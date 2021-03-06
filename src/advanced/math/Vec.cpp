/*
 * Vec.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <tl/advanced/math/Vec.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::String;
using lang::IndexOutOfBoundsException;

Vec::Vec(float x) {
	// TODO Auto-generated constructor stub
	mValue = { x };

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec::Vec(vec initValue) {
	mValue = initValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec::~Vec() {
	// TODO Auto-generated destructor stub
}

tlint Vec::size() {
	return COMPONENT_COUNT;
}

vec Vec::values() {
	return mValue;
}

VectorType Vec::vectorType() {
	return VECTOR_TYPE_VALUE;
}

void Vec::set(vec v) {
	mValue = v;
}

void Vec::set(tlint index, float v) {
	switch (index) {
	case 0:
		mValue.x = v;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}
}

float Vec::get(tlint index) {
	float value;
	switch (index) {
	case 0:
		value = mValue.x;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return value;
}

type_t Vec::type() {
	return CLASS_SERIAL;
}

tlint Vec::maxIndex() {
	return MAX_INDEX;
}

tlint Vec::minIndex() {
	return MIN_INDEX;
}

bool Vec::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Vector::instanceof(type);
}

Reference Vec::toString() {
	char str[60];
	sprintf(str, "[%f]", mValue.x);
	return Reference(new String(str));
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
