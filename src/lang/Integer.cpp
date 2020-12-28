/*
 * Integer.cpp
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#include "Integer.h"
#include "String.h"
#include <cstdio>

namespace tl {
namespace lang {

Integer::Integer(tlint value) {
	// TODO Auto-generated ructor stub
	mValue = value;
	mHashCode = genHashCode();
}

Integer::Integer(Reference ref) {
	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		char *characters = str->bytes();
		int value;
		if (sscanf(characters, "%d", &value) != 1) {
			mValue = 0;
		} else {
			mValue = value;
		}
	} else if (ref.getEntity()->instanceof(Integer::type())) {
		Integer *another = dynamic_cast<Integer*>(ref.getEntity());
		mValue = another->mValue;
	} else {
		mValue = 0;
	}

	mHashCode = genHashCode();
}

byte Integer::byteValue() {
	return (byte)mValue;
}

word Integer::shortValue() {
	return (word)mValue;
}

tlint Integer::intValue() {
	return mValue;
}

tlint64 Integer::longValue() {
	return (tlint64)mValue;
}

double Integer::doubleValue() {
	return (double)mValue;
}

float Integer::floatValue() {
	return (float)mValue;
}

tlint Integer::compareTo(Reference ref) {
	if (ref.getEntity()->instanceof(Number::type())) {
		Number *another = dynamic_cast<Number*>(ref.getEntity());
		return another->intValue() = mValue;
	}
	return mValue;
}

tlint Integer::getBitAt(tlint position) {
	position %= 32;

	tlint bits = mValue;
	bits = bits << position;
	bits = bits >> 31;

	return bits;
}

tlint Integer::larger(tlint a, tlint b) {
	return a > b ? a : b;
}

tlint Integer::smaller(tlint a, tlint b) {
	return a > b ? b : a;
}

Reference Integer::toString() {
	char str[20];
	sprintf(str, "%d", mValue);
	return Reference(new String(str));
}

bool Integer::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

type_t Integer::type() {
	return CLASS_SERIAL;
}

hash_t Integer::genHashCode() {
	return CLASS_SERIAL << 32 + mValue;
}


} /* namespace lang */
} /* namespace tl */
