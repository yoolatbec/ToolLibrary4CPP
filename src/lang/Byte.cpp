/*
 * Byte.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include <lang/Byte.h>
#include <lang/IllegalArgumentTypeException.h>
#include <lang/String.h>
#include <stdio.h>

namespace tl {
namespace lang {

Byte::Byte(byte value)
	: mValue(value) {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

Byte::~Byte() {
	// TODO Auto-generated destructor stub
}

hash_t Byte::genHashCode(type_t type) {
	return (type << 32) | mValue;
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
	dismissNull(ref);
	argumentTypeCheck(ref, Byte::type());

	Number *n = dynamic_cast<Number*>(ref.getEntity());
	return mValue - n->byteValue();
}

byte Byte::parseByte(Reference ref) {
	if(ref.isNull()){
		return 0;
	}

	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		const char *s = str->toCharArray();

		tlint v;
		if (sscanf(s, "%d", &v) == 0) {
			//cast an exception
		}

		return (byte)v;
	}

	if (ref.getEntity()->instanceof(Number::type())) {
		Number *num = dynamic_cast<Number*>(ref.getEntity());
		return num->byteValue();
	}

	throw IllegalArgumentTypeException();
}

Reference Byte::valueOf(byte value) {
	return Reference(new Byte(value));
}

Reference Byte::valueOf(Reference ref) {
	return valueOf(parseByte(ref));
}

tlint Byte::compare(byte b1, byte b2) {
	return b1 - b2;
}

type_t Byte::type() {
	return CLASS_SERIAL;
}

bool Byte::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
