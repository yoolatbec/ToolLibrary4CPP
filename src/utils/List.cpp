/*
 * List.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "List.h"

namespace tl {
namespace utils {

List::List(hash_t element_type)
		: mElementType(element_type) {
	mCapacity = DEFAULT_CAPACITY;
	mSize = 0;
	mModified = false;
}

List::List(hash_t element_type, size_t reserved)
		: mElementType(element_type) {
	mCapacity = reserved > 0 ? reserved : DEFAULT_CAPACITY;
	mSize = 0;
	mModified = false;
}

List::~List() {

}

size_t List::getCapacity() const {
	return mCapacity;
}

size_t List::getSize() const {
	return mSize;
}

hash_t List::elementType() const{
	return mElementType;
}

bool List::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
