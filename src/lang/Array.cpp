/*
 * Array.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#include "Array.h"

namespace tl {
namespace lang {

Array::Array(size_t size, hash_t element_type)
		: mSize(size), mElementType(element_type) {
	// TODO Auto-generated constructor stub
	mElements = new Reference[mSize];
}

Array::~Array() {
	// TODO Auto-generated destructor stub
	delete [] mElements;
}

Reference Array::get(size_t index) const{
	if(index < 0 || index >= mSize){

	}

	return mElements[index];
}

bool Array::set(const Reference& ref, size_t index){
	if(ref.isNull()){
		return false;
	}

	if(!ref.instanceof(mElementType)){
		return false;
	}

	if(index < 0 || index >= mSize){
		return false;
	}

	mElements[index] = ref;
}

size_t Array::size() const{
	return mSize;
}

hash_t Array::getType(){
	return CLASS_HASH;
}

bool Array::instanceof(hash_t type) const{
	return (mHash & CLASS_MASK == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
