/*
 * Array.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Array.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>
#include <tl/lang/StringBuilder.h>

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

void Array::indexBoundCheck(tlint index) {
	if (index < 0 || index >= mSize) {
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
	Reference ref = Reference(new StringBuilder());
	StringBuilder *builder = dynamic_cast<StringBuilder*>(ref.getEntity());

	builder->append('[');

	for (tlint index = 0; index < mSize; index++) {
		if (mElements[index].isNull()) {
			continue;
		}

		Object *obj = dynamic_cast<Object*>(mElements[index].getEntity());
		builder->append(obj->toString());
		builder->append(' ');
	}

	builder->append(']');
	return builder->toString();
}

type_t Array::type() {
	return CLASS_SERIAL;
}

bool Array::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
