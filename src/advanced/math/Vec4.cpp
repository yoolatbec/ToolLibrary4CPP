/*
 * Vec4.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: yoolatbec
 */

#include "Vec4.h"
#include "../../lang/String.h"
#include <stdio.h>

namespace tl {
namespace advanced {
namespace math {

using lang::String;

Vec4::Vec4(float x, float y, float z, float w) {
	// TODO Auto-generated constructor stub
	mValue.x = x;
	mValue.y = y;
	mValue.z = z;
	mValue.w = w;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec4::Vec4(vec4 initValue){
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
	}
}

vec4 Vec4::values() {
	return mValue;
}

Reference Vec4::toString() {
	char str[60];
	sprintf(str, "[%f, %f, %f, %f]");
	return Reference(new String(str));
}

Vec4::~Vec4() {
	// TODO Auto-generated destructor stub
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
