/*
 * ArrayList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "ArrayList.h"

namespace tl {
namespace utils {

ArrayList::ArrayList(hash_t type)
		: List(type) {
	mElements = new Reference[mCapacity];
}

ArrayList::ArrayList(hash_t type, size_t reserved)
		: List(type, reserved) {
	mElements = new Reference[mCapacity];
}

ArrayList::~ArrayList() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

bool ArrayList::add(const Reference& value){
	if(value.isNull()){
		return false;
	}

	for(int i = 0; i < mSize; i++){
		if(mElements[i].equals(value)){
			return false;
		}
	}

	if(mSize == mCapacity){
		expand();
	}

	mElements[mSize] = value;
	mSize++;
	mModified = true;
	return true;
}

void ArrayList::addAll(const List* anotherList){
	if(anotherList == nullptr){
		return;
	}

	while(mCapacity - mSize <= anotherList->mSize){
		expand();
	}

	ConstantIterator* iterator = anotherList->constIterator();
	while(iterator->hasNext()){
		add(iterator->next());
	}
}

bool ArrayList::instanceof(hash_t type) const{
	return (mHash & CLASS_MASK == type) || List::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
