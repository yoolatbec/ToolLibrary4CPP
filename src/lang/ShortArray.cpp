/*
 * ShortArray.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/ShortArray.h>
#include <tl/lang/String.h>
#include <tl/lang/IllegalArgumentException.h>
#include <cstdio>
#include <cstring>

namespace tl {
namespace lang {

ShortArray::ShortArray(tlint size, short initValue)
	: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new short[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = initValue;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

ShortArray::ShortArray(tlint size, short *initValues, bool useInput)
	: NOArray(size) {
	if (useInput) {
		mElements = initValues;
	} else {
		mElements = new short[mSize];
		for (tlint index = 0; index < mSize; index++) {
			mElements[index] = initValues[index];
		}
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

void ShortArray::initParameterCheck(tlint size) {
	if (size <= 0) {
		throw IllegalArgumentException();
	}
}

ShortArray::~ShortArray() {
	// TODO Auto-generated destructor stub
}

void ShortArray::set(tlint index, short value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

short ShortArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

Reference ShortArray::clone() {
	return Reference(new ShortArray(mSize, mElements, false));
}

Reference ShortArray::toString() {
	char *str = new char[mSize * DEFAULT_WIDTH_FOR_EACH_ELEMENT + 3];
	str[0] = '[';
	str[1] = '\0';

	for (tlint index = 0; index < mSize; index++) {
		sprintf(str + strlen(str), "%d ", mElements[index]);
	}

	tlint index = strlen(str);
	str[index] = ']';
	str[index + 1] = '\0';

	String *rtval = new String(str);
	delete[] str;
	return Reference(rtval);
}

Reference ShortArray::newInstance(tlint size, short *initValues,
	bool useInput) {
	if (initValues == nullptr) {
		return newInstance(size, DEFAULT_VALUE);
	}

	initParameterCheck(size);

	return Reference(new ShortArray(size, initValues, useInput));
}

Reference ShortArray::newInstance(tlint size, short initValue) {
	initParameterCheck(size);

	return Reference(new ShortArray(size, initValue));
}

type_t ShortArray::type() {
	return CLASS_SERIAL;
}

bool ShortArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
