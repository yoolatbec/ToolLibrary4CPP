/*
 * Vec3.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/Vec3.h>
#include <lang/String.h>

#include <stdio.h>

namespace tl {
namespace advanced {
namespace math {

using lang::String;

Vec3::Vec3(float x, float y, float z) {
	// TODO Auto-generated constructor stub
	mValue.x = x;
	mValue.y = y;
	mValue.z = z;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec3::Vec3(vec3 initValue) {
	mValue = initValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec3::~Vec3() {
	// TODO Auto-generated destructor stub
}

float Vec3::get(tlint index) {
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
	default:
		//cast an exception
	}

	return value;
}

tlint Vec3::size() {
	return COMPONENT_COUNT;
}

vec3 Vec3::values() {
	return mValue;
}

VECTOR_TYPE Vec3::vectorType() {
	return VECTOR_TYPE_VALUE;
}

void Vec3::set(vec3 v) {
	mValue = v;
}

void Vec3::set(tlint index, float v) {
	switch (index) {
	case 0:
		mValue.x = v;
		break;
	case 1:
		mValue.y = v;
		break;
	case 2:
		mValue.z = v;
		break;
	default:
		//cast an exception
	}
}

Reference Vec3::toString() {
	char str[60];
	sprintf(str, "[%f, %f, %f]");
	return Reference(new String(str));
}

tlint Vec3::maxIndex() {
	return MAX_INDEX;
}

tlint Vec3::minIndex() {
	return MIN_INDEX;
}

type_t Vec3::type() {
	return CLASS_SERIAL;
}

bool Vec3::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Vector::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
