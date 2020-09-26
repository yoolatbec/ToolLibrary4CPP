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
}

Integer::Integer(const String &str) {
	const char* characters = str.getCharacters();
	int value;
	if(sscanf(characters, "%d", &value) != 1){

	}
	mValue = value;
}

byte Integer::byteValue() const{
	return (byte)mValue;
}

word Integer::shortValue() const{
	return (word)mValue;
}

tlint Integer::intValue() const{
	return mValue;
}

tlint64 Integer::longValue() const{
	return (tlint64)mValue;
}

double Integer::doubleValue() const{
	return (double)mValue;
}

float Integer::floatValue() const{
	return (float)mValue;
}

bool Integer::compareTo(const Integer& other) const{
	return mValue == other.mValue;
}

tlint Integer::getBitAt(tlint position) const{
	position %= 32;

	tlint bits = mValue;
	bits << position;
	bits >> 31;

	return bits;
}

tlint Integer::max(tlint a, tlint b){
	return a > b ? a : b;
}

tlint Integer::min(tlint a, tlint b){
	return a > b ? b : a;
}

String Integer::toString() const{
	char str[20];
	sprintf(str, "%d", mValue);
	return String(str);
}

} /* namespace lang */
} /* namespace tl */
