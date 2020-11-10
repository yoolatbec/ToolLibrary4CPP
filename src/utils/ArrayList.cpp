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

	if(!value.instanceof(mElementType)){
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

bool ArrayList::addAll(const Reference& ref){
	if(!ref.instanceof(Collection::getType())){
		return false;
	}

	Collection* collection = (Collection*)ref.getEntity();
	if(collection->getElementType() != mElementType){
		return false;
	}

	ConstantIterator* iterator = collection->constantIterator();
	while(iterator->hasNext()){
		Reference ref = iterator->next();
		add(ref);
	}
	return true;
}

bool ArrayList::contains(const Reference& ref) const{
	if(ref.isNull()){
		return false;
	}

	if(!ref.instanceof(mElementType)){
		return false;
	}

	if(mSize == 0){
		return false;
	}

	for(tlint index = 0; index < mSize; index++){
		if(mElements[index].equals(ref)){
			return true;
		}
	}
	return false;
}

bool ArrayList::insert(const Reference& ref, size_t position){
	if(ref.isNull()){
		return false;
	}

	if(!ref.instanceof(mElementType)){
		return false;
	}

	if(mSize < position){
		return false;
	}

	if(mSize == position){
		return add(ref);
	}

	if(contains(ref)){
		return false;
	}

	if(mSize == mCapacity){
		expand();
	}

	for(tlint index = mSize; index > position; index--){
		mElements[index] = mElements[index - 1];
	}
	mElements[position] = ref;
	return true;
}

bool ArrayList::instanceof(hash_t type) const{
	return (mHash & CLASS_MASK == type) || List::instanceof(type);
}

hash_t ArrayList::getType(){
	return CLASS_HASH;
}

} /* namespace utils */
} /* namespace tl */
