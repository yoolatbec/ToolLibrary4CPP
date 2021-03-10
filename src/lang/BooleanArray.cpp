/*
 * BooleanArray.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#include <lang/BooleanArray.h>
#include <cstdio>
#include <cstring>
#include <lang/String.h>
#include <lang/UnacceptableArgumentException.h>

namespace tl {
namespace lang {

BooleanArray::BooleanArray(tlint size, bool initValue)
	: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new bool[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = initValue;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

BooleanArray::BooleanArray(tlint size, bool *initValues)
	: NOArray(size) {
	mElements = new bool[mSize];

	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = initValues[index];
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

void BooleanArray::initParameterCheck(tlint value) {
	if (value <= 0) {
		throw UnacceptableArgumentException();
	}
}

Reference BooleanArray::toString() {
	char *str = new char[mSize * DEFAULT_WIDTH_FOR_EACH_ELEMENT + 3];
	str[0] = '[';
	str[1] = '\0';

	for (tlint index = 0; index < mSize; index++) {
		sprintf(str + strlen(str), "%s ", mElements[index] ? "true" : "false");
	}

	tlint index = strlen(str);
	str[index] = ']';
	str[index + 1] = '\0';

	String *rtval = new String(str);
	delete[] str;
	return Reference(rtval);
}

Reference BooleanArray::clone(){
	return Reference(new BooleanArray(mSize, mElements));
}

BooleanArray::~BooleanArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

Reference BooleanArray::newInstance(tlint size, bool *initValues) {
	if (initValues == nullptr) {
		return newInstance(size, DEFAULT_VALUE);
	}

	initParameterCheck(size);

	return Reference(new BooleanArray(size, initValues));
}

Reference BooleanArray::newInstance(tlint size, bool initValue) {
	initParameterCheck(size);

	return Reference(new BooleanArray(size, initValue));
}

bool BooleanArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

void BooleanArray::set(tlint index, bool value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

type_t BooleanArray::type() {
	return CLASS_SERIAL;
}

bool BooleanArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
