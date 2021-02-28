/*
 * Byte.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include "Byte.h"
#include "String.h"
#include <stdio.h>

namespace tl {
namespace lang {

Byte::Byte(byte value) {
	// TODO Auto-generated constructor stub
	mValue = value;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Byte::~Byte() {
	// TODO Auto-generated destructor stub
}

tlint Byte::intValue() {
	return (tlint)mValue;
}

short Byte::shortValue() {
	return mValue;
}

byte Byte::byteValue() {
	return mValue;
}

tlint64 Byte::longValue() {
	return mValue;
}

float Byte::floatValue() {
	return (float)mValue;
}

double Byte::doubleValue() {
	return (double)mValue;
}

Reference Byte::toString() {
	char str[10];
	sprintf(str, "%d", mValue);
	return Reference(new String(str));
}

tlint Byte::compareTo(Reference ref) {
	if (ref.isNull()) {
		return mValue;
	}

	if (!ref.getEntity()->instanceof(Number::type())) {
		//cast an exception
	}

	Number *n = dynamic_cast<Number*>(ref.getEntity());
	return mValue - n->byteValue();
}

type_t Byte::type() {
	return CLASS_SERIAL;
}

bool Byte::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
