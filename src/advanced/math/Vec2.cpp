/*
 * Vec2.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <tl/advanced/math/Vec2.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::IndexOutOfBoundsException;
using lang::String;

Vec2::Vec2(float x, float y) {
	// TODO Auto-generated constructor stub
	mValue.x = x;
	mValue.y = y;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec2::Vec2(vec2 initValue) {
	mValue = initValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec2::~Vec2() {
	// TODO Auto-generated destructor stub
}

float Vec2::get(tlint index) {
	float value;
	switch (index) {
	case 0:
		value = mValue.x;
		break;
	case 1:
		value = mValue.y;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return value;
}

vec2 Vec2::values() {
	return mValue;
}

VectorType Vec2::vectorType() {
	return VECTOR_TYPE_VALUE;
}

tlint Vec2::size() {
	return COMPONENT_COUNT;
}

void Vec2::set(vec2 v) {
	mValue = v;
}

void Vec2::set(tlint index, float v) {
	switch (index) {
	case 0:
		mValue.x = v;
		break;
	case 1:
		mValue.y = v;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}
}

tlint Vec2::maxIndex() {
	return MAX_INDEX;
}

tlint Vec2::minIndex() {
	return MIN_INDEX;
}

type_t Vec2::type() {
	return CLASS_SERIAL;
}

bool Vec2::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Vector::instanceof(type);
}

Reference Vec2::toString() {
	char str[60];
	sprintf(str, "[%f, %f]", mValue.x, mValue.y);
	return Reference(new String(str));
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
