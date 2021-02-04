/*
 * TreeSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "TreeSet.h"
#include "../lang/Array.h"
#include "LinkedList.h"

namespace tl {
namespace utils {

TreeSet::TreeSet(type_t type) :
		Set(type) {
	// TODO Auto-generated constructor stub
	mMap = Reference(new TreeMap(type, Object::type()));

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeSet::~TreeSet() {
	// TODO Auto-generated destructor stub
	clear();
}

bool TreeSet::add(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, mElementType);

	if (contains0(ref)) {
		return false;
	}

	add0(ref);
	return true;
}

bool TreeSet::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	typeCheck(collection->mElementType, mElementType);

	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		if (!contains0(element)) {
			add0(element);
			result = true;
		}
	}

	return result;
}

bool TreeSet::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, mElementType);

	return contains0(ref);
}

bool TreeSet::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	typeCheck(collection->mElementType, mElementType);

	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result && contains0(element);
		if (!result) {
			return result;
		}
	}

	return result;
}

bool TreeSet::remove(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, mElementType);

	if (!contains0(ref)) {
		return false;
	}

	remove0(ref);
	return true;
}

bool TreeSet::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	typeCheck(collection->mElementType, mElementType);

	if (collection->mSize == 0) {
		return false;
	}

	bool result = false;
	Iterator *iterator =
			dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		bool exist = contains0(element);
		if (exist) {
			remove0(element);
		}
		result = result || exist;
	}

	return result;
}

Reference TreeSet::first() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->firstKey();
}

Reference TreeSet::last() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lastKey();
}

Reference TreeSet::higher(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->ceilingKey(ref);
}

Reference TreeSet::lower(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->floorKey(ref);
}

Reference TreeSet::pollFirst() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference first = map->pollFirstEntry();

	if(first.isNull()){
		return Reference();
	}

	Map::Entry* entry = dynamic_cast<Map::Entry*>(first.getEntity());
	return entry->key();
}

Reference TreeSet::pollLast() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference last = map->pollLastEntry();

	if(last.isNull()){
		return Reference();
	}

	Map::Entry* entry = dynamic_cast<Map::Entry*>(last.getEntity());
	return entry->key();
}

Reference TreeSet::subSet(Reference fromElement, bool fromInclusive,
		Reference toElement, bool toInclusive) {
	typeCheck(fromElement, mElementType);
	typeCheck(toElement, mElementType);

	if (!contains0(fromElement) || !contains0(toElement)) {
		//cast IllegalArgumentException
	}

	if (fromElement.getEntity()->mHashCode > toElement.getEntity()->mHashCode) {
		//cast IllegalArgumentException
	}

	Reference resultSetRef = Reference(new TreeSet(mElementType));
	TreeSet *set = dynamic_cast<TreeSet*>(resultSetRef.getEntity());
	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	while (iterator->hasNext()) {
		Reference element = iterator->next();
		if (element.getEntity()->mHashCode
				< fromElement.getEntity()->mHashCode) {
			continue;
		}

		if (element.getEntity()->mHashCode > toElement.getEntity()->mHashCode) {
			break;
		}

		if ((element.getEntity()->mHashCode == fromElement.getEntity())
				&& fromInclusive) {
			set->add(element);
		} else {
			continue;
		}

		if ((element.getEntity()->mHashCode == toElement.getEntity()->mHashCode)
				&& toInclusive) {
			set->add(element);
		} else {
			break;
		}

		set->add(element);
	}

	return resultSetRef;
}

Reference TreeSet::subSet(Reference fromElement, Reference toElement) {
	return subSet(fromElement, true, toElement, false);
}

Reference TreeSet::toArray() {
	Reference arrayRef = Reference(new Array(mElementType, mSize));
	Array *array = dynamic_cast<Array*>(arrayRef.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	tlint index = 0;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		array->set(index, element);
		index++;
	}

	return arrayRef;
}

Reference TreeSet::iterator() {
	return Reference(new TreeSetIterator(Reference(this, false)));
}

void TreeSet::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();

	mSize = 0;
	mModified = true;
}

void TreeSet::typeCheck(Reference ref, type_t type) {
	if (!ref.getEntity()->instanceof(type)) {
		//cast an exception
	}
}

void TreeSet::typeCheck(type_t t1, type_t t2) {
	if (t1 != t2) {
		//cast an exception
	}
}

void TreeSet::add0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->put(ref, Reference());
	mSize = map->size();
	mModified = true;
}

void TreeSet::remove0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->remove(ref);
	mSize = map->size();
	mModified = true;
}

bool TreeSet::contains0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsKey(ref);
}

bool TreeSet::instanceof(type_t type) {
	return CLASS_SERIAL == type || Set::instanceof(type);
}

type_t TreeSet::elementType() {
	return mElementType;
}

type_t TreeSet::type() {
	return CLASS_SERIAL;
}

TreeSet::TreeSetIterator::TreeSetIterator(Reference ref) {
	if (!ref.instanceof(TreeSet::type())) {
		//cast an exception here
	}

	mSet = ref;
	TreeSet *set = dynamic_cast<TreeSet*>(mSet.getEntity());
	mSetElements = new Array(set->elementType(), set->size());
}

} /* namespace utils */
} /* namespace tl */
