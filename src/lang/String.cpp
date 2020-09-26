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

String::String(const char *str) {
	mLength = strlen(str);
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, str, mLength);
}

String::String(size_t length, char c) {
	mLength = length;
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	memset(mStr, c, mLength);
}

String::String(const String &other) {
	// TODO Auto-generated constructor stub
	mLength = other.mLength;
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, other.mStr, mLength);
}

String::~String() {
	// TODO Auto-generated destructor stub
	delete[] mStr;
}

String String::append(char c) const {
	char *str = new char[mLength + 2];
	strncpy(str, mStr, mLength);
	str[mLength + 1] = c;
	str[mLength + 2] = '\0';
	String nstr(str);
	delete[] str;
	return nstr;
}

String String::append(const String &other) const {
	char *str = new char[mLength + other.mLength + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, other.mStr, other.mLength);
	str[mLength + other.mLength] = '\0';
	String nstr(str);
	delete[] str;
	return nstr;
}

String String::append(int i) const{

}

} /* namespace lang */
} /* namespace tl */
