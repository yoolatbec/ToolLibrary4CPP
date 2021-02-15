/*
 * Vec.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#include "Vec.h"
#include "../../lang/String.h"
#include <stdio.h>

namespace tl {
namespace advanced {
namespace math {

using lang::String;

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
		break;
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
		break;
	}

	return value;
}

type_t Vec::type() {
	return CLASS_SERIAL;
}

bool Vec::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Vector::instanceof(type);
}

Reference Vec::toString() {
	char str[60];
	sprintf(str, "[%f]");
	return Reference(new String(str));
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
