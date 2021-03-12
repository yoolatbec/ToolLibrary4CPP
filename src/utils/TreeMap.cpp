/*
 * TreeMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Array.h>
#include <tl/lang/Integer.h>
#include <tl/lang/String.h>
#include <tl/lang/UnsupportedOperationException.h>
#include <tl/utils/NoSuchElementException.h>
#include <tl/utils/TreeMap.h>

namespace tl {
namespace utils {

using lang::String;
using lang::Array;
using lang::UnsupportedOperationException;

TreeMap::TreeMap(type_t keyType, type_t valueType)
	: NavigableMap(keyType, valueType) {
	// TODO Auto-generated constructor stub
	mRootEntry = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
	clear0(mRootEntry);
	mRootEntry = Reference();
}

hash_t TreeMap::TreeEntry::genHashCode(type_t type) {
	hash_t keyHash = dynamic_cast<Object*>(mKey.getEntity())->hashCode();
	hash_t valueHash =
		mValue.isNull() ?
			0 : dynamic_cast<Object*>(mValue.getEntity())->hashCode();
	return (((keyHash ^ valueHash) << 32) >> 32) | (type << 32);
}

TreeMap::TreeEntry::TreeEntry(Reference key, Reference value, Reference parent)
	: Entry(key, value), mParent(parent) {
	mHeight = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
	mWeight = dynamic_cast<Object*>(mKey.getEntity())->hashCode();
}

bool TreeMap::containsKey0(Reference ref, Reference key) {
	return !getEntry0(ref, key).isNull();
}

bool TreeMap::containsValue0(Reference ref, Reference value) {
	if (ref.isNull()) {
		return false;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->value().equals(value)) {
		return true;
	}

	return containsValue0(entry->getLeft(), value)
		|| containsValue0(entry->getRight(), value);
}

Reference TreeMap::getEntry0(Reference ref, Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	while (!ref.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
		if (entry->getWeight()
			== dynamic_cast<Object*>(key.getEntity())->hashCode()) {
			break;
		}
		if (entry->getWeight()
			< dynamic_cast<Object*>(key.getEntity())->hashCode()) {
			ref = entry->getRight();
		} else {
			ref = entry->getLeft();
		}
	}

	if (ref.isNull()) {
		return Reference();
	} else {
		return ref;
	}
}

tlint TreeMap::height0(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	return entry->getHeight();
}

Reference TreeMap::rightRotate0(Reference ref) {
	TreeEntry *root = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference parent = root->getParent();
	Reference leftRef = root->getLeft();
	TreeEntry *left = dynamic_cast<TreeEntry*>(leftRef.getEntity());
	Reference rightRef = left->getRight();

	root->setLeft(rightRef);
	if (!rightRef.isNull()) {
		TreeEntry *right = dynamic_cast<TreeEntry*>(rightRef.getEntity());
		right->setParent(ref);
	}

	left->setRight(ref);
	root->setParent(leftRef);

	left->setParent(parent);

	root->setHeight(
		lang::Integer::larger(TreeMap::height0(root->getLeft()),
			TreeMap::height0(root->getRight())) + 1);
	left->setHeight(
		lang::Integer::larger(TreeMap::height0(left->getLeft()),
			TreeMap::height0(left->getRight())) + 1);

	return leftRef;
}

Reference TreeMap::leftRotate0(Reference ref) {
	TreeEntry *root = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference parent = root->getParent();
	Reference rightRef = root->getRight();
	TreeEntry *right = dynamic_cast<TreeEntry*>(rightRef.getEntity());
	Reference leftRef = right->getLeft();

	root->setRight(leftRef);
	if (!leftRef.isNull()) {
		TreeEntry *left = dynamic_cast<TreeEntry*>(leftRef.getEntity());
		left->setParent(ref);
	}

	right->setLeft(ref);
	root->setParent(rightRef);

	right->setParent(parent);

	root->setHeight(
		lang::Integer::larger(TreeMap::height0(root->getLeft()),
			TreeMap::height0(root->getRight())) + 1);
	right->setHeight(
		lang::Integer::larger(TreeMap::height0(right->getLeft()),
			TreeMap::height0(right->getRight())) + 1);

	return rightRef;
}

Reference TreeMap::rightLeftRotate0(Reference ref) {
	TreeEntry *parentEntry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference right = parentEntry->getRight();

	parentEntry->setRight(TreeMap::rightRotate0(right));
	return TreeMap::leftRotate0(ref);
}

Reference TreeMap::leftRightRotate0(Reference ref) {
	TreeEntry *parentEntry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference left = parentEntry->getLeft();

	parentEntry->setLeft(TreeMap::leftRotate0(left));
	return TreeMap::rightRotate0(ref);
}

Reference TreeMap::balance0(Reference ref) {
	if (ref.isNull()) {
		return ref;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference left = entry->getLeft();
	Reference right = entry->getRight();
	TreeEntry *leftEntry = dynamic_cast<TreeEntry*>(left.getEntity());
	TreeEntry *rightEntry = dynamic_cast<TreeEntry*>(right.getEntity());

	if (TreeMap::height0(left) - TreeMap::height0(right)
		> TreeEntry::ALLOWED_IMBALANCE) {
		if (TreeMap::height0(leftEntry->getLeft())
			>= TreeMap::height0(leftEntry->getRight())) {
			ref = TreeMap::rightRotate0(ref);
		} else {
			ref = TreeMap::leftRightRotate0(ref);
		}
	} else if (TreeMap::height0(right) - TreeMap::height0(left)
		> TreeEntry::ALLOWED_IMBALANCE) {
		if (TreeMap::height0(rightEntry->getRight())
			>= TreeMap::height0(rightEntry->getLeft())) {
			ref = TreeMap::leftRotate0(ref);
		} else {
			ref = TreeMap::rightLeftRotate0(ref);
		}
	}

	entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	left = entry->getLeft();
	right = entry->getRight();

	entry->setHeight(lang::Integer::larger(TreeMap::height0(left),
		TreeMap::height0(right)) + 1);
	return ref;
}

Reference TreeMap::add0(Reference ref, Reference keyRef, Reference valueRef,
	Reference parent) {
	if (ref.isNull()) {
		return Reference(new TreeEntry(keyRef, valueRef, parent));
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference key = entry->value();
	if (key.equals(keyRef)) {
		entry->setValue(valueRef);
	} else if (dynamic_cast<Object*>(keyRef.getEntity())->hashCode()
		> entry->getWeight()) {
		entry->getRight() = TreeMap::add0(entry->getRight(), keyRef, valueRef,
			ref);
	} else {
		entry->getLeft() = TreeMap::add0(entry->getLeft(), keyRef, valueRef,
			ref);
	}

	return TreeMap::balance0(ref);
}

Reference TreeMap::remove0(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->key().equals(keyRef)) {
		Reference parent = entry->getParent();
		if (!entry->getLeft().isNull() && !entry->getRight().isNull()) {
			TreeEntry *minEntry = dynamic_cast<TreeEntry*>(TreeMap::minEntry0(
				entry->getRight()).getEntity());
			Reference newEntryRef = Reference(
				new TreeEntry(minEntry->key(), minEntry->value()));
			TreeEntry *newEntry =
				dynamic_cast<TreeEntry*>(newEntryRef.getEntity());
			newEntry->setParent(entry->getParent());
			newEntry->setLeft(entry->getLeft());
			Reference leftEntryRef = entry->getLeft();
			Reference rightEntryRef = entry->getRight();
			TreeEntry *leftEntry =
				dynamic_cast<TreeEntry*>(leftEntryRef.getEntity());
			TreeEntry *rightEntry =
				dynamic_cast<TreeEntry*>(rightEntryRef.getEntity());
			leftEntry->setParent(newEntryRef);
			rightEntry->setParent(newEntryRef);
			newEntry->setRight(
				TreeMap::remove0(entry->getRight(), entry->key()));
		} else {
			ref =
				entry->getLeft().isNull() ?
					entry->getRight() : entry->getLeft();
			if (!ref.isNull()) {
				entry = dynamic_cast<TreeEntry*>(ref.getEntity());
				entry->setParent(parent);
			}
		}
	} else if (entry->getWeight()
		< dynamic_cast<Object*>(keyRef.getEntity())->hashCode()) {
		entry->getRight() = TreeMap::remove0(entry->getRight(), keyRef);
	} else {
		entry->getLeft() = TreeMap::remove0(entry->getLeft(), keyRef);
	}

	return TreeMap::balance0(ref);
}

Reference TreeMap::getValue0(Reference root, Reference keyRef) {
	Reference entryRef = TreeMap::getEntry0(root, keyRef);
	if (!entryRef.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
		return entry->value();
	} else {
		return Reference();
	}
}

void TreeMap::clear0(Reference ref) {
	if (ref.isNull()) {
		return;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	TreeMap::clear0(entry->getLeft());
	TreeMap::clear0(entry->getRight());

	entry->getLeft() = Reference();
	entry->getRight() = Reference();
}

Reference TreeMap::minEntry0(Reference ref) {
	if (ref.isNull()) {
		return Reference();
	}

	Reference current = ref;
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	while (!entry->getLeft().isNull()) {
		current = entry->getLeft();
		entry = dynamic_cast<TreeEntry*>(current.getEntity());
	}

	return current;
}

Reference TreeMap::maxEntry0(Reference ref) {
	if (ref.isNull()) {
		return Reference();
	}

	Reference current = ref;
	TreeEntry *entry = dynamic_cast<TreeEntry*>(current.getEntity());
	while (!entry->getRight().isNull()) {
		current = entry->getRight();
		entry = dynamic_cast<TreeEntry*>(current.getEntity());
	}

	return current;
}

Reference TreeMap::floorEntry0(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->getWeight()
		== dynamic_cast<Object*>(keyRef.getEntity())->hashCode()) {
		return ref;
	} else if (entry->getWeight()
		> dynamic_cast<Object*>(keyRef.getEntity())->hashCode()) {
		if (entry->getLeft().isNull()) {
			return Reference();
		} else {
			return floorEntry0(entry->getLeft(), keyRef);
		}
	} else {
		if (entry->getRight().isNull()) {
			return ref;
		} else {
			return TreeMap::floorEntry0(entry->getRight(), keyRef);
		}
	}

}

Reference TreeMap::ceilingEntry0(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->getWeight()
		== dynamic_cast<Object*>(keyRef.getEntity())->hashCode()) {
		return ref;
	} else if (entry->getWeight()
		< dynamic_cast<Object*>(keyRef.getEntity())->hashCode()) {
		if (entry->getRight().isNull()) {
			return Reference();
		} else {
			return TreeMap::ceilingEntry0(entry->getRight(), keyRef);
		}
	} else {
		if (entry->getLeft().isNull()) {
			return ref;
		} else {
			return TreeMap::ceilingEntry0(entry->getLeft(), keyRef);
		}
	}
}

Reference TreeMap::TreeEntry::getLeft() {
	return mLeft;
}

Reference TreeMap::TreeEntry::getRight() {
	return mRight;
}

Reference TreeMap::TreeEntry::getParent() {
	return mParent;
}

void TreeMap::TreeEntry::setLeft(Reference ref) {
	mLeft = ref;
}

void TreeMap::TreeEntry::setRight(Reference ref) {
	mRight = ref;
}

void TreeMap::TreeEntry::setParent(Reference ref) {
	mParent = ref;
}

tlint TreeMap::TreeEntry::getHeight() {
	return mHeight;
}

void TreeMap::TreeEntry::setHeight(tlint height) {
	mHeight = height;
}

hash_t TreeMap::TreeEntry::getWeight() {
	return mWeight;
}

Reference TreeMap::TreeEntry::toString() {
	Reference keyStr = mKey.getEntity()->toString();
	Reference valueStr =
		mValue.isNull() ?
			Reference(new String("null")) : mValue.getEntity()->toString();

	String *keyString = dynamic_cast<String*>(keyStr.getEntity());
	Reference tmp = keyString->append('=');
	String *tmpString = dynamic_cast<String*>(tmp.getEntity());
	return tmpString->append(valueStr);
}

Reference TreeMap::successor0(Reference root, Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	Reference entryRef = TreeMap::getEntry0(root, key);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	if (!entry->getRight().isNull()) {
		Reference s = entry->getRight();
		TreeEntry *e = dynamic_cast<TreeEntry*>(s.getEntity());
		while (!e->getLeft().isNull()) {
			s = e->getLeft();
			e = dynamic_cast<TreeEntry*>(s.getEntity());
		}

		return s;
	} else {
		Reference p = entry->getParent();
		Reference ch = entryRef;
		while (!p.isNull()) {
			TreeEntry *parent = dynamic_cast<TreeEntry*>(p.getEntity());
			if (!parent->getRight().equals(ch)) {
				break;
			}
			ch = p;
			p = parent->getParent();
		}

		return p;
	}
}

Reference TreeMap::predecessor0(Reference root, Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	Reference entryRef = TreeMap::getEntry0(root, key);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	if (!entry->getLeft().isNull()) {
		Reference p = entry->getLeft();
		TreeEntry *e = dynamic_cast<TreeEntry*>(p.getEntity());
		while (!e->getRight().isNull()) {
			p = e->getRight();
			e = dynamic_cast<TreeEntry*>(p.getEntity());
		}

		return p;
	} else {
		Reference p = entry->getParent();
		Reference ch = entryRef;
		while (!p.isNull()) {
			TreeEntry *parent = dynamic_cast<TreeEntry*>(p.getEntity());
			if (!parent->getLeft().equals(ch)) {
				break;
			}
			ch = p;
			p = parent->getParent();
		}

		return p;
	}
}

type_t TreeMap::TreeEntry::type() {
	return CLASS_SERIAL;
}

bool TreeMap::TreeEntry::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Map::Entry::instanceof(type);
}

Reference TreeMap::get(Reference key) {
	dismissNull(key);

	argumentTypeCheck(key, mKeyType);

	return TreeMap::getValue0(mRootEntry, key);
}

Reference TreeMap::put(Reference key, Reference value) {
	dismissNull(key);

	argumentTypeCheck(key, mKeyType);
	if (!value.isNull()) {
		argumentTypeCheck(value, mValueType);
	}

	return put0(key, value);
}

Reference TreeMap::put0(Reference key, Reference value) {
	Reference oldValue = TreeMap::getValue0(mRootEntry, key);
	mRootEntry = add0(mRootEntry, key, value, Reference());

	if (!oldValue.isNull()) {
		return oldValue;
	} else {
		mSize++;
		return Reference();
	}
}

Reference TreeMap::remove(Reference key) {
	dismissNull(key);

	argumentTypeCheck(key, mKeyType);

	Reference oldValue = getValue0(mRootEntry, key);
	if (oldValue.isNull()) {
		return Reference();
	} else {
		mSize--;
		mRootEntry = remove0(mRootEntry, key);
		return oldValue;
	}
}

Reference TreeMap::firstKey() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference minEntryRef = minEntry0(mRootEntry);
	if (minEntryRef.isNull()) {
		return Reference();
	}

	Entry *minEntry = dynamic_cast<Entry*>(minEntryRef.getEntity());
	return minEntry->key();
}

Reference TreeMap::firstEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	return minEntry0(mRootEntry);
}

Reference TreeMap::lastEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	return maxEntry0(mRootEntry);
}

Reference TreeMap::lastKey() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference maxEntryRef = maxEntry0(mRootEntry);
	Entry *entry = dynamic_cast<Entry*>(maxEntryRef.getEntity());
	return entry->key();
}

Reference TreeMap::floorKey(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference floorEntryRef = floorEntry0(mRootEntry, keyRef);
	if (floorEntryRef.isNull()) {
		return Reference();
	}

	Entry *floorEntry = dynamic_cast<Entry*>(floorEntryRef.getEntity());
	return floorEntry->key();
}

Reference TreeMap::floorEntry(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	return floorEntry0(mRootEntry, keyRef);
}

Reference TreeMap::ceilingEntry(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	return ceilingEntry0(mRootEntry, keyRef);
}

Reference TreeMap::ceilingKey(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference ceilingEntryRef = ceilingEntry0(mRootEntry, keyRef);
	if (ceilingEntryRef.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ceilingEntryRef.getEntity());
	return entry->key();
}

Reference TreeMap::lowerEntry(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (containsKey0(mRootEntry, keyRef)) {
		return predecessor0(mRootEntry, keyRef);
	} else {
		return floorEntry0(mRootEntry, keyRef);
	}
}

Reference TreeMap::lowerKey(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (containsKey0(mRootEntry, keyRef)) {
		Reference entryRef = predecessor0(mRootEntry, keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	} else {
		Reference entryRef = floorEntry(keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	}
}

Reference TreeMap::higherEntry(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (containsKey0(mRootEntry, keyRef)) {
		return successor0(mRootEntry, keyRef);
	} else {
		return ceilingEntry0(mRootEntry, keyRef);
	}
}

Reference TreeMap::higherKey(Reference keyRef) {
	dismissNull(keyRef);

	argumentTypeCheck(keyRef, mKeyType);

	if (containsKey0(mRootEntry, keyRef)) {
		Reference entryRef = successor0(mRootEntry, keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	} else {
		Reference entryRef = ceilingEntry0(mRootEntry, keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	}

}

Reference TreeMap::pollFirstEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference firstEntryRef = minEntry0(mRootEntry);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(firstEntryRef.getEntity());
	remove0(mRootEntry, entry->key());
	mSize--;

	return firstEntryRef;
}

Reference TreeMap::pollLastEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference lastEntryRef = maxEntry0(mRootEntry);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(lastEntryRef.getEntity());
	remove0(mRootEntry, entry->key());
	mSize--;

	return lastEntryRef;
}

Reference TreeMap::putIfAbsent(Reference key, Reference value) {
	dismissNull(key);

	argumentTypeCheck(key, mKeyType);
	if (!value.isNull()) {
		argumentTypeCheck(value, mValueType);
	}

	Reference oldValue = getValue0(mRootEntry, key);
	if (oldValue.isNull()) {
		mRootEntry = add0(oldValue, key, value, Reference());
		mSize++;
		return value;
	} else {
		return oldValue;
	}
}

void TreeMap::putAll(Reference ref) {
	if (ref.isNull()) {
		return;
	}

	argumentTypeCheck(ref, Map::type());

	Map *map = dynamic_cast<Map*>(ref.getEntity());
	Reference entrySet = map->entrySet();
	Set *entries = dynamic_cast<Set*>(entrySet.getEntity());
	Reference iteratorRef = entries->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	while (iterator->hasNext()) {
		Reference element = iterator->next();
		Map::Entry *entry = dynamic_cast<Map::Entry*>(element.getEntity());
		put(entry->key(), entry->value());
	}
}

bool TreeMap::containsKey(Reference key) {
	dismissNull(key);

	argumentTypeCheck(key, mKeyType);

	return containsKey0(mRootEntry, key);
}

bool TreeMap::containsEntry(Reference entryRef) {
	if (entryRef.isNull()) {
		return false;
	}

	argumentTypeCheck(entryRef, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	Reference requestedEntryRef = getEntry0(mRootEntry, entry->key());
	if (requestedEntryRef.isNull()) {
		return false;
	}

	Map::Entry *requestedEntry =
		dynamic_cast<Map::Entry*>(requestedEntryRef.getEntity());
	return (requestedEntry->value().equals(entry->value()));
}

bool TreeMap::containsValue(Reference value) {
	if (value.isNull()) {
		return false;
	}

	argumentTypeCheck(value, mValueType);

	return containsValue0(mRootEntry, value);
}

void TreeMap::clear() {
	clear0(mRootEntry);
	mRootEntry = Reference();
	mSize = 0;
}

Reference TreeMap::keySet() {
//	return mKeySet;
	return Reference(new KeySet(mKeyType, Reference(this, false)));
}

Reference TreeMap::values() {
//	return mValues;
	return Reference(new Values(mValueType, Reference(this, false)));
}

Reference TreeMap::entrySet() {
	return Reference(new EntrySetView(Reference(this, false)));
}

type_t TreeMap::type() {
	return CLASS_SERIAL;
}

bool TreeMap::instanceof(type_t type) {
	return CLASS_SERIAL == type || Map::instanceof(type);
}

TreeMap::Values::Values(type_t type, Reference map)
	: Collection(type) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void TreeMap::Values::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

bool TreeMap::Values::contains(Reference value) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsValue(value);

}

bool TreeMap::Values::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	bool result = true;
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result && map->containsValue(element);
		if (!result) {
			break;
		}
	}

	return result;
}

bool TreeMap::Values::add(Reference ref) {
	//cast NotSupportedOperationException
	throw UnsupportedOperationException();
}

bool TreeMap::Values::addAll(Reference ref) {
	//cast NotSupportedOperationException
	throw UnsupportedOperationException();
}

Reference TreeMap::Values::toArray() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(map->mValueType, size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());
	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	tlint index = 0;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		arr->set(index, element);
		index++;
	}

	return rtval;
}

type_t TreeMap::Values::type() {
	return CLASS_SERIAL;
}

bool TreeMap::Values::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

tlint TreeMap::Values::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

bool TreeMap::Values::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size() == 0;
}
bool TreeMap::Values::remove(Reference ref) {
	throw UnsupportedOperationException();
}

bool TreeMap::Values::removeAll(Reference ref) {
	throw UnsupportedOperationException();
}

Reference TreeMap::Values::iterator() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return Reference(new ValueIterator(map->firstEntry()));
}

TreeMap::EntrySetView::EntrySetView(Reference map)
	: Collection(Map::Entry::type()), Set(Map::Entry::type()) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::EntrySetView::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference resultRef = map->getEntry0(map->mRootEntry, ref);
	if (resultRef.isNull()) {
		return false;
	}

	Map::Entry *result = dynamic_cast<Map::Entry*>(resultRef.getEntity());
	if (!result->key().equals(entry->key())
		|| !result->value().equals(entry->value())) {
		return false;
	}

	return true;
}

bool TreeMap::EntrySetView::containsAll(Reference ref) {
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
		result = result && TreeMap::EntrySetView::contains(element);
		if (!result) {
			return result;
		}
	}

	return result;
}

void TreeMap::EntrySetView::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

bool TreeMap::EntrySetView::add(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->put(entry->key(), entry->value()).isNull();
}

bool TreeMap::EntrySetView::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result || add(element);
	}

	return result;
}

bool TreeMap::EntrySetView::remove(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference entryRef = map->getEntry0(map->mRootEntry, entry->key());
	if (entryRef.isNull()) {
		return false;
	}

	TreeEntry *requiredEntry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	if (requiredEntry->value().equals(entry->value())) {
		map->remove(entry->key());
		return true;
	}

	return false;
}

bool TreeMap::EntrySetView::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

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

Reference TreeMap::EntrySetView::iterator() {
	return Reference(new EntryIterator(mMap));
}

bool TreeMap::EntrySetView::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->isEmpty();
}

tlint TreeMap::EntrySetView::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

Reference TreeMap::EntrySetView::toArray() {
	Reference rtval = Reference(new Array(Map::Entry::type(), size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());
	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	tlint index = 0;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		arr->set(index, element);
		index++;
	}

	return rtval;
}

type_t TreeMap::EntrySetView::type() {
	return CLASS_SERIAL;
}

bool TreeMap::EntrySetView::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Set::instanceof(type);
}

//Reference TreeMap::EntrySetView::first() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return TreeMap::TreeEntry::minEntry(map->mRootEntry);
//}
//
//Reference TreeMap::EntrySetView::last() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return TreeMap::TreeEntry::maxEntry(map->mRootEntry);
//}
//
//Reference TreeMap::EntrySetView::pollFirst() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return map->pollFirstEntry();
//}
//
//Reference TreeMap::EntrySetView::pollLast() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return map->pollLastEntry();
//}
//
//Reference TreeMap::EntrySetView::subSet(Reference fromElement,
//	Reference toElement) {
//	return subSet(fromElement, true, toElement, false);
//}
//
//Reference TreeMap::EntrySetView::subSet(Reference fromElement,
//	bool fromInclusive, Reference toElement, bool toInclusive) {
//
//}

TreeMap::PrivateEntryIterator::PrivateEntryIterator(Reference map) {
	mMap = map;

	TreeMap *treeMap = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = treeMap->firstEntry();
	mLastReturned = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::PrivateEntryIterator::hasNext() {
	return !mNext.isNull();
}

Reference TreeMap::PrivateEntryIterator::nextEntry() {
	Reference e = mNext;
	if (e.isNull()) {
		//cast NoSuchElementException
		throw NoSuchElementException();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(e.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = map->successor0(map->mRootEntry, entry->key());
	mLastReturned = e;

	return e;
}

Reference TreeMap::PrivateEntryIterator::previousEntry() {
	Reference e = mNext;
	if (e.isNull()) {
		//cast NoSuchElementException
		throw NoSuchElementException();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(e.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = map->predecessor0(map->mRootEntry, entry->key());
	mLastReturned = e;

	return e;
}

void TreeMap::PrivateEntryIterator::remove() {
	if (mLastReturned.isNull()) {
		throw NoSuchElementException();
	}

	TreeEntry *lastReturned =
		dynamic_cast<TreeEntry*>(mLastReturned.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->remove(lastReturned->key());

	mLastReturned = Reference();
}

type_t TreeMap::PrivateEntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::PrivateEntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterator::instanceof(type);
}

TreeMap::EntryIterator::EntryIterator(Reference map)
	: PrivateEntryIterator(map) {

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::EntryIterator::next() {
	return nextEntry();
}

type_t TreeMap::EntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::EntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::ValueIterator::ValueIterator(Reference map)
	: PrivateEntryIterator(map) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::ValueIterator::next() {
	Reference entryRef = PrivateEntryIterator::nextEntry();
	TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	return entry->value();
}

type_t TreeMap::ValueIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::ValueIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::KeyIterator::KeyIterator(Reference map)
	: PrivateEntryIterator(map) {

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::KeyIterator::next() {
	Reference entryRef = PrivateEntryIterator::nextEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

type_t TreeMap::KeyIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::KeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::DescendingKeyIterator::DescendingKeyIterator(Reference map)
	: PrivateEntryIterator(map) {
	TreeMap *treeMap = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = treeMap->lastEntry();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::DescendingKeyIterator::next() {
	Reference entryRef = TreeMap::PrivateEntryIterator::previousEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

type_t TreeMap::DescendingKeyIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::DescendingKeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::KeySet::KeySet(type_t elementType, Reference map)
	: Collection(elementType), Set(elementType), SortedSet(elementType), NavigableSet(
		elementType) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::KeySet::add(Reference ref) {
	return false;
}

bool TreeMap::KeySet::addAll(Reference ref) {
	return false;
}

bool TreeMap::KeySet::remove(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return !map->remove(ref).isNull();
}

bool TreeMap::KeySet::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference key = iterator->next();
		result = result || !map->remove(key).isNull();
	}

	return result;
}

bool TreeMap::KeySet::contains(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsKey(ref);
}

bool TreeMap::KeySet::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference key = iterator->next();
		result = result && map->containsKey(key);
		if (!result) {
			return result;
		}
	}

	return result;
}

void TreeMap::KeySet::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

Reference TreeMap::KeySet::ceiling(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->ceilingKey(keyRef);
}

Reference TreeMap::KeySet::floor(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->floorKey(keyRef);
}

Reference TreeMap::KeySet::lower(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lowerKey(keyRef);
}

Reference TreeMap::KeySet::higher(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->higherKey(keyRef);
}

Reference TreeMap::KeySet::first() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->firstKey();
}

Reference TreeMap::KeySet::last() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lastKey();
}

Reference TreeMap::KeySet::pollLast() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference entryRef = map->pollLastEntry();
	if (entryRef.isNull()) {
		return Reference();
	}

	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

Reference TreeMap::KeySet::pollFirst() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference entryRef = map->pollFirstEntry();
	if (entryRef.isNull()) {
		return Reference();
	}

	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

Reference TreeMap::KeySet::toArray() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(mElementType, map->size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	tlint index = 0;

	while (iterator->hasNext()) {
		arr->set(index, iterator->next());
		index++;
	}

	return rtval;
}

tlint TreeMap::KeySet::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

bool TreeMap::KeySet::isEmpty() {
	return size() == 0;
}

Reference TreeMap::KeySet::iterator() {
	return Reference(new KeyIterator(mMap));
}

type_t TreeMap::KeySet::type() {
	return CLASS_SERIAL;
}

bool TreeMap::KeySet::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NavigableSet::instanceof(type);
}

//Reference TreeMap::KeySet::subSet(Reference fromElement, Reference toElement) {
//	return subSet(fromElement, true, toElement, false);
//}
//
//Reference TreeMap::KeySet::subSet(Reference fromElement, bool fromInclusive,
//	Reference toElement, bool toInclusive) {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//	Reference subMapRef = map->subMap(fromElement, fromInclusive, toElement,
//		toInclusive);
//	TreeMap *subMap = dynamic_cast<TreeMap*>(subMapRef.getEntity());
//	return subMap->keySet();
//}

} /* namespace utils */
} /* namespace tl */
