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
	mHash = genHash();
}

String::String(const byte *str) {
	mLength = strlen(str);
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	strncpy(mStr, str, mLength);
	mHash = genHash();
}

String::String(size_t length, byte c) {
	mLength = length;
	mStr = new char[mLength + 1];
	mStr[mLength] = '\0';
	memset(mStr, c, mLength);
	mHash = genHash();
}

String::String(const Reference &ref) {
	// TODO Auto-generated constructor stub
	if(ref.isNull()){
		mStr = nullptr;
		mLength = 0;
	}

	if (ref.instanceof(String::getType())) {
		String *other = dynamic_cast<String*>(ref.getEntity());
		mLength = other->mLength;
		mStr = new char[mLength + 1];
		mStr[mLength] = '\0';
		strncpy(mStr, other->mStr, mLength);
	} else {

	}

	mHash = genHash();
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

String* String::append(const Reference &ref) const {
	if(ref.isNull()){
		return new String(mStr);
	}

	String* r_value;

	if (ref.instanceof(String::getType())) {
		String *other = dynamic_cast<String*>(ref.getEntity());
		char *str = new char[mLength + other->mLength + 1];
		strncpy(str, mStr, mLength);
		strncpy(str + mLength, other->mStr, other->mLength);
		str[mLength + other->mLength] = '\0';
		r_value = new String(str);
		delete[] str;
	} else {
		Object* obj = ref.getEntity();
		Reference str = Reference(obj->toString());
		r_value = append(str);
	}

	return r_value;
}

String* String::append(tlint i) const {
	byte ivalue[32];
	ivalue[31] = '\0';
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
	doubleValue[63] = '\0';
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

const byte* String::bytes() const {
	return mStr;
}

tlint String::compareTo(const Reference& ref) const {
	if(ref.instanceof(String::getType())){

	}

	return 0;
}

List* String::split(byte b) const{
	ArrayList* list = new ArrayList(String::getType());

	char token[2]{0};
	token[0] = b;
	byte* str = strtok(mStr, token);
	while(str != nullptr){
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list;
}

List* String::split(const Reference& ref) const{
	if(ref.isNull()){
		return new ArrayList(String::getType());
	}

	if(!ref.instanceof(String::getType())){
		return new ArrayList(String::getType());
	}

	ArrayList* list = new ArrayList(String::getType());

	byte* token = dynamic_cast<String*>(ref.getEntity())->mStr;
	byte* str = strtok(mStr, token);
	while(str != nullptr){
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list;
}

bool String::instanceof(hash_t type) const {
	return (CLASS_HASH == type) || Comparable::instanceof(type);
}

hash_t String::getType() {
	return CLASS_HASH;
}

hash_t String::genHash(){
	hash_t hash = 5381;
	for(tlint index = 0; index < mLength; index++){
		hash = ((hash << 5) + hash) + mStr[index];
	}

	return (CLASS_HASH & CLASS_MASK) + (hash & INSTANCE_MASK);
}

} /* namespace lang */
} /* namespace tl */
