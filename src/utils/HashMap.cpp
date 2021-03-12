/*
 * HashMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Array.h>
#include <tl/lang/IntArray.h>
#include <tl/utils/HashMap.h>

namespace tl {
namespace utils {

using lang::Array;
using lang::IntArray;
using lang::Reference;

HashMap::HashMap(type_t keyType, type_t valueType)
	: Map(keyType, valueType) {
	// TODO Auto-generated constructor stub

	mTables = Reference(new Array(Array::type(), TABLE_COUNT));
	Array *tables = dynamic_cast<Array*>(mTables.getEntity());
	for (tlint index = 0; index < TABLE_COUNT; index++) {
		tables->set(index,
			Reference(new Array(HashEntry::type(), INIT_CAPACITY[index])));
		mCurrentCapacity[index] = INIT_CAPACITY[index];
	}

	mNextExchange = 0;
	mCurrentTotalCapacity = DEFAULT_TOTAL_CAPACITY;
	mLoadFactor = DEFAULT_LOAD_FACTOR;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference HashMap::computeIndices(Reference keyRef) {
	if (keyRef.isNull()) {
		//cast an exception
	}

	argumentTypeCheck(keyRef, mKeyType);

	hash_t keyHashcode = keyRef.getEntity()->hashCode();
	tlint indices[] =
		{ (tlint)(keyHashcode % mCurrentCapacity[0]), (tlint)(keyHashcode
				% mCurrentCapacity[1]),
			(tlint)(keyHashcode % mCurrentCapacity[2]), (tlint)(keyHashcode
				% mCurrentCapacity[3]),
			(tlint)(keyHashcode % mCurrentCapacity[4]) };

	return IntArray::newInstance(TABLE_COUNT, indices);
}

Reference HashMap::findEntry(Reference keyRef) {
	Reference indicesArr = computeIndices(keyRef);
	IntArray *indices = dynamic_cast<IntArray*>(indicesArr.getEntity());

	Array *tables = dynamic_cast<Array*>(mTables.getEntity());
	for (tlint i = 0; i < TABLE_COUNT; i++) {
		Reference tableRef = tables->get(i);
		Array *table = dynamic_cast<Array*>(tableRef.getEntity());
		Reference entryRef = table->get(indices->get(i));
		HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
		if (entry->key().equals(keyRef)) {
			return entryRef;
		}
	}

	return Reference();
}

Reference HashMap::remove(Reference keyRef) {
	Reference entryRef = findEntry(keyRef);
	if (entryRef.isNull()) {
		return Reference();
	}

	HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
	if (entry->valid()) {
		entry->invalidate();
		mSize--;
		return entry->value();
	} else {
		return Reference();
	}
}

bool HashMap::containsKey(Reference keyRef) {
	Reference entryRef = findEntry(keyRef);
	return !entryRef.isNull();
}

bool HashMap::containsValue(Reference valueRef) {
	for (tlint i = 0; i < TABLE_COUNT; i++) {
		if (searchTableForValue(i, valueRef)) {
			return true;
		}
	}

	return false;
}

bool HashMap::containsEntry(Reference entryRef) {
	if (entryRef.isNull()) {
		return false;
	}

	argumentTypeCheck(entryRef, Map::Entry::type());
	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	Reference requestedEntryRef = findEntry(entry->key());
	if (requestedEntryRef.isNull()) {
		return false;
	}

	Map::Entry *requestedEntry =
		dynamic_cast<Map::Entry*>(requestedEntryRef.getEntity());
	return (requestedEntry->value().equals(entry->value()));
}

bool HashMap::searchTableForValue(tlint index, Reference valueRef) {
	Array *tables = dynamic_cast<Array*>(mTables.getEntity());
	Reference tableRef = tables->get(index);
	Array *table = dynamic_cast<Array*>(tableRef.getEntity());

	for (tlint i = 0; i < table->size(); i++) {
		if (!table->get(i).isNull()) {
			Reference ref = table->get(i);
			HashEntry *entry = dynamic_cast<HashEntry*>(ref.getEntity());
			if (entry->value().equals(valueRef) && entry->valid()) {
				return true;
			}
		}
	}

	return false;
}

Reference HashMap::remove(Reference keyRef, Reference valueRef) {
	Reference entryRef = findEntry(keyRef);
	if (entryRef.isNull()) {
		return Reference();
	}

	HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
	if (entry->value().equals(valueRef) && entry->valid()) {
		entry->invalidate();
		mSize--;
		return entry->value();
	} else {
		return Reference();
	}
}

HashMap::~HashMap() {
	// TODO Auto-generated destructor stub
}

Reference HashMap::put(Reference keyRef, Reference valueRef) {
	if (mSize >= mCurrentTotalCapacity * mLoadFactor) {
		rehash();
	}

	Reference entryRef = findEntry(keyRef);
	if (entryRef.isNull()) {
		put0(keyRef, valueRef);
		return Reference();
	}

	HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
	Reference oldValue = entry->value();
	entry->setValue(valueRef);
	if (entry->valid()) {
		return oldValue;
	} else {
		entry->validate();
		mSize++;
		return Reference();
	}
}

void HashMap::put0(Reference keyRef, Reference valueRef) {
	Array *tables = dynamic_cast<Array*>(mTables.getEntity());
	tlint transfers = 0;
	tlint rehashes = 0;

	while (true) {
		Reference indicesArr = computeIndices(keyRef);
		IntArray *indices = dynamic_cast<IntArray*>(indicesArr.getEntity());

		for (tlint i = 0; i < TABLE_COUNT; i++) {
			Reference tableRef = tables->get(i);
			Array *table = dynamic_cast<Array*>(tableRef.getEntity());
			if (table->get(indices->get(i)).isNull()) {
				table->set(indices->get(i),
					Reference(new HashEntry(keyRef, valueRef)));
				mSize++;
				return;
			}

			Reference entryRef = table->get(indices->get(i));
			HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
			if (!entry->valid()) {
				table->set(indices->get(i),
					Reference(new HashEntry(keyRef, valueRef)));
				mSize++;
				return;
			}
		}

		Reference tableRef = tables->get(mNextExchange);
		Array *table = dynamic_cast<Array*>(tableRef.getEntity());

		Reference poppedEntryRef = table->get(indices->get(mNextExchange));
		HashEntry *poppedEntry =
			dynamic_cast<HashEntry*>(poppedEntryRef.getEntity());
		table->set(indices->get(mNextExchange),
			Reference(new HashEntry(keyRef, valueRef)));
		keyRef = poppedEntry->key();
		valueRef = poppedEntry->value();
		mNextExchange = (mNextExchange + 1) % TABLE_COUNT;

		if (++transfers > MAX_TRANSFER) {
			rehash();
			rehashes++;
			transfers = 0;
		}

	}

}

void HashMap::capacityCheck() {
	if (mCurrentCapacity[4] >= MAX_CAPACITY) {
		//cast an exception
	}
}

void HashMap::clear() {
	Reference newTablesRef = Reference(new Array(Array::type(), TABLE_COUNT));
	Array *newTables = dynamic_cast<Array*>(newTablesRef.getEntity());

	for (tlint i = 0; i < TABLE_COUNT; i++) {
		newTables->set(i,
			Reference(new Array(HashEntry::type(), INIT_CAPACITY[i])));
		mCurrentCapacity[i] = INIT_CAPACITY[i];
	}

	mCurrentTotalCapacity = DEFAULT_TOTAL_CAPACITY;
	mTables = newTablesRef;
}

void HashMap::rehash() {
	capacityCheck();

	tlint newCapacity[] =
		{ mCurrentCapacity[1], mCurrentCapacity[2], mCurrentCapacity[3],
			mCurrentCapacity[4], mCurrentCapacity[3] + mCurrentCapacity[4] };
	tlint newTotalCapacity = 0;

	Reference newTablesRef = Reference(new Array(Array::type(), TABLE_COUNT));
	Array *newTables = dynamic_cast<Array*>(newTablesRef.getEntity());
	for (tlint i = 0; i < TABLE_COUNT; i++) {
		newTables->set(i,
			Reference(new Array(HashEntry::type(), newCapacity[i])));
		newTotalCapacity += newCapacity[i];
	}

	Reference oldTablesRef = mTables;
	mTables = newTablesRef;
	Array *oldTables = dynamic_cast<Array*>(oldTablesRef.getEntity());

	for (tlint i = 0; i < TABLE_COUNT; i++) {
		Reference tableRef = oldTables->get(i);
		Array *table = dynamic_cast<Array*>(tableRef.getEntity());

		for (tlint k = 0; k < table->size(); k++) {
			Reference entryRef = table->get(k);
			if (entryRef.isNull()) {
				continue;
			}

			HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
			if (!entry->valid()) {
				continue;
			}

			put(entry->key(), entry->value());
		}
	}
}

Reference HashMap::putIfAbsent(Reference keyRef, Reference valueRef) {
	Reference entryRef = findEntry(keyRef);
	if (entryRef.isNull()) {
		put0(keyRef, valueRef);
		return Reference();
	}

	HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
	if (entry->valid()) {
		return entry->value();
	} else {
		put0(keyRef, valueRef);
		return Reference();
	}
}

Reference HashMap::get(Reference keyRef) {
	Reference entryRef = findEntry(keyRef);
	if (entryRef.isNull()) {
		return Reference();
	}

	HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
	if (entry->valid()) {
		return entry->value();
	}

	return Reference();
}

Reference HashMap::entrySet() {
	return Reference(new EntrySetView(Reference(this, false)));
}

Reference HashMap::keySet() {
	return Reference(new KeySetView(mKeyType, Reference(this, false)));
}

Reference HashMap::values() {
	return Reference(new Values(mValueType, Reference(this, false)));
}

bool HashMap::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Map::instanceof(type);
}

type_t HashMap::type() {
	return CLASS_SERIAL;
}

HashMap::HashEntry::HashEntry(Reference key, Reference value)
	: Entry(key, value) {
	mValid = true;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool HashMap::HashEntry::valid() {
	return mValid;
}

void HashMap::HashEntry::invalidate() {
	mValid = false;
}

void HashMap::HashEntry::validate() {
	mValid = true;
}

type_t HashMap::HashEntry::type() {
	return CLASS_SERIAL;
}

bool HashMap::HashEntry::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Entry::instanceof(type);
}

HashMap::PrivateEntryIterator::PrivateEntryIterator(Reference map) {
	mMap = map;

	mLastReturned = Reference();
	mTableNumber = 0;
	mEntryIndex = 0;

	mCurrentEntry = nextEntry0();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference HashMap::PrivateEntryIterator::nextEntry0() {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());

	if (mTableNumber == -1 || mEntryIndex == -1) {
		return Reference();
	}

	Array *tables = dynamic_cast<Array*>(map->mTables.getEntity());
	for (tlint t = mTableNumber; t < HashMap::TABLE_COUNT; t++) {
		Reference tableRef = tables->get(t);
		Array *table = dynamic_cast<Array*>(tableRef.getEntity());

		for (tlint i = mEntryIndex + 1; i < table->size(); i++) {
			Reference entryRef = table->get(i);
			if (entryRef.isNull()) {
				continue;
			}

			HashEntry *entry = dynamic_cast<HashEntry*>(entryRef.getEntity());
			if (entry->valid()) {
				mTableNumber = t;
				mEntryIndex = i;
				return entryRef;
			}
		}
	}

	mTableNumber = -1;
	mEntryIndex = -1;
	return Reference();
}

Reference HashMap::PrivateEntryIterator::nextEntry() {
	checkValidation();

	if (mCurrentEntry.isNull()) {
		//cast an exception
	}

	mLastReturned = mCurrentEntry;
	mCurrentEntry = nextEntry0();

	return mLastReturned;
}

bool HashMap::PrivateEntryIterator::hasNext() {
	checkValidation();

	return !mCurrentEntry.isNull();
}

void HashMap::PrivateEntryIterator::remove() {
	checkValidation();

	if (mLastReturned.isNull()) {
		//cast an exception
	}

	Map::Entry *entry = dynamic_cast<Map::Entry*>(mLastReturned.getEntity());
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	map->remove(entry->key());

	mLastReturned = Reference();
}

type_t HashMap::PrivateEntryIterator::type() {
	return CLASS_SERIAL;
}

bool HashMap::PrivateEntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterator::instanceof(type);
}

HashMap::EntrySetView::EntrySetView(Reference ref)
	: Collection(Map::Entry::type()), Set(Map::Entry::type()) {
	mMap = ref;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool HashMap::EntrySetView::add(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());

	invalidateIterators();

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	return map->put(entry->key(), entry->value()).isNull();
}

bool HashMap::EntrySetView::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference entry = iterator->next();
		result = result || add(entry);
	}

	if (result) {
		invalidateIterators();
	}

	return result;
}

bool HashMap::EntrySetView::contains(Reference ref) {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	return map->containsEntry(ref);
}

bool HashMap::EntrySetView::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result && contains(element);
		if (!result) {
			return result;
		}
	}

	return result;
}

Reference HashMap::EntrySetView::iterator() {
	mIterator = Reference(new EntryIterator(mMap));
	return mIterator;
}

void HashMap::EntrySetView::invalidateIterators() {
	if (mIterator.isNull()) {
		return;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
}

bool HashMap::EntrySetView::remove(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());

	invalidateIterators();

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());

	return !map->remove(entry->key(), entry->value()).isNull();
}

bool HashMap::EntrySetView::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result || remove(element);
	}

	return result;
}

void HashMap::EntrySetView::clear() {
	invalidateIterators();

	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	map->clear();
}

Reference HashMap::EntrySetView::toArray() {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(Map::Entry::type(), map->size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		arr->set(index, e);
		index++;
	}

	return rtval;
}

type_t HashMap::EntrySetView::type() {
	return CLASS_SERIAL;
}

bool HashMap::EntrySetView::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Set::instanceof(type);
}

HashMap::EntryIterator::EntryIterator(Reference map)
	: PrivateEntryIterator(map) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference HashMap::EntryIterator::next() {
	checkValidation();

	return PrivateEntryIterator::nextEntry();
}

type_t HashMap::EntryIterator::type() {
	return CLASS_SERIAL;
}

bool HashMap::EntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

HashMap::KeySetView::KeySetView(type_t keyType, Reference map)
	: Collection(keyType), Set(keyType) {
	mMap = map;
	mHashCode = genHashCode(CLASS_SERIAL);
}

bool HashMap::KeySetView::add(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	Map *map = dynamic_cast<Map*>(mMap.getEntity());
	return map->put(ref, Reference()).isNull();
}

bool HashMap::KeySetView::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	invalidateIterators();

	Collection *c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		result = result || add(e);
	}

	return result;
}

bool HashMap::KeySetView::contains(Reference ref) {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	return map->containsKey(ref);
}

bool HashMap::KeySetView::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		result = result && map->containsKey(e);
		if (!result) {
			return result;
		}
	}

	return result;
}

Reference HashMap::KeySetView::iterator() {
	mIterator = Reference(new KeyIterator(mMap));
	return mIterator;
}

void HashMap::KeySetView::invalidateIterators() {
	if (mIterator.isNull()) {
		return;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
}

bool HashMap::KeySetView::remove(Reference ref) {
	invalidateIterators();

	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	return !map->remove(ref).isNull();
}

bool HashMap::KeySetView::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	invalidateIterators();

	Collection *c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result || remove(element);
	}

	return result;
}

void HashMap::KeySetView::clear() {
	invalidateIterators();

	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	map->clear();
}

Reference HashMap::KeySetView::toArray() {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(map->keyType(), map->size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		arr->set(index, e);
		index++;
	}

	return rtval;
}

type_t HashMap::KeySetView::type() {
	return CLASS_SERIAL;
}

bool HashMap::KeySetView::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Set::instanceof(type);
}

HashMap::KeyIterator::KeyIterator(Reference map)
	: PrivateEntryIterator(map) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference HashMap::KeyIterator::next() {
	Reference entryRef = PrivateEntryIterator::nextEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());

	return entry->key();
}

type_t HashMap::KeyIterator::type() {
	return CLASS_SERIAL;
}

bool HashMap::KeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

HashMap::Values::Values(type_t valueType, Reference map)
	: Collection(valueType) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool HashMap::Values::add(Reference ref) {
	//cast an exception
	return false;
}

bool HashMap::Values::addAll(Reference ref) {
	//cast an exception
	return false;
}

bool HashMap::Values::contains(Reference ref) {
	Map *map = dynamic_cast<Map*>(mMap.getEntity());
	return map->containsValue(ref);
}

bool HashMap::Values::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference v = iterator->next();
		result = result && map->containsValue(v);
		if (!result) {
			return result;
		}
	}

	return result;
}

bool HashMap::Values::remove(Reference ref) {
	//cast an exception
	return false;
}

bool HashMap::Values::removeAll(Reference ref) {
	//cast an exception
	return false;
}

void HashMap::Values::clear() {
	invalidateIterators();

	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	map->clear();
}

Reference HashMap::Values::iterator() {
	mIterator = Reference(new ValueIterator(mMap));
	return mIterator;
}

void HashMap::Values::invalidateIterators() {
	if (mIterator.isNull()) {
		return;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
}

Reference HashMap::Values::toArray() {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(map->valueType(), map->size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference v = iterator->next();
		arr->set(index, v);
		index++;
	}

	return rtval;
}

type_t HashMap::Values::type() {
	return CLASS_SERIAL;
}

bool HashMap::Values::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

HashMap::ValueIterator::ValueIterator(Reference map)
	: PrivateEntryIterator(map) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference HashMap::ValueIterator::next() {
	Reference ref = nextEntry();
	HashEntry *entry = dynamic_cast<HashEntry*>(ref.getEntity());
	return entry->value();
}

type_t HashMap::ValueIterator::type() {
	return CLASS_SERIAL;
}

bool HashMap::ValueIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
