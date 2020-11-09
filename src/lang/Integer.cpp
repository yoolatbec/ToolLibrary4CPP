/*
 * Integer.cpp
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#include "Integer.h"
#include <cstdio>

namespace tl {
namespace lang {

Integer::Integer(tlint value) {
	// TODO Auto-generated constructor stub
	mValue = value;
	mHash = genHash();
}

Integer::Integer(const Reference &ref) {
	if (ref.instanceof(String::getType())) {
		String *str = (String*)ref.getEntity();
		const char *characters = str->bytes();
		int value;
		if (sscanf(characters, "%d", &value) != 1) {
			mValue = 0;
		} else {
			mValue = value;
		}
	} else if(ref.instanceof(Integer::getType())){
		Integer* another = ref.getEntity();
		mValue = another->mValue;
	} else {
		mValue = 0;
	}

	mHash = genHash();
}

byte Integer::byteValue() const {
	return (byte)mValue;
}

word Integer::shortValue() const {
	return (word)mValue;
}

tlint Integer::intValue() const {
	return mValue;
}

tlint64 Integer::longValue() const {
	return (tlint64)mValue;
}

double Integer::doubleValue() const {
	return (double)mValue;
}

float Integer::floatValue() const {
	return (float)mValue;
}

tlint Integer::compareTo(const Reference &ref) const {
	if(ref.instanceof(Integer::getType())){
		Integer* another = ref.getEntity();
		return mValue - another->mValue;
	}
	return mValue;
}

tlint Integer::getBitAt(tlint position) const {
	position %= 32;

	tlint bits = mValue;
	bits << position;
	bits >> 31;

	return bits;
}

tlint Integer::larger(tlint a, tlint b) {
	return a > b ? a : b;
}

tlint Integer::smaller(tlint a, tlint b) {
	return a > b ? b : a;
}

String Integer::toString() const {
	char str[20];
	sprintf(str, "%d", mValue);
	return String(str);
}

bool Integer::instanceof(hash_t type) const {
	return (mHash & CLASS_MASK == type) || Number::instanceof(type);
}

hash_t Integer::getType() {
	return CLASS_HASH;
}

hash_t Integer::genHash(){
	return CLASS_HASH + mValue;
}

} /* namespace lang */
} /* namespace tl */
