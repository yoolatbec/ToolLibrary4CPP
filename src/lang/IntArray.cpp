/*
 * IntArray.cpp
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/IntArray.h>
#include <tl/lang/String.h>
#include <tl/lang/IllegalArgumentException.h>
#include <cstring>
#include <cstdio>

namespace tl {
namespace lang {

IntArray::IntArray(tlint size, tlint *initValues, bool useInput)
	: NOArray(size) {
	// TODO Auto-generated constructor stub
	if (useInput) {
		mElements = initValues;
	} else {
		mElements = new tlint[mSize];

		for (tlint i = 0; i < mSize; i++) {
			mElements[i] = initValues[i];
		}
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

IntArray::IntArray(tlint size, tlint initValue)
	: NOArray(size) {
	mElements = new tlint[mSize];

	for (tlint i = 0; i < mSize; i++) {
		mElements[i] = initValue;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

IntArray::~IntArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

Reference IntArray::newInstance(tlint size, tlint *initValues, bool useInput) {

	return Reference(new IntArray(size, initValues, useInput));
}

tlint IntArray::get(tlint index) {
	indexBoundCheck(index);

	return mElements[index];
}

void IntArray::set(tlint index, tlint value) {
	indexBoundCheck(index);

	mElements[index] = value;
}

Reference IntArray::toString() {
	char *str = new char[DEFAULT_WIDTH_FOR_EACH_ELEMENT * mSize + 3];

	str[0] = '\0';
	str[1] = '[';

	for (tlint index = 0; index < size(); index++) {
		sprintf(str + strlen(str), "%d ", mElements[index]);
	}

	tlint index = strlen(str);
	str[index] = ']';
	str[index + 1] = '\0';

	Reference rtval = Reference(new String(str));
	delete[] str;

	return rtval;
}

Reference IntArray::clone() {
	return Reference(new IntArray(mSize, mElements, false));
}

type_t IntArray::type() {
	return CLASS_SERIAL;
}

bool IntArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NOArray::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
