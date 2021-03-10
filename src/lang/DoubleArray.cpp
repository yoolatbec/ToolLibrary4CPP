/*
 * DoubleArray.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: yoolatbec
 */

#include <lang/DoubleArray.h>
#include <cstring>
#include <lang/IndexOutOfBoundsException.h>
#include <lang/UnacceptableArgumentException.h>
#include <lang/String.h>
#include <cstdio>

namespace tl {
namespace lang {

DoubleArray::DoubleArray(tlint size, double defaultValue)
	: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new double[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = defaultValue;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

DoubleArray::DoubleArray(tlint size, double *defaultValues)
	: NOArray(size) {
	mElements = new double[mSize];
	for (tlint index = 0; index < mSize; index++) {
		mElements[index] = defaultValues[index];
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

DoubleArray::~DoubleArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

void DoubleArray::initParameterCheck(tlint size) {
	if (size <= 0) {
		throw UnacceptableArgumentException();
	}
}

Reference DoubleArray::newInstance(tlint size, double *defaultValues) {
	initParameterCheck(size);

	if (defaultValues == nullptr) {
		return Reference(new DoubleArray(size, DEFAULT_VALUE));
	}

	return Reference(new DoubleArray(size, defaultValues));
}

Reference DoubleArray::newInstance(tlint size, double initValue) {
	initParameterCheck(size);

	return Reference(new DoubleArray(size, initValue));
}

Reference DoubleArray::clone() {
	return Reference(new DoubleArray(mSize, mElements));
}

void DoubleArray::set(tlint index, double value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

double DoubleArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

Reference DoubleArray::toString() {
	char *str = new char[mSize * RESERVED_WIDTH_FOR_EACH_BIT + 3];
	str[0] = '[';
	str[1] = '\0';

	for (tlint index = 0; index < size(); index++) {
		sprintf(str + strlen(str), "%g ", mElements[index]);
	}

	tlint i = strlen(str);
	str[i] = ']';
	str[i + 1] = '\0';

	Reference rtval = Reference(new String(str));
	delete[] str;
	return rtval;
}

type_t DoubleArray::type() {
	return CLASS_SERIAL;
}

bool DoubleArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
