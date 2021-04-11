/*
 * Collection.cpp
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Collection.h>

namespace tl {
namespace utils {

Collection::Collection(type_t type) {
	// TODO Auto-generated constructor stub
	mElementType = type;
	mSize = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Collection::~Collection() {
	// TODO Auto-generated destructor stub
}

bool Collection::isEmpty() {
	return mSize == 0;
}

tlint Collection::size() {
	return mSize;
}

type_t Collection::type() {
	return CLASS_SERIAL;
}

bool Collection::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterable::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
