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

}

List::List(hash_t element_type, size_t reserved)
		: mElementType(element_type) {

}

List::List(const List &other)
		: Object(other), mElementType(other.mElementType) {

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

} /* namespace utils */
} /* namespace tl */
