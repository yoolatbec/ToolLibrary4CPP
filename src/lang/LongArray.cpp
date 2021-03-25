/*
 * LongArray.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/LongArray.h>
#include <tl/lang/String.h>
#include <tl/lang/UnacceptableArgumentException.h>
#include <cstdio>
#include <cstring>

namespace tl {
namespace lang {

LongArray::LongArray(tlint size, tlint64 initValue)
	: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new tlint64[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = initValue;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

LongArray::LongArray(tlint size, tlint64 *initValues)
	: NOArray(size) {
	mElements = new tlint64[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = initValues[index];
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

void LongArray::initParameterCheck(tlint size) {
	if (size <= 0) {
		throw IllegalArgumentException();
	}
}

LongArray::~LongArray() {
	// TODO Auto-generated destructor stub
}

Reference LongArray::newInstance(tlint size, tlint64 initValue) {
	initParameterCheck(size);

	return Reference(new LongArray(size, initValue));
}

Reference LongArray::newInstance(tlint size, tlint64 *initValues) {
	if (initValues == nullptr) {
		return newInstance(size, DEFAULT_VALUE);
	}

	initParameterCheck(size);

	return Reference(new LongArray(size, initValues));
}

Reference LongArray::toString() {
	char *str = new char[mSize * DEFAULT_WIDTH_FOR_EACH_ELEMENT + 3];
	str[0] = '[';
	str[1] = '\0';

	for (tlint index = 0; index < mSize; index++) {
		sprintf(str + strlen(str), "%lld ", mElements[index]);
	}

	tlint index = strlen(str);
	str[index] = ']';
	str[index + 1] = '\0';

	String *rtval = new String(str);
	delete[] str;
	return Reference(rtval);
}

Reference LongArray::clone() {
	return Reference(new LongArray(mSize, mElements));
}

void LongArray::set(tlint index, tlint64 value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

tlint64 LongArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

type_t LongArray::type() {
	return CLASS_SERIAL;
}

bool LongArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
