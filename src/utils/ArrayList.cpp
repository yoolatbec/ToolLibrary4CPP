/*
 * ArrayList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "ArrayList.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {
using lang::Reference;
using lang::Array;

ArrayList::ArrayList(type_t type)
	: Collection(type), List(type) {
	mElements = new Reference[mCapacity];

	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::ArrayList(type_t type, tlint reserved)
	: Collection(type), List(type, reserved) {
	if (reserved > MAX_CAPACITY) {
		//cast an exception here
	}

	mElements = new Reference[mCapacity];

	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::~ArrayList() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

void ArrayList::boundCheck(tlint position) {
	if (position >= mSize || position < 0) {
		//cast IndexOutOfBoundException exception
	}
}

tlint ArrayList::argumentCheck(Reference ref, type_t type) {
	if (ref.isNull()) {
		return 0;
	}

	if (!ref.getEntity()->instanceof(type)) {
		return -1;
	}

	return 1;
}

void ArrayList::add0(Reference ref) {
	if (mSize == mCapacity) {
		expand();
	}

	mElements[mSize] = ref;
	mSize++;
	mModified = true;
}

void ArrayList::insert0(tlint position, Reference ref) {
	if (mSize == mCapacity) {
		expand();
	}

	for (tlint index = mSize; index > position; index--) {
		mElements[index] = mElements[index - 1];
	}

	mElements[position] = ref;
	mSize++;
	mModified = true;
}

tlint ArrayList::indexOf0(Reference ref) {
	for (tlint index = 0; index < mSize; index++) {
		if (mElements[index].equals(ref)) {
			return index;
		}
	}

	return -1;
}

tlint ArrayList::lastIndexOf0(Reference ref) {
	for (tlint index = mSize - 1; index >= 0; index--) {
		if (mElements[index].equals(ref)) {
			return index;
		}
	}

	return -1;
}

Reference ArrayList::set0(tlint position, Reference ref) {
	Reference oldElement = mElements[position];
	if (oldElement.equals(ref)) {
		return ref;
	}

	mElements[position] = ref;
	mModified = true;
	return oldElement;
}

void ArrayList::remove0(tlint position) {
	mSize--;
	for (tlint index = position; index < mSize; index++) {
		mElements[index] = mElements[index + 1];
	}
	mElements[mSize] = Reference();
	mModified = true;
}

bool ArrayList::add(Reference value) {
	switch (argumentCheck(value, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception here;
	default:
		//do nothing
	}

	if (mSize == mCapacity) {
		expand();
	}

	add0(value);
	return true;
}

bool ArrayList::addAll(Reference ref) {
	switch (argumentCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		//cast an exception
		return false;
	}

	if (collection->mSize <= 0) {
		return false;
	}

	Iterator *iterator =
		dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add0(ref);
	}
	return true;
}

bool ArrayList::contains(Reference ref) {
	switch (argumentCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		// do nothing
	}

	return indexOf0(ref) >= 0;
}

bool ArrayList::containsAll(Reference ref) {
	switch (argumentCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	if (mSize == 0) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		//should cast an exception
		return false;
	}

	bool result = true;
	Iterator *iterator =
		dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		Reference obj = iterator->next();
		result = result && (indexOf0(obj) >= 0);
		if (!result) {
			return result;
		}
	}

	return result;
}

bool ArrayList::insert(tlint position, Reference ref) {
	switch (argumentCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		// do nothing
	}

	if (mSize < position) {
		return false;
	}

	if (mSize == position) {
		return add0(ref);
	}

	insert0(position, ref);
	return true;
}

bool ArrayList::insertAll(tlint position, Reference ref) {
	if (position == mSize) {
		return addAll(ref);
	}

	switch (argumentCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		return false;
	}

	if (position < 0 || position > mSize) {
		return false;
	}

	tlint size = collection->size();
	while (mCapacity <= size + mSize) {
		expand();
	}

	tlint index;
	for (index = mSize - 1; index >= position; index--) {
		mElements[index + size] = mElements[index];
	}

	index = position;
	Iterator *iterator =
		dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		mElements[index] = iterator->next();
		index++;
	}

	mSize += size;
	mModified = true;
	return true;
}

tlint ArrayList::lastIndexOf(Reference ref) {
	switch (argumentCheck(ref, mElementType)) {
	case 0:
		return -1;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	return lastIndexOf0(ref);
}

bool ArrayList::remove(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	switch (argumentCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	tlint index = indexOf0(ref);
	if (index >= 0) {
		remove0(index);
	}

	return index >= 0;
}

bool ArrayList::remove(tlint position) {
	if (isEmpty()) {
		return false;
	}

	boundCheck(position);

	remove0(position);

	return true;
}

bool ArrayList::removeLast(Reference ref) {
	switch (argumentCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	tlint index = lastIndexOf0(ref);
	if (index >= 0) {
		remove0(index);
	}

	return (index >= 0);
}

bool ArrayList::removeAll(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	switch (argumentCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		//cast an exception
		return false;
	}

	Iterator *iterator =
		dynamic_cast<Iterator*>(collection->iterator().getEntity());
	bool removed = false;
	while (iterator->hasNext()) {
		removed = remove(iterator->next()) || removed;
	}
	return removed;
}

Reference ArrayList::get(tlint position) {
	boundCheck(position);

	return mElements[position];
}

Reference ArrayList::set(tlint position, Reference ref) {
	switch (argumentCheck(ref, mElementType)) {
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	boundCheck(position);

	return set0(position, ref);
}

Reference ArrayList::toArray() {
	Array *arr = new Array(mElementType, mSize);
	for (tlint index = 0; index < mSize; index++) {
		arr->set(index, mElements[index]);
	}
	return Reference(arr);
}

Reference ArrayList::sublist(tlint begin, tlint end) {
	if (end < begin) {
		//should cast an exception
		return Reference();
	}

	boundCheck(begin);
	boundCheck(end);

	ArrayList *list = new ArrayList(mElementType);

	for (tlint index = begin; index < end; index++) {
		list->add(mElements[index]);
	}

	return Reference(list);
}

bool ArrayList::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || List::instanceof(type);
}

void ArrayList::clear() {
	delete[] mElements;
	mElements = new Reference[DEFAULT_CAPACITY];
	mCapacity = DEFAULT_CAPACITY;
	mSize = 0;
	mModified = true;
}

void ArrayList::expand() {
	if (mCapacity == MAX_CAPACITY) {
		//cast SizeOutOfLimitException
	}

	tlint newCapacity;
	if (mCapacity > MAX_CAPACITY / 2) {
		newCapacity = MAX_CAPACITY;
	} else {
		newCapacity = mCapacity * 2;
	}

	Reference *newElements = new Reference[newCapacity];
	for (tlint index = 0; index < mSize; index++) {
		newElements[index] = mElements[index];
	}

	delete[] mElements;
	mElements = newElements;
	mCapacity = newCapacity;
}

void ArrayList::trim() {
	if (mSize == mCapacity) {
		return;
	}

	Reference *newElements = new Reference[mSize];
	for (tlint index = 0; index < mSize; index++) {
		newElements[index] = mElements[index];
	}

	delete[] mElements;
	mElements = newElements;
	mCapacity = mSize;
	mModified = true;
}

void ArrayList::ensureCapacity(tlint capacity) {
	if (capacity <= mCapacity) {
		return;
	}

	Reference *newElements = new Reference[capacity];
	for (tlint index = 0; index < mSize; index++) {
		newElements[index] = mElements[index];
	}

	delete[] mElements;
	mElements = newElements;
	mModified = true;
}

Reference ArrayList::iterator() {
	return Reference(new ArrayListIterator(Reference(this, false), 0));
}

type_t ArrayList::type() {
	return CLASS_SERIAL;
}

Reference ArrayList::iterator(tlint initCursor) {
	return Reference(new ArrayListIterator(Reference(this, false), initCursor));
}

ArrayList::ArrayListIterator::ArrayListIterator(Reference list,
	tlint initCursor)
	: ListIterator(list, initCursor) {
	indexRangeCheck();

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool ArrayList::ArrayListIterator::hasNext() {
	List *list = dynamic_cast<List*>(mList.getEntity());
	return mCursor < (list->size() - 1);
}

bool ArrayList::ArrayListIterator::hasPrevious() {
	return mCursor > 0;
}

void ArrayList::ArrayListIterator::remove() {
	if (mLastCursor < 0) {
		//cast an exception
	}

	List *list = dynamic_cast<List*>(mList.getEntity());
	list->remove(mLastCursor);

	mCursor = mLastCursor;
	mLastCursor = -1;
}

void ArrayList::ArrayListIterator::set(Reference newValue) {
	if (mLastCursor < 0) {
		//cast an exception
	}

	List *list = dynamic_cast<List*>(mList.getEntity());
	list->set(mLastCursor, newValue);
}


Reference ArrayList::ArrayListIterator::nextElement() {
	indexRangeCheck();

	List *list = dynamic_cast<List*>(mList.getEntity());
	Reference element = list->get(mCursor);
	mLastCursor = mCursor;
	mCursor++;

	return element;
}

Reference ArrayList::ArrayListIterator::previousElement() {
	indexRangeCheck();

	List *list = dynamic_cast<List*>(mList.getEntity());
	Reference element = list->get(mCursor);
	mLastCursor = mCursor;
	mCursor--;

	return element;
}

tlint ArrayList::ArrayListIterator::nextIndex() {
	return mCursor;
}

tlint ArrayList::ArrayListIterator::previousIndex() {
	return mCursor - 1;
}

Reference ArrayList::ArrayListIterator::next() {
	return nextElement();
}

Reference ArrayList::ArrayListIterator::previous() {
	return previousElement();
}

type_t ArrayList::ArrayListIterator::type() {
	return CLASS_SERIAL;
}

bool ArrayList::ArrayListIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ListIterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
