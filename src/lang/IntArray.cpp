/*
 * IntArray.cpp
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#include "IntArray.h"
#include "String.h"
#include <cstring>

namespace tl {
namespace lang {

IntArray::IntArray(tlint size, tlint* initValues)
		: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new int[mSize];

	if(initValues != nullptr){
		for(tlint index = 0; index < mElements; index++){
			mElements[index] = initValues[index];
		}
	} else {
		memset(mElements, 0, mSize * sizeof(tlint));
	}
}

IntArray::~IntArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

Reference IntArray::newIntArray(tlint size, tlint* initValues){
	parameterCheck(size);

	return Reference(new IntArray(size, initValues));
}

tlint IntArray::get(tlint index){
	boundCheck(index);

	return mElements[index];
}

void IntArray::set(tlint index, tlint value){
	boundCheck(index);

	mElements[index] = value;
}

Reference IntArray::toString(){

}

Reference IntArray::clone(){
	return Reference(new IntArray(mSize, mElements));
}

type_t IntArray::type(){
	return CLASS_SERIAL;
}

bool IntArray::instanceof(type_t type){
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
