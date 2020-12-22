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

ArrayList::ArrayList(type_t type)
		: Collection(type), List(type) {
	mElements = new Reference[mCapacity];

	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::ArrayList(type_t type, size_t reserved)
		: Collection(type), List(type, reserved) {
	if(reserved > MAX_CAPACITY){
		//cast an exception here
	}

	mElements = new Reference[mCapacity];

	mHashCode = genHashCode(CLASS_SERIAL);
}

ArrayList::~ArrayList() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

bool ArrayList::add(Reference value) {
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

bool ArrayList::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
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

bool ArrayList::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(mElementType)) {
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

bool ArrayList::containsAll(Reference ref){
	if(ref.isNull()){
		return false;
	}

	if(!ref.getEntity()->instanceof(Collection::type())){
		//should cast an exception
		return false;
	}

	if(mSize == 0){
		return false;
	}

	Collection* collection = dynamic_cast<Collection*>(ref.getEntity());
	if(collection->mElementType != mElementType){
		//should cast an exception
		return false;
	}

	bool result = true;
	Iterator* iterator = collection->iterator();
	while(iterator->hasNext()){
		Reference obj = iterator->next();
		result = result && contains(obj);
		if(!result){
			return result;
		}
	}

	return result;
}

bool ArrayList::insert(Reference ref, size_t position) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(mElementType)) {
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

bool ArrayList::insertAll(Reference ref, size_t position) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
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

tlint ArrayList::indexOf(Reference ref){
	for(int index = 0; index < mSize; index++){
		if(mElements[index].equals(ref)){
			return index;
		}
	}

	return -1;
}

bool ArrayList::remove(Reference ref) {
	if(empty()){
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(mElementType)) {
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

bool ArrayList::removeAll(Reference ref) {
	if(empty()){
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
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

bool ArrayList::set(size_t position, Reference ref) {
	if (position < 0 || position >= mSize) {
		return false;
	}

	if (ref.isNull()) {
		mElements[position] = Reference();
		return true;
	}

	if (!ref.getEntity()->instanceof(mElementType)) {
		return false;
	}

	mElements[position] = ref;
	mModified = true;
	return true;
}

lang::Array* ArrayList::toArray() {
	Array *arr = new Array(mElementType, mSize);
	for (size_t index = 0; index < mSize; index++) {
		arr->set(mElements[index], index);
	}
	return arr;
}

List* ArrayList::sublist(size_t begin, size_t end){
	if(end < begin){
		//should cast an exception
		return nullptr;
	}

	ArrayList* list = new ArrayList(mElementType);
	if(begin >= mSize){
		return list;
	}

	for(size_t index = begin; index < end && index < mSize; index++){
		list->add(mElements[index]);
	}

	return list;
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

type_t ArrayList::type(){
	return CLASS_SERIAL;
}

ArrayList::ArrayListIterator::ArrayListIterator(ArrayList *list)
		: mList(list) {
	mCurrent = -1;
	mList->mModified = false;
}

type_t ArrayList::ArrayListIterator::type() {
	return CLASS_SERIAL;
}

bool ArrayList::ArrayListIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterator::instanceof(type);
}

bool ArrayList::ArrayListIterator::hasNext() {
	if (mList->mModified) {

	}

	return mCurrent < mList->mSize - 1;
}

Reference ArrayList::ArrayListIterator::next() {
	if (mList->mModified) {

	}

	return mList->mElements[++mCurrent];
}

bool ArrayList::ArrayListIterator::hasPrevious(){
	if(mList->mModified){

	}

	return mCurrent > 0;
}

Reference ArrayList::ArrayListIterator::previous(){
	if(mList-mModified){

	}

	return mList->mElements[--mCurrent];
}

bool ArrayList::ArrayListIterator::remove() {
	if (mList->mModified) {

	}

	if (mList->mSize == 0) {
		return false;
	}

	if(mCurrent < 0){
		return false;
	}

	for (size_t index = mCurrent; index < mList->mSize - 1; index++) {
		mList->mElements[index] = mList->mElements[index + 1];
	}
	(mList->mSize)--;
	mList->mElements[mList->mSize] = Reference();

	return true;
}

bool ArrayList::ArrayListIterator::insert(Reference ref) {
	if (mList->mModified) {
		//cast an exception
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(mList->mElementType)) {
		return false;
	}

	if (mList->mSize == mList->mCapacity) {
		mList->expand();
	}

	for (size_t index = mList->mSize; index > mCurrent + 1; index--) {
		mList->mElements[index] = mList->mElements[index - 1];
	}
	mList->mElements[mCurrent + 1] = ref;
	(mList->mSize)++;

	return true;
}

} /* namespace utils */
} /* namespace tl */
