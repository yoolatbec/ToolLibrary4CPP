/*
 * ArrayList.cpp
 *
 *  Created on: Apr 10, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Array.h>
#include <tl/lang/IllegalArgumentException.h>
#include <tl/lang/MemoryLimitExceededException.h>
#include <tl/utils/NoSuchElementException.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/Integer.h>
#include <tl/utils/ArrayList.h>

namespace tl {
namespace utils {

using lang::Array;
using lang::IllegalArgumentException;
using lang::MemoryLimitExceededException;
using lang::IndexOutOfBoundsException;
using lang::Integer;

ArrayList::ArrayList(type_t elementType)
	: Collection(elementType), List(elementType) {
	// TODO Auto-generated constructor stub
	mCurrentCapacity = DEFAULT_CAPACITY;
	mElements = Reference(new Array(elementType, mCurrentCapacity));

	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::ArrayList(type_t elementType, tlint capacity)
	: Collection(elementType), List(elementType) {
	if (capacity <= 0) {
		//cast an exception
		throw IllegalArgumentException();
	}

	mCurrentCapacity = capacity;
	mElements = Reference(new Array(elementType, mCurrentCapacity));

	mHashCode = genHashCode(CLASS_SERIAL);
}

void ArrayList::tryExpand() {
	if (mCurrentCapacity >= (tlint)(MAX_CAPACITY / EXPAND_FACTOR)) {
		//cast an exception
		throw MemoryLimitExceededException();
	}

	mCurrentCapacity = (tlint)(mCurrentCapacity * EXPAND_FACTOR);
	Reference newArray = Reference(new Array(mElementType, mCurrentCapacity));
	Array *newArr = dynamic_cast<Array*>(newArray.getEntity());
	Array *oldArr = dynamic_cast<Array*>(mElements.getEntity());

	for (tlint index = 0; index < oldArr->size(); index++) {
		newArr->set(index, oldArr->get(index));
	}

	mElements = newArray;
}

bool ArrayList::anyVacancy() {
	return mCurrentCapacity > mSize;
}

void ArrayList::invalidateIterators() {
	if (!mIterator.isNull()) {
		Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
		iterator->invalidate();
	}
}

bool ArrayList::add(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	if (!anyVacancy()) {
		tryExpand();
	}

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());
	arr->set(mSize, ref);
	mSize++;

	return true;
}

bool ArrayList::add(tlint index, Reference ref) {
	if (!anyVacancy()) {
		tryExpand();
	}

	indexBoundsCheck(index);
	dismissNull(ref);
	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());
	for (tlint i = mSize; i > index; i--) {
		Reference e = arr->get(i - 1);
		arr->set(i, e);
	}

	arr->set(index, ref);
	mSize++;

	return true;
}

bool ArrayList::addAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	ref = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());

	bool flag = false;
	while (iterator->hasNext()) {
		ref = iterator->next();
		if (ref.isNull()) {
			continue;
		}
		flag = flag || add(ref);
	}

	return flag;
}

bool ArrayList::addAll(tlint index, Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	ref = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());

	bool flag = false;
	while (iterator->hasNext()) {
		ref = iterator->next();
		if (ref.isNull()) {
			continue;
		}
		flag = flag || add(index, ref);
		index++;
	}

	return flag;
}

bool ArrayList::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	Array *arr = dynamic_cast<Array*>(ref.getEntity());
	for (tlint index = 0; index < mSize; index++) {
		Reference e = arr->get(index);

		if (ref.getEntity()->equals(e)) {
			return true;
		}
	}

	return false;
}

bool ArrayList::containsAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	ref = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());

	bool flag = true;
	while (iterator->hasNext()) {
		ref = iterator->next();
		flag = flag && contains(ref);
		if (!flag) {
			return flag;
		}
	}

	return flag;
}

void ArrayList::ensureCapacity(tlint capacity) {
	while (mCurrentCapacity < capacity) {
		tryExpand();
	}
}

Reference ArrayList::get(tlint index) {
	indexBoundsCheck(index);

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());
	return arr->get(index);
}

tlint ArrayList::indexOf(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	argumentTypeCheck(ref, mElementType);

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());
	for (tlint index = 0; index < mSize; index++) {
		Reference e = arr->get(index);
		if (ref.getEntity()->equals(e)) {
			return index;
		}
	}

	return -1;
}

Reference ArrayList::iterator() {
	return listIterator();
}

tlint ArrayList::lastIndexOf(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	argumentTypeCheck(ref, mElementType);

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());
	for (tlint index = mSize - 1; index >= 0; index--) {
		Reference e = arr->get(index);
		if (ref.getEntity()->equals(e)) {
			return index;
		}
	}

	return -1;
}

Reference ArrayList::listIterator() {
	invalidateIterators();

	mIterator = Reference(
		new ArrayListIterator(mElementType, Reference(this, false)));
	return mIterator;
}

Reference ArrayList::listIterator(tlint index) {
	indexBoundsCheck(index);
	invalidateIterators();

	if (!mIterator.isNull()) {
		Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
		iterator->invalidate();
	}

	mIterator = Reference(
		new ArrayListIterator(mElementType, Reference(this, false), index));
	return mIterator;
}

bool ArrayList::remove(Reference ref) {
	tlint index = indexOf(ref);

	if (index != -1) {
		remove(index);
		return true;
	}

	return false;
}

Reference ArrayList::remove(tlint index) {
	indexBoundsCheck(index);
	invalidateIterators();

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());

	Reference e = arr->get(index);
	mSize--;
	for (; index < mSize; index++) {
		Reference tmp = arr->get(index + 1);
		arr->set(index, tmp);
	}

	return e;
}

void ArrayList::removeAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	while (iterator->hasNext()) {
		ref = iterator->next();
		remove(ref);
	}
}

bool ArrayList::removeLast(Reference ref) {
	tlint index = lastIndexOf(ref);

	if (index != -1) {
		remove(index);
		return true;
	}

	return false;
}

Reference ArrayList::set(tlint index, Reference ref) {
	if (ref.isNull()) {
		remove(index);
	}

	indexBoundsCheck(index);
	argumentTypeCheck(ref, mElementType);

	Array *arr = dynamic_cast<Array*>(mElements.getEntity());
	Reference e = arr->get(index);
	arr->set(index, ref);
	return e;
}

Reference ArrayList::subList(tlint fromIndex, tlint toIndex) {
	indexBoundsCheck(fromIndex);
	if (toIndex < 0 || toIndex > mSize) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	Reference list = Reference(
		new ArrayList(mElementType, toIndex - fromIndex));
	ArrayList *sublist = dynamic_cast<ArrayList*>(list.getEntity());
	Array *arr = dynamic_cast<Array*>(mElements.getEntity());

	for (tlint index = fromIndex; index < toIndex; index++) {
		sublist->add(arr->get(index));
	}

	return list;
}

Reference ArrayList::toArray() {
	Array *elements = dynamic_cast<Array*>(mElements.getEntity());

	Reference rtval = Reference(new Array(mElementType, mSize));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	for (tlint index = 0; index < mSize; index++) {
		arr->set(index, elements->get(index));
	}

	return rtval;
}

void ArrayList::trim() {
	if (anyVacancy()) {
		Reference newArray = Reference(new Array(mElementType, mSize));
		Array *newArr = dynamic_cast<Array*>(newArray.getEntity());
		Array *arr = dynamic_cast<Array*>(mElements.getEntity());

		for (tlint index = 0; index < mSize; index++) {
			newArr->set(index, arr->get(index));
		}

		mElements = newArray;
	}
}

ArrayList::~ArrayList() {
	// TODO Auto-generated destructor stub
}

type_t ArrayList::type() {
	return CLASS_SERIAL;
}

bool ArrayList::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || List::instanceof(type);
}

ArrayList::ArrayListIterator::ArrayListIterator(type_t elementType,
	Reference list)
	: ListIterator(elementType, list) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::ArrayListIterator::ArrayListIterator(type_t elementType,
	Reference list, tlint index)
	: ListIterator(elementType, list, index) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::ArrayListIterator::~ArrayListIterator() {

}

void ArrayList::ArrayListIterator::add(Reference ref) {
	checkValidation();
	if (mLastIndex == -1) {
		//cast an exception
		throw NoSuchElementException();
	}

	ArrayList *list = dynamic_cast<ArrayList*>(mList.getEntity());
	list->add(mLastIndex, ref);

	mCurrentIndex = mLastIndex;
	mLastIndex = -1;
}

Reference ArrayList::ArrayListIterator::next() {
	checkValidation();

	ArrayList *list = dynamic_cast<ArrayList*>(mList.getEntity());
	Reference e = list->get(mCurrentIndex);
	mLastIndex = mCurrentIndex;
	mCurrentIndex++;

	mForward = true;

	return e;
}

Reference ArrayList::ArrayListIterator::previous() {
	checkValidation();

	ArrayList *list = dynamic_cast<ArrayList*>(mList.getEntity());
	Reference e = list->get(mCurrentIndex);
	mLastIndex = mCurrentIndex;
	mCurrentIndex--;

	mForward = false;

	return e;
}

void ArrayList::ArrayListIterator::remove() {
	checkValidation();
	if (mLastIndex == -1) {
		//cast an exception
		throw NoSuchElementException();
	}

	ArrayList *list = dynamic_cast<ArrayList*>(mList.getEntity());
	list->remove(mLastIndex);
	if (mForward) {
		mCurrentIndex = mLastIndex;
	}

	mLastIndex = -1;
}

void ArrayList::ArrayListIterator::set(Reference ref) {
	checkValidation();
	dismissNull(ref);

	if (mLastIndex == -1) {
		//cast an exception
		throw NoSuchElementException();
	}

	ArrayList *list = dynamic_cast<ArrayList*>(mList.getEntity());
	list->set(mLastIndex, ref);

	mLastIndex = -1;
}

type_t ArrayList::ArrayListIterator::type() {
	return CLASS_SERIAL;
}

bool ArrayList::ArrayListIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ListIterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
