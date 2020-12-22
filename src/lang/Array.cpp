/*
 * Array.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#include "Array.h"

namespace tl {
namespace lang {

Array::Array(type_t element_type, size_t size)
		: mSize(size), mElementType(element_type) {
	// TODO Auto-generated constructor stub
	if(size > MAX_SIZE){
		//case an exception
	}

	mElements = new Reference[mSize];

	mHashCode = genHashCode(CLASS_SERIAL);
}

Array::~Array() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

Reference Array::get(size_t index) {
	if (index < 0 || index >= mSize) {
		//should cast an exception
	}

	return mElements[index];
}

bool Array::set(Reference ref, size_t index) {
	if (!ref.getEntity()->instanceof(mElementType)) {
		return false;
		//or cast an exception
	}

	if (index < 0 || index >= mSize) {
		return false;
		//or cast an exception
	}

	mElements[index] = ref;
	return true;
}

size_t Array::size() {
	return mSize;
}

String* Array::toString(){
	String** elementStrings = new String*[mSize];
	size_t* length = new size_t[mSize];
	for(int index = 0; index < mSize; index++){
		if(mElements[index].isNull()){
			continue;
		}

		elementStrings[index] = mElements[index].getEntity()->toString();
	}
}

type_t Array::type() {
	return CLASS_SERIAL;
}

bool Array::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
