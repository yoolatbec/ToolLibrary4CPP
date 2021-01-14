/*
 * FloatArray.cpp
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#include "FloatArray.h"
#include <cstring>

namespace tl {
namespace lang {

FloatArray::FloatArray(tlint size, float *initValues)
		: NOArray(size) {
	mElements = new float[mSize];

	if (initValues != nullptr) {
		for (tlint index = 0; index < size; index++) {
			mElements[index] = initValues[index];
		}
	} else {
		memset(mElements, 0, mSize * sizeof(float));
	}
}

FloatArray::~FloatArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

Reference FloatArray::newFloatArray(tlint size) {
	parameterCheck(size);

	return Reference(new FloatArray(size, nullptr));
}

Reference FloatArray::newFloatArray(tlint size, float *initValues) {
	parameterCheck(size);

	return Reference(new FloatArray(size, initValues));
}

float FloatArray::get(tlint index) {
	boundCheck(index);

	return mElements[index];
}

void FloatArray::set(tlint index, float value) {
	boundCheck(index);

	mElements[index] = value;
}

Reference FloatArray::clone(){
	return Reference(new FloatArray(mSize, mElements));
}

} /* namespace lang */
} /* namespace tl */
