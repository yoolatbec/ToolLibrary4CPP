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

void ArrayList::boundCheck(tlint position){
	if(position >= mSize || position < 0){
		//cast IndexOutOfBoundException exception
	}
}

tlint ArrayList::argumentCheck(Reference ref, type_t type){
	if(ref.isNull()){
		return 0;
	}

	if(!ref.getEntity()->instanceof(type)){
		return -1;
	}

	return 1;
}

void ArrayList::add0(Reference ref){
	if(mSize == mCapacity){
		expand();
	}

	mElements[mSize] = ref;
	mSize++;
	mModified = true;
}

void ArrayList::insert0(tlint position, Reference ref){
	if(mSize == mCapacity){
		expand();
	}

	for(tlint index = mSize; index > position; index--){
		mElements[index] = mElements[index - 1];
	}

	mElements[position] = ref;
	mSize++;
	mModified = true;
}

tlint ArrayList::indexOf0(Reference ref){
	for(tlint index = 0; index < mSize; index++){
		if(mElements[index].equals(ref)){
			return index;
		}
	}

	return -1;
}

tlint ArrayList::lastIndexOf0(Reference ref){
	for(tlint index = mSize - 1; index >= 0; index--){
		if(mElements[index].equals(ref)){
			return index;
		}
	}

	return -1;
}

Reference ArrayList::set0(tlint position, Reference ref){
	Reference oldElement = mElements[position];
	if(oldElement.equals(ref)){
		return ref;
	}

	mElements[position] = ref;
	mModified = true;
	return oldElement;
}

void ArrayList::remove0(tlint position){
	mSize--;
	for(tlint index = position; index < mSize; index++){
		mElements[index] = mElements[index + 1];
	}
	mElements[mSize] = Reference();
	mModified = true;
}

bool ArrayList::add(Reference value) {
	switch(argumentCheck(value, mElementType)){
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
	switch(argumentCheck(ref, Collection::type())){
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

	if(collection->mSize <= 0){
		return false;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(collection->iterator().getEntity());
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add0(ref);
	}
	return true;
}

bool ArrayList::contains(Reference ref) {
	switch(argumentCheck(ref, mElementType)){
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		// do nothing
	}

	return indexOf0(ref) >= 0;
}

bool ArrayList::containsAll(Reference ref){
	switch(argumentCheck(ref, Collection::type())){
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
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
		result = result && (indexOf0(obj) >= 0);
		if(!result){
			return result;
		}
	}

	return result;
}

bool ArrayList::insert(tlint position, Reference ref) {
	switch(argumentCheck(ref, mElementType)){
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

	switch(argumentCheck(ref, Collection::type())){
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
	for(index = mSize - 1; index >= position; index--){
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

tlint ArrayList::lastIndexOf(Reference ref){
	switch(argumentCheck(ref, mElementType)){
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
	if(empty()){
		return false;
	}

	switch(argumentCheck(ref, mElementType)){
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	tlint index = indexOf0(ref);
	if(index >= 0){
		remove0(index);
	}

	return index >= 0;
}

bool ArrayList::remove(tlint position) {
	if(empty()){
		return false;
	}

	boundCheck(position);

	remove0(position);

	return true;
}

bool ArrayList::removeLast(Reference ref){
	switch(argumentCheck(ref, mElementType)){
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	tlint index = lastIndexOf0(ref);
	if(index >= 0){
		remove0(index);
	}

	return (index >= 0);
}

bool ArrayList::removeAll(Reference ref) {
	if(empty()){
		return false;
	}

	switch(argumentCheck(ref, Collection::type())){
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


	Iterator *iterator = dynamic_cast<Iterator*>(collection->iterator().getEntity());
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
	switch(argumentCheck(ref, mElementType)){
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

Reference ArrayList::sublist(tlint begin, tlint end){
	if(end < begin){
		//should cast an exception
		return Reference();
	}

	boundCheck(begin);
	boundCheck(end);

	ArrayList* list = new ArrayList(mElementType);

	for(tlint index = begin; index < end; index++){
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
	if(mCapacity == MAX_CAPACITY){
		//cast SizeOutOfLimitException
	}

	tlint newCapacity;
	if(mCapacity > MAX_CAPACITY / 2){
		newCapacity = MAX_CAPACITY;
	} else {
		newCapacity = mCapacity * 2;
	}

	Reference* newElements = new Reference[newCapacity];
	for(tlint index = 0; index < mSize; index++){
		newElements[index] = mElements[index];
	}

	delete [] mElements;
	mElements = newElements;
	mCapacity = newCapacity;
}

void ArrayList::trim(){
	if(mSize == mCapacity){
		return;
	}

	Reference* newElements = new Reference[mSize];
	for(tlint index = 0; index < mSize; index++){
		newElements[index] = mElements[index];
	}

	delete [] mElements;
	mElements = newElements;
	mCapacity = mSize;
	mModified = true;
}

void ArrayList::ensureCapacity(tlint capacity){
	if(capacity <= mCapacity){
		return;
	}

	Reference* newElements = new Reference[capacity];
	for(tlint index = 0; index < mSize; index++){
		newElements[index] = mElements[index];
	}

	delete[] mElements;
	mElements = newElements;
	mModified = true;
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
