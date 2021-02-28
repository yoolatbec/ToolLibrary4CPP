/*
 * String.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "String.h"
#include <cstdio>
#include <cstring>

#include "../utils/ArrayList.h"

using tl::utils::ArrayList;

namespace tl {
namespace lang {

String::String() {
	// TODO Auto-generated ructor stub
	mStr = nullptr;
	mLength = 0;
	mHashCode = genHashCode();
}

String::String(const char *str) {
	mLength = strlen(str);
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, str, mLength);
	mHashCode = genHashCode();
}

String::String(size_t length, char c) {
	mLength = length;
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	memset(mStr, c, mLength);
	mHashCode = genHashCode();
}

String::String(Reference ref) {
	// TODO Auto-generated ructor stub
	if (ref.isNull()) {
		mStr = nullptr;
		mLength = 0;
	} else {
		String *other = ref.getEntity()->toString();
		const char *str = other->toCharArray();
		mLength = other->mLength;
		mStr = new byte[mLength + 1];
		strncpy(mStr, str, mLength);
		mStr[mLength] = '\0';
	}

//	if (ref.getEntity()->instanceof(String::type())) {
//		String *other = dynamic_cast<String*>(ref.getEntity());
//		mLength = other->mLength;
//		mStr = new char[mLength + 1];
//		mStr[mLength] = '\0';
//		strncpy(mStr, other->mStr, mLength);
//	} else {
//
//	}

	mHashCode = genHashCode();
}

String::~String() {
	// TODO Auto-generated destructor stub
	delete[] mStr;
}

Reference String::append(char c) {
	char *str = new char[mLength + 2];
	strncpy(str, mStr, mLength);
	str[mLength] = c;
	str[mLength + 1] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::append(byte c) {
	char *str = new char[mLength + 4];
	strncpy(str, mStr, mLength);
	sprintf(str + mLength, "%d", c);
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::append(Reference ref) {
	if (ref.isNull()) {
		return Reference(new String(mStr));
	}

	String *r_value;
	String *ref_str =
			dynamic_cast<String*>(ref.getEntity()->toString().getEntity());
	char *str = new char[mLength + ref_str->mLength + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, ref_str->toCharArray(), ref_str->mLength);
	str[mLength + ref_str->mLength] = '\0';
	r_value = new String(str);

//	if (ref.instanceof(String::type())) {
//		String *other = dynamic_cast<String*>(ref.getEntity());
//		char *str = new char[mLength + other->mLength + 1];
//		strncpy(str, mStr, mLength);
//		strncpy(str + mLength, other->mStr, other->mLength);
//		str[mLength + other->mLength] = '\0';
//		r_value = new String(str);
//		delete[] str;
//	} else {
//		Object *obj = ref.getEntity();
//		Reference str = Reference(obj->toString());
//		r_value = append(str);
//	}

	delete[] str;

	return Reference(r_value);
}

Reference String::append(tlint i) {
//	char ivalue[32];
//	ivalue[31] = '\0';
//	sprintf(ivalue, "%d", i);
//	byte *str = new byte[mLength + strlen(ivalue) + 1];
//	strncpy(str, mStr, mLength);
//	strncpy(str + mLength, ivalue, strlen(ivalue));
//	str[mLength + strlen(ivalue)] = '\0';
//	String *r_value = new String(str);
//	delete[] str;
//	return Reference(r_value);

	char *str = new char[mLength + 32];
	strncpy(str, mStr, mLength);
	sprintf(str + mLength, "%d", i);
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);

}

Reference String::append(double d) {
//	byte doubleValue[64];
//	doubleValue[63] = '\0';
//	sprintf(doubleValue, "%lf", d);
//	byte *str = new byte[mLength + strlen(doubleValue) + 1];
//	strncpy(str, mStr, mLength);
//	strncpy(str + mLength, doubleValue, strlen(doubleValue));
//	str[mLength + strlen(doubleValue)] = '\0';
//	String *r_value = new String(str);
//	delete[] str;
//	return Reference(r_value);

	char *str = new char[mLength + 32];
	strncpy(str, mStr, mLength);
	sprintf(str + mLength, "%f", d);
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

tlint String::charAt(size_t position) {
	if (position < 0 || position >= mLength) {
		return -1;
	}

	return mStr[position];
}

Reference String::substring(size_t length) {
	if (length <= 0) {
		//cast an exception
		return new String("");
	}

	if (length > mLength) {
		length = mLength;
	}

	char *str = new char[length + 1];
	strncpy(str, mStr, length);
	str[length] = '\0';

	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::substring(size_t start, size_t length) {
	if (start < 0) {
		//cast an exception
		start = 0;
	}

	if (start + length >= mLength) {
		length = mLength - start - 1;
	}

	if (length <= 0) {
		return new String("");
	}

	char *str = new char[length + 1];
	strncpy(str, mStr + start, length);
	str[length] = '\0';

	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

const byte* String::bytes() {
	return mStr;
}

tlint String::compareTo(Reference ref) {
	if (ref.getEntity()->instanceof(String::type())) {
		String *other = dynamic_cast<String*>(ref.getEntity());
		return strcmp(other->mStr, mStr);
	}

	return 0;
}

Reference String::split(byte b) {
	ArrayList *list = new ArrayList(String::type());

	char token[2]
		{ 0 };
	token[0] = b;
	char *str = strtok(mStr, token);
	while (str != nullptr) {
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list->toArray();
}

Reference String::split(Reference ref) {
	if (ref.isNull()) {
		return new ArrayList(String::type());
	}

	if (!ref.getEntity()->instanceof(String::type())) {
		return new ArrayList(String::type());
	}

	ArrayList *list = new ArrayList(String::type());

	char *token = dynamic_cast<String*>(ref.getEntity())->mStr;
	char *str = strtok(mStr, token);
	while (str != nullptr) {
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list->toArray();
}

const char* String::toCharArray() {
	return mStr;
}

bool String::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Comparable::instanceof(type);
}

hash_t String::genHashCode() {
	hash_t hash = 5381;
	for (tlint index = 0; index < mLength; index++) {
		hash = ((hash << 5) + hash) + mStr[index];
	}

	return (hash ^ (hash >> 32)) | CLASS_SERIAL << 32;
}

type_t String::type() {
	return CLASS_SERIAL;
}

Reference String::toString() {
	return Reference(this);
}

} /* namespace lang */
} /* namespace tl */
