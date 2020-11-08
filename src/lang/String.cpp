/*
 * String.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "String.h"
#include "cstdio"
#include "cstring"

namespace tl {
namespace lang {

String::String() {
	// TODO Auto-generated constructor stub
	mStr = nullptr;
	mLength = 0;
}

String::String(const byte *str) {
	mLength = strlen(str);
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, str, mLength);
}

String::String(size_t length, byte c) {
	mLength = length;
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	memset(mStr, c, mLength);
}

String::String(const String *other) {
	// TODO Auto-generated constructor stub
	mLength = other->mLength;
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, other->mStr, mLength);
}

String::~String() {
	// TODO Auto-generated destructor stub
	delete[] mStr;
}

String* String::append(byte c) const {
	byte *str = new byte[mLength + 2];
	strncpy(str, mStr, mLength);
	str[mLength + 1] = c;
	str[mLength + 2] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return r_value;
}

String* String::append(const String *other) const {
	char *str = new char[mLength + other->mLength + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, other->mStr, other->mLength);
	str[mLength + other->mLength] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return r_value;
}

String* String::append(tlint i) const {
	byte ivalue[32];
	sprintf(ivalue, "%d", i);
	byte *str = new byte[mLength + strlen(ivalue) + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, ivalue, strlen(ivalue));
	str[mLength + strlen(ivalue)] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return r_value;
}

String* String::append(double d) const {
	byte doubleValue[64];
	sprintf(doubleValue, "%lf", d);
	byte *str = new byte[mLength + strlen(doubleValue) + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, doubleValue, strlen(doubleValue));
	str[mLength + strlen(doubleValue)] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return r_value;
}

tlint String::charAt(size_t position) const {
	if (position < 0 || position >= mLength) {
		return -1;
	}

	return mStr[position];
}

String* String::substring(size_t length) const {
	if (length <= 0) {
		return new String("");
	}

	if (length > mLength) {
		length = mLength;
	}

	byte *str = new byte[length + 1];
	strncpy(str, mStr, length);
	str[length] = '\0';

	String *r_value = new String(str);
	delete[] str;
	return r_value;
}

String* String::substring(size_t start, size_t length) const {
	if (start < 0) {
		start = 0;
	}

	if (start + length > mLength) {
		length = mLength - start;
	}

	if (length <= 0) {
		return new String("");
	}

	byte *str = new byte[length + 1];
	strncpy(str, mStr + start, length);
	str[length] = '\0';

	String *r_value = new String(str);
	delete[] str;
	return r_value;
}

const byte* String::bytes() const{
	return mStr;
}

tlint String::compareTo(const String* another) const {
	return 0;
}

bool String::instanceof(hash_t type) const{
	return (mHash & CLASS_MASK == type) || Comparable::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
