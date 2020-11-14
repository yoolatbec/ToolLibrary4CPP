/*
 * Collection.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#include "Collection.h"

namespace tl {
namespace utils {

Collection::Collection(hash_t type)
		: mElementType(type) {
	// TODO Auto-generated constructor stub
	mSize = 0;
}

Collection::~Collection() {
	// TODO Auto-generated destructor stub
}

bool Collection::instanceof(hash_t type) const {
	return (CLASS_HASH == type) || Iterable::instanceof(type);
}

hash_t Collection::getType() {
	return CLASS_HASH;
}

hash_t Collection::getElementType() const{
	return mElementType;
}

size_t Collection::size() const{
	return mSize;
}

} /* namespace utils */
} /* namespace tl */
