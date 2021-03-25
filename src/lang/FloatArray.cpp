/*
 * FloatArray.cpp
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/FloatArray.h>
#include <tl/lang/String.h>
#include <tl/lang/UnacceptableArgumentException.h>
#include <cstring>
#include <cstdio>

namespace tl {
namespace lang {

FloatArray::FloatArray(tlint size, float *initValues)
	: NOArray(size) {
	mElements = new float[mSize];

	for (tlint index = 0; index < size; index++) {
		mElements[index] = initValues[index];
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

FloatArray::FloatArray(tlint size, float value)
	: NOArray(size) {
	mElements = new float[mSize];
	for (tlint index = 0; index < size; index++) {
		mElements[index] = value;
	}
}

FloatArray::~FloatArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

void FloatArray::initParameterCheck(tlint i) {
	if (i < 0) {
		throw IllegalArgumentException();
	}
}

Reference FloatArray::newInstance(tlint size, float *initValues) {
	initParameterCheck(size);

	if(initValues == nullptr){
		return Reference(new FloatArray(size, DEFAULT_VALUE));
	}

	return Reference(new FloatArray(size, initValues));
}

Reference FloatArray::newInstance(tlint size, float value) {
	initParameterCheck(size);

	return Reference(new FloatArray(size, value));
}

float FloatArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

void FloatArray::set(tlint index, float value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

Reference FloatArray::clone() {
	return Reference(new FloatArray(mSize, mElements));
}

Reference FloatArray::toString() {
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

type_t FloatArray::type() {
	return CLASS_SERIAL;
}

bool FloatArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
