/*
 * Vec4.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <tl/advanced/math/Vec4.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::String;
using lang::IndexOutOfBoundsException;

Vec4::Vec4(float x, float y, float z, float w) {
	// TODO Auto-generated constructor stub
	mValue.x = x;
	mValue.y = y;
	mValue.z = z;
	mValue.w = w;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec4::Vec4(vec4 initValue) {
	mValue = initValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

tlint Vec4::size() {
	return COMPONENT_COUNT;
}

float Vec4::get(tlint index) {
	float value;
	switch (index) {
	case 0:
		value = mValue.x;
		break;
	case 1:
		value = mValue.y;
		break;
	case 2:
		value = mValue.z;
		break;
	case 3:
		value = mValue.w;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return value;
}

void Vec4::set(vec4 value) {
	mValue = value;
}

void Vec4::set(tlint index, float value) {
	switch (index) {
	case 0:
		mValue.x = value;
		break;
	case 1:
		mValue.y = value;
		break;
	case 2:
		mValue.z = value;
		break;
	case 3:
		mValue.w = value;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}
}

vec4 Vec4::values() {
	return mValue;
}

VectorType Vec4::vectorType() {
	return VECTOR_TYPE_VALUE;
}

tlint Vec4::maxIndex() {
	return MAX_INDEX;
}

tlint Vec4::minIndex() {
	return MIN_INDEX;
}

Reference Vec4::toString() {
	char str[60];
	sprintf(str, "[%f, %f, %f, %f]", mValue.x, mValue.y, mValue.z, mValue.w);
	return Reference(new String(str));
}

Vec4::~Vec4() {
	// TODO Auto-generated destructor stub
}

type_t Vec4::type() {
	return CLASS_SERIAL;
}

bool Vec4::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Vector::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
