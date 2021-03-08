/*
 * ArrayList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include <lang/Array.h>
#include <lang/MemoryLimitExceededException.h>
#include <lang/UnacceptableArgumentException.h>
#include <utils/ArrayList.h>

namespace tl {
namespace utils {

using lang::Reference;
using lang::Array;
using lang::UnacceptableArgumentException;
using lang::MemoryLimitExceededException;

ArrayList::ArrayList(type_t type)
		: Collection(type), List(type) {
	mElements = new Reference[mCapacity];

	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::ArrayList(type_t type, tlint reserved)
		: Collection(type), List(type, reserved) {
	if (reserved > MAX_CAPACITY) {
		//cast an exception here
		throw UnacceptableArgumentException();
	}

	mElements = new Reference[mCapacity];

	mHashCode = genHashCode(CLASS_SERIAL);
}

void ArrayList::invalidateIterators(){
	if(mIterator.isNull()){
		return;
	}

	Iterator* iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
}

ArrayList::~ArrayList() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

void ArrayList::boundCheck(tlint position) {
	if (position >= mSize || position < 0) {
		//cast IndexOutOfBoundException exception
		throw UnacceptableArgumentException();
	}
}

void ArrayList::add0(Reference ref) {
	if (mSize == mCapacity) {
		expand();
	}

	mElements[mSize] = ref;
	mSize++;
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
	return oldElement;
}

void ArrayList::remove0(tlint position) {
	mSize--;
	for (tlint index = position; index < mSize; index++) {
		mElements[index] = mElements[index + 1];
	}
	mElements[mSize] = Reference();
}

bool ArrayList::add(Reference value) {
	if(value.isNull()){
		return false;
	}

	argumentTypeCheck(value, mElementType);

	invalidateIterators();

	if (mSize == mCapacity) {
		expand();
	}

	add0(value);
	return true;
}

bool ArrayList::addAll(Reference ref) {
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->size() <= 0) {
		return false;
	}

	Iterator *iterator =
			dynamic_cast<Iterator*>(collection->iterator().getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		result = result || add(ref);
	}
	return result;
}

bool ArrayList::contains(Reference ref) {
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	return indexOf0(ref) >= 0;
}

bool ArrayList::containsAll(Reference ref) {
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	if (mSize == 0) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	bool result = true;
	Iterator *iterator =
			dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		Reference obj = iterator->next();
		result = result && contains(obj);
		if (!result) {
			return result;
		}
	}

	return result;
}

bool ArrayList::insert(tlint position, Reference ref) {
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	if (mSize < position) {
		return false;
	}

	if (mSize == position) {
		add0(ref);
		return true;
	}

	insert0(position, ref);
	return true;
}

bool ArrayList::insertAll(tlint position, Reference ref) {
	if (position == mSize) {
		return addAll(ref);
	}

	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	indexBoundCheck(position);

	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());


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
		Reference e = iterator->next();
		argumentTypeCheck(e, mElementType);
		mElements[index] = e;
		index++;
	}

	mSize += size;
	return true;
}

tlint ArrayList::lastIndexOf(Reference ref) {
	if(ref.isNull()){
		return -1;
	}

	argumentTypeCheck(ref, mElementType);

	return lastIndexOf0(ref);
}

bool ArrayList::remove(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

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

	invalidateIterators();

	remove0(position);

	return true;
}

bool ArrayList::removeLast(Reference ref) {
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

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

	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

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
	if(ref.isNull()){
		return Reference();
	}

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

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
		throw UnacceptableArgumentException();
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
	invalidateIterators();

	delete[] mElements;
	mElements = new Reference[DEFAULT_CAPACITY];
	mCapacity = DEFAULT_CAPACITY;
	mSize = 0;
}

void ArrayList::expand() {
	if (mCapacity == MAX_CAPACITY) {
		//cast SizeOutOfLimitException
		throw MemoryLimitExceededException();
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
}

Reference ArrayList::iterator() {
	mIterator = Reference(new ArrayListIterator(Reference(this, false), 0));
	return mIterator;
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
	checkValidation();

	List *list = dynamic_cast<List*>(mList.getEntity());
	return mCursor < (list->size() - 1);
}

bool ArrayList::ArrayListIterator::hasPrevious() {
	checkValidation();

	return mCursor > 0;
}

void ArrayList::ArrayListIterator::remove() {
	checkValidation();

	if (mLastCursor < 0) {
		//cast an exception
		throw UnacceptableArgumentException();
	}

	List *list = dynamic_cast<List*>(mList.getEntity());
	list->remove(mLastCursor);

	mCursor = mLastCursor;
	mLastCursor = -1;
}

void ArrayList::ArrayListIterator::set(Reference newValue) {
	checkValidation();

	if (mLastCursor < 0) {
		//cast an exception
		throw UnacceptableArgumentException();
	}

	List *list = dynamic_cast<List*>(mList.getEntity());
	list->set(mLastCursor, newValue);
}

Reference ArrayList::ArrayListIterator::nextElement() {
	checkValidation();
	indexRangeCheck();

	List *list = dynamic_cast<List*>(mList.getEntity());
	Reference element = list->get(mCursor);
	mLastCursor = mCursor;
	mCursor++;

	return element;
}

Reference ArrayList::ArrayListIterator::previousElement() {
	checkValidation();
	indexRangeCheck();

	List *list = dynamic_cast<List*>(mList.getEntity());
	Reference element = list->get(mCursor);
	mLastCursor = mCursor;
	mCursor--;

	return element;
}

tlint ArrayList::ArrayListIterator::nextIndex() {
	checkValidation();

	return mCursor;
}

tlint ArrayList::ArrayListIterator::previousIndex() {
	checkValidation();

	return mCursor - 1;
}

Reference ArrayList::ArrayListIterator::next() {
	checkValidation();

	return nextElement();
}

Reference ArrayList::ArrayListIterator::previous() {
	checkValidation();

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
