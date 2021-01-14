/*
 * IntArray.cpp
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#include "IntArray.h"

namespace tl {
namespace lang {

IntArray::IntArray(tlint size)
		: NOArray(size) {
	// TODO Auto-generated constructor stub
	mElements = new int[mSize];
}

IntArray::~IntArray() {
	// TODO Auto-generated destructor stub
	delete[] mElements;
}

} /* namespace lang */
} /* namespace tl */
