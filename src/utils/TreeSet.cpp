/*
 * TreeSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include <lang/Array.h>

#include <utils/LinkedList.h>
#include <utils/TreeSet.h>

namespace tl {
namespace utils {

using lang::Array;
using lang::Reference;

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

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

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

	argumentTypeCheck(ref, Collection::type());
	invalidateIterators();

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

bool TreeSet::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	return contains0(ref);
}

bool TreeSet::containsAll(Reference ref) {
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
	}

	return result;
}

bool TreeSet::remove(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

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

	argumentTypeCheck(ref, Collection::type());
	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	if (collection->size() <= 0) {
		return false;
	}

	bool result = false;
	Iterator *iterator =
			dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		bool exist = contains(element);
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

Reference TreeSet::ceiling(Reference ref){
	TreeMap* map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->ceilingKey(ref);
}

Reference TreeSet::floor(Reference ref){
	TreeMap* map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->floorKey(ref);
}

//Reference TreeSet::subSet(Reference fromElement, bool fromInclusive,
//		Reference toElement, bool toInclusive) {
//	typeCheck(fromElement, mElementType);
//	typeCheck(toElement, mElementType);
//
//	if (!contains0(fromElement) || !contains0(toElement)) {
//		//cast IllegalArgumentException
//	}
//
//	if (fromElement.getEntity()->mHashCode > toElement.getEntity()->mHashCode) {
//		//cast IllegalArgumentException
//	}
//
//	Reference resultSetRef = Reference(new TreeSet(mElementType));
//	TreeSet *set = dynamic_cast<TreeSet*>(resultSetRef.getEntity());
//	Reference iteratorRef = iterator();
//	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
//
//	while (iterator->hasNext()) {
//		Reference element = iterator->next();
//		if (element.getEntity()->mHashCode
//				< fromElement.getEntity()->mHashCode) {
//			continue;
//		}
//
//		if (element.getEntity()->mHashCode > toElement.getEntity()->mHashCode) {
//			break;
//		}
//
//		if ((element.getEntity()->mHashCode == fromElement.getEntity())
//				&& fromInclusive) {
//			set->add(element);
//		} else {
//			continue;
//		}
//
//		if ((element.getEntity()->mHashCode == toElement.getEntity()->mHashCode)
//				&& toInclusive) {
//			set->add(element);
//		} else {
//			break;
//		}
//
//		set->add(element);
//	}
//
//	return resultSetRef;
//}
//
//Reference TreeSet::subSet(Reference fromElement, Reference toElement) {
//	return subSet(fromElement, true, toElement, false);
//}

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
	TreeMap* map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference keySetRef = map->keySet();
	Set* keySet = dynamic_cast<Set*>(keySetRef.getEntity());
	mIterator = keySet->iterator();
	return mIterator;
}

void TreeSet::invalidateIterators(){
	if(mIterator.isNull()){
		return;
	}

	Iterator* iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
}

void TreeSet::clear() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();

	mSize = 0;
}

void TreeSet::add0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->put(ref, Reference());
	mSize = map->size();
}

void TreeSet::remove0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->remove(ref);
	mSize = map->size();
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

} /* namespace utils */
} /* namespace tl */
