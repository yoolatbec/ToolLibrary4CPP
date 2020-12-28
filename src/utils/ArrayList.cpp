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
	if (collection->elementType() != mElementType) {
		return false;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(collection->iterator().getEntity());
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

	for (tlint index = 0; index < mSize; index++) {
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
	if(collection->elementType() != mElementType){
		//should cast an exception
		return false;
	}

	bool result = true;
	Iterator* iterator = dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while(iterator->hasNext()){
		Reference obj = iterator->next();
		result = result && contains(obj);
		if(!result){
			return result;
		}
	}

	return result;
}

bool ArrayList::insert(Reference ref, tlint position) {
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

	for (tlint index = mSize; index > position; index--) {
		mElements[index] = mElements[index - 1];
	}
	mElements[position] = ref;
	mSize++;
	mModified = true;
	return true;
}

bool ArrayList::insertAll(Reference ref, tlint position) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		return false;
	}

	if (position < 0 || position > mSize) {
		return false;
	}

	if (position == mSize) {
		return addAll(ref);
	}

	tlint size = collection->size();
	while (mCapacity <= size + mSize) {
		expand();
	}

	tlint index;
	for (index = position; index < mSize; index++) {
		mElements[index + size] = mElements[index];
	}

	index = position;
	Iterator *iterator = dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		mElements[index] = iterator->next();
		index++;
	}

	mSize += size;
	mModified = true;
	return true;
}

tlint ArrayList::indexOf(Reference ref){
	for(tlint index = 0; index < mSize; index++){
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
	tlint index = 0;
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

bool ArrayList::remove(tlint position) {
	if(empty()){
		return false;
	}

	if (position < 0 || position >= mSize) {
		return false;
	}

	for (tlint index = position; index < mSize - 1; index++) {
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
	if (collection->elementType() != mElementType) {
		return false;
	}


	Iterator *iterator = dynamic_cast<Iterator*>(collection->iterator().getEntity());
	bool removed = false;
	while (iterator->hasNext()) {
		removed = remove(iterator->next()) || removed;
	}
	return removed;
}

Reference ArrayList::get(tlint position) {
	if (position < 0 || position >= mSize) {
		return Reference();
	}

	return mElements[position];
}

bool ArrayList::set(tlint position, Reference ref) {
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

Reference ArrayList::toArray() {
	Array *arr = new Array(mElementType, mSize);
	for (tlint index = 0; index < mSize; index++) {
		arr->set(mElements[index], index);
	}
	return Reference(arr);
}

Reference ArrayList::sublist(tlint begin, tlint end){
	if(end < begin){
		//should cast an exception
		return Reference();
	}

	ArrayList* list = new ArrayList(mElementType);
	if(begin >= mSize){
		return Reference(list);
	}

	for(tlint index = begin; index < end && index < mSize; index++){
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

void ArrayList::expand(){
	tlint newCapacity = mCapacity * 2;
	Reference* newElements = new Reference[newCapacity];
	for(tlint index = 0; index < mSize; index++){
		newElements[index] = mElements[index];
	}

	delete [] mElements;
	mElements = newElements;
	mCapacity = newCapacity;
}

Reference ArrayList::iterator() {
	return Reference(new ArrayListIterator(this));
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
	if(mList->mModified){

	}

	return mList->mElements[--mCurrent];
}

void ArrayList::ArrayListIterator::remove() {
	if (mList->mModified) {

	}

	if (mList->mSize == 0) {
		return;
	}

	if(mCurrent < 0){
		return;
	}

	for (tlint index = mCurrent; index < mList->mSize - 1; index++) {
		mList->mElements[index] = mList->mElements[index + 1];
	}
	(mList->mSize)--;
	mList->mElements[mList->mSize] = Reference();
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

	for (tlint index = mList->mSize; index > mCurrent + 1; index--) {
		mList->mElements[index] = mList->mElements[index - 1];
	}
	mList->mElements[mCurrent + 1] = ref;
	(mList->mSize)++;

	return true;
}

} /* namespace utils */
} /* namespace tl */
