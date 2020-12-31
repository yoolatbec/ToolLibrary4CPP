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

TreeSet::TreeSet(type_t type)
		: Set(type) {
	// TODO Auto-generated constructor stub
	mMap = Reference(new TreeMap(type, Object::type()));

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeSet::~TreeSet() {
	// TODO Auto-generated destructor stub
	mMap = Reference()();
}

bool TreeSet::add(Reference ref) {
	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	if (contains0(ref)) {
		return false;
	}

	add0(ref);
	return true;
}

bool TreeSet::addAll(Reference ref) {
	switch (typeCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->mElementType != mElementType) {
		//cast an exception here
	}

	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		if (!contains0(element)) {
			result = result || add0(element);
		}
	}

	return result;
}

bool TreeSet::contains(Reference ref) {
	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	return contains0(ref);
}

bool TreeSet::containsAll(Reference ref) {
	switch (typeCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->mElementType != mElementType) {
		//cast an exception here
	}

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

bool TreeSet::remove(Reference ref){
	switch(typeCheck(ref, mElementType)){
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	if(!contains0(ref)){
		return false;
	}

	remove0(ref);
	return true;
}

Reference TreeSet::iterator() {
	return Reference(new TreeSetIterator(Reference(this)));
}

byte TreeSet::typeCheck(Reference ref, type_t type) {
	if (ref.isNull()) {
		return 0;
	}

	if (!ref.getEntity()->instanceof(type)) {
		return -1;
	}

	return 1;
}

void TreeSet::add0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->put(ref, Reference());
	mSize++;
}

void TreeSet::remove0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->remove(ref);
	mSize--;
}

bool TreeSet::contains0(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsKey(ref);
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
