/*
 * Array.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#include <lang/Array.h>
#include <lang/IndexOutOfBoundsException.h>
#include <lang/String.h>

namespace tl {
namespace lang {

Array::Array(type_t element_type, tlint size)
	: mSize(size), mElementType(element_type) {
	// TODO Auto-generated constructor stub
	if (size > MAX_SIZE) {
		//case an exception
	}

	mElements = new Reference[mSize];

	mHashCode = genHashCode(CLASS_SERIAL);
}

Array::~Array() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

void Array::indexBoundCheck(tlint index){
	if(index < 0 || index >= mSize){
		throw IndexOutOfBoundsException();
	}
}

Reference Array::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

bool Array::set(tlint index, Reference ref) {
	argumentTypeCheck(ref, mElementType);
	indexBoundCheck(index);

	mElements[index] = ref;
	return true;
}

tlint Array::size() {
	return mSize;
}

Reference Array::toString() {
	//to edit
	Reference rtval = Reference(new String());

	for (int index = 0; index < mSize; index++) {
		if (mElements[index].isNull()) {
			continue;
		}

		String *str = dynamic_cast<String*>(rtval.getEntity());
		rtval= str->append(
			dynamic_cast<Object*>(mElements[index].getEntity())->toString());
	}

	return rtval;
}

type_t Array::type() {
	return CLASS_SERIAL;
}

bool Array::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
