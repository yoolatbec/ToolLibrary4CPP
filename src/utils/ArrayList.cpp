/*
 * ArrayList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "ArrayList.h"
using tl::lang::Reference;
using tl::lang::Array;

namespace tl {
namespace utils {

ArrayList::ArrayList(hash_t type)
		: Collection(type), List(type) {
	mElements = new Reference[mCapacity];
}

ArrayList::ArrayList(hash_t type, size_t reserved)
		: Collection(type), List(type, reserved) {
	mElements = new Reference[mCapacity];
}

ArrayList::~ArrayList() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

bool ArrayList::add(const Reference &value) {
	if (value.isNull()) {
		return false;
	}

	if (!value.instanceof(mElementType)) {
		return false;
	}

	if (mSize == mCapacity) {
		expand();
	}

	mElements[mSize] = value;
	mSize++;
	mModified = true;
	return true;
}

bool ArrayList::addAll(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add(ref);
	}
	return true;
}

bool ArrayList::contains(const Reference &ref) const {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	if (mSize == 0) {
		return false;
	}

	for (size_t index = 0; index < mSize; index++) {
		if (mElements[index].equals(ref)) {
			return true;
		}
	}
	return false;
}

bool ArrayList::insert(const Reference &ref, size_t position) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	if (mSize < position) {
		return false;
	}

	if (mSize == position) {
		return add(ref);
	}

	if (mSize == mCapacity) {
		expand();
	}

	for (size_t index = mSize; index > position; index--) {
		mElements[index] = mElements[index - 1];
	}
	mElements[position] = ref;
	mSize++;
	mModified = true;
	return true;
}

bool ArrayList::insertAll(const Reference &ref, size_t position) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	if (position < 0 || position > mSize) {
		return false;
	}

	if (position == mSize) {
		return addAll(ref);
	}

	size_t size = collection->size();
	while (mCapacity <= size + mSize) {
		expand();
	}

	size_t index;
	for (index = position; index < mSize; index++) {
		mElements[index + size] = mElements[index];
	}

	index = position;
	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		mElements[index] = iterator->next();
		index++;
	}

	mSize += size;
	mModified = true;
	return true;
}

bool ArrayList::remove(const Reference &ref) {
	if(empty()){
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	bool found = false;
	size_t index = 0;
	while(index < mSize){
		if(mElements[index].equals(ref)){
			remove(index);
			found = true;
			continue;
		}
		index++;
	}

	return found;
}

bool ArrayList::remove(size_t position) {
	if(empty()){
		return false;
	}

	if (position < 0 || position >= mSize) {
		return false;
	}

	for (size_t index = position; index < mSize - 1; index++) {
		mElements[index] = mElements[index + 1];
	}
	mSize--;
	mElements[mSize] = Reference();
	mModified = true;

	return true;
}

bool ArrayList::removeAll(const Reference &ref) {
	if(empty()){
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Iterator *iterator = collection->iterator();
	bool removed = false;
	while (iterator->hasNext()) {
		removed = remove(iterator->next()) || removed;
	}
	return removed;
}

Reference ArrayList::get(size_t position) {
	if (position < 0 || position >= mSize) {
		return Reference();
	}

	return mElements[position];
}

bool ArrayList::replace(const Reference &ref, size_t position) {
	if (ref.isNull()) {
		return remove(position);
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	if (position < 0 || position >= mSize) {
		return false;
	}

	mElements[position] = ref;
	mModified = true;
	return true;
}

lang::Array* ArrayList::toArray() const {
	Array *arr = new Array(mSize, mElementType);
	for (size_t index = 0; index < mSize; index++) {
		arr->set(mElements[index], index);
	}
	return arr;
}

bool ArrayList::instanceof(hash_t type) const {
	return ((mHash & CLASS_MASK) == type) || List::instanceof(type);
}

void ArrayList::clear() {
	delete[] mElements;
	mElements = new Reference[DEFAULT_CAPACITY];
	mCapacity = DEFAULT_CAPACITY;
	mSize = 0;
	mModified = true;
}

void ArrayList::expand(){
	size_t newCapacity = mCapacity * 2;
	Reference* newElements = new Reference[newCapacity];
	for(size_t index = 0; index < mSize; index++){
		newElements[index] = mElements[index];
	}

	delete [] mElements;
	mElements = newElements;
	mCapacity = newCapacity;
}

Iterator* ArrayList::iterator() {
	return new ArrayListIterator(this);
}

hash_t ArrayList::getType() {
	return CLASS_HASH;
}

ArrayList::ArrayListIterator::ArrayListIterator(ArrayList *list)
		: mList(list) {
	mCurrent = 0;
	mList->mModified = false;
}

hash_t ArrayList::ArrayListIterator::getType() {
	return CLASS_HASH;
}

bool ArrayList::ArrayListIterator::instanceof(hash_t type) const {
	return ((mHash & CLASS_MASK) == type) || Iterator::instanceof(type);
}

bool ArrayList::ArrayListIterator::hasNext() const {
	if (!mValidate) {

	}

	return mCurrent < mList->mSize;
}

Reference ArrayList::ArrayListIterator::next() {
	if (!mValidate) {

	}

	return mList->mElements[mCurrent++];
}

bool ArrayList::ArrayListIterator::remove() {
	if (!mValidate) {

	}

	if (mList->mSize == 0) {
		return false;
	}

	for (size_t index = mCurrent; index < mList->mSize - 1; index++) {
		mList->mElements[index] = mList->mElements[index + 1];
	}
	(mList->mSize)--;
	mList->mElements[mList->mSize] = Reference();

	return true;
}

bool ArrayList::ArrayListIterator::insert(const Reference &ref) {
	if (!mValidate) {

	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mList->mElementType)) {
		return false;
	}

	if (mList->mSize == mList->mCapacity) {
		mList->expand();
	}

	for (size_t index = mList->mSize; index > mCurrent; index--) {
		mList->mElements[index] = mList->mElements[index - 1];
	}
	mList->mElements[mCurrent] = ref;

	return true;
}

} /* namespace utils */
} /* namespace tl */
