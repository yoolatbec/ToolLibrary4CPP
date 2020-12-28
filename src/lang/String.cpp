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

String::String(const byte *str) {
	mLength = strlen(str);
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, str, mLength);
	mHashCode = genHashCode();
}

String::String(size_t length, byte c) {
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
		const byte *str = other->bytes();
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

Reference String::append(byte c) {
	byte *str = new byte[mLength + 2];
	strncpy(str, mStr, mLength);
	str[mLength + 1] = c;
	str[mLength + 2] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::append(Reference ref) {
	if (ref.isNull()) {
		return Reference(new String(mStr));
	}

	String *r_value;
	String *ref_str = ref.getEntity()->toString();
	byte *str = new byte[mLength + ref_str->mLength + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, ref_str->bytes(), ref_str->mLength);
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
	byte ivalue[32];
	ivalue[31] = '\0';
	sprintf(ivalue, "%d", i);
	byte *str = new byte[mLength + strlen(ivalue) + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, ivalue, strlen(ivalue));
	str[mLength + strlen(ivalue)] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::append(double d) {
	byte doubleValue[64];
	doubleValue[63] = '\0';
	sprintf(doubleValue, "%lf", d);
	byte *str = new byte[mLength + strlen(doubleValue) + 1];
	strncpy(str, mStr, mLength);
	strncpy(str + mLength, doubleValue, strlen(doubleValue));
	str[mLength + strlen(doubleValue)] = '\0';
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
	return Reference(r_value);
}

Reference String::substring(size_t start, size_t length) {
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
	return Reference(r_value);
}

const byte* String::bytes() {
	return mStr;
}

tlint String::compareTo(Reference ref) {
	if (ref.getEntity()->instanceof(String::type())) {
		String* other = dynamic_cast<String*>(ref.getEntity());
		return strcmp(other->mStr, mStr);
	}

	return 0;
}

Reference String::split(byte b) {
	ArrayList *list = new ArrayList(String::type());

	char token[2]
		{ 0 };
	token[0] = b;
	byte *str = strtok(mStr, token);
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

	byte *token = dynamic_cast<String*>(ref.getEntity())->mStr;
	byte *str = strtok(mStr, token);
	while (str != nullptr) {
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list->toArray();
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
