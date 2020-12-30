/*
 * Collection.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#include "Collection.h"

namespace tl {
namespace utils {

Collection::Collection(type_t type)
		: mElementType(type) {
	// TODO Auto-generated constructor stub
	mSize = 0;
	mHashCode = genHashCode(CLASS_SERIAL);
}

Collection::~Collection() {
	// TODO Auto-generated destructor stub
}

bool Collection::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterable::instanceof(type);
}

type_t Collection::type() {
	return CLASS_SERIAL;
}

type_t Collection::elementType() {
	return mElementType;
}

tlint Collection::size() {
	return mSize;
}

bool Collection::empty() {
	return mSize == 0;
}

} /* namespace utils */
} /* namespace tl */
