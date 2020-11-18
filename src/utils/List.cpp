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
		:Collection(element_type) {
	mCapacity = DEFAULT_CAPACITY;
	mModified = false;
}

List::List(hash_t element_type, size_t reserved)
		:Collection(element_type) {
	mHash &= CLASS_HASH;
	mCapacity = reserved > 0 ? reserved : DEFAULT_CAPACITY;
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

hash_t List::elementType() const {
	return mElementType;
}

bool List::instanceof(hash_t type) const {
	return (CLASS_HASH == type) || Object::instanceof(type);
}

hash_t List::getType(){
	return CLASS_HASH;
}

} /* namespace utils */
} /* namespace tl */
