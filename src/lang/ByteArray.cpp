/*
 * ByteArray.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/ByteArray.h>
#include <tl/lang/String.h>
#include <tl/lang/IllegalArgumentException.h>
#include <cstdio>
#include <cstring>

namespace tl {
namespace lang {

ByteArray::ByteArray(tlint size, byte initValue)
	: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new byte[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = initValue;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}
//
//ByteArray::ByteArray(tlint size, byte *initValues)
//	: NOArray(size) {
//	mElements = new byte[mSize];
//	for (tlint index = 0; index < mSize; index++) {
//		mElements[index] = initValues[index];
//	}
//
//	mHashCode = genHashCode(CLASS_SERIAL);
//}

ByteArray::ByteArray(tlint size, byte *initValues, bool useInput)
	: NOArray(size) {
	if (useInput) {
		mElements = initValues;
	} else {
		mElements = new byte[mSize];
		for (tlint index = 0; index < mSize; index++) {
			mElements[index] = initValues[index];
		}
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

void ByteArray::initParameterCheck(tlint size) {
	if (size <= 0) {
		throw IllegalArgumentException();
	}
}

Reference ByteArray::newInstance(tlint size, byte initValue) {
	initParameterCheck(size);

	return Reference(new ByteArray(size, initValue));
}
//
//Reference ByteArray::newInstance(tlint size, byte *initValues) {
//	initParameterCheck(size);
//
//	if (initValues == nullptr) {
//		return newInstance(size, DEFAULT_VALUE);
//	}
//
//	return Reference(new ByteArray(size, initValues, false));
//}

Reference ByteArray::newInstance(tlint size, byte *initValues, bool useInput) {
	initParameterCheck(size);

	if (initValues == nullptr) {
		return newInstance(size, DEFAULT_VALUE);
	}

	return Reference(new ByteArray(size, initValues, useInput));
}

Reference ByteArray::clone() {
	return Reference(new ByteArray(mSize, mElements, false));
}

Reference ByteArray::toString() {
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

void ByteArray::set(tlint index, byte value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

byte ByteArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

const byte* ByteArray::rawData() {
	return mElements;
}

ByteArray::~ByteArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

type_t ByteArray::type() {
	return CLASS_SERIAL;
}

bool ByteArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
