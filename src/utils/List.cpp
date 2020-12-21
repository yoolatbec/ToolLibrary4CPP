/*
 * List.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "List.h"

namespace tl {
namespace utils {

List::List(type_t element_type)
		:Collection(element_type) {
	mCapacity = DEFAULT_CAPACITY;
	mModified = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::List(type_t element_type, size_t reserved)
		:Collection(element_type) {
	mCapacity = reserved > 0 ? reserved : DEFAULT_CAPACITY;
	mModified = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::~List() {

}

size_t List::getCapacity() {
	return mCapacity;
}

size_t List::getSize() {
	return mSize;
}

type_t List::elementType() {
	return mElementType;
}

bool List::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

type_t List::type(){
	return CLASS_SERIAL;
}

ListIterator::ListIterator(){

}

bool ListIterator::instanceof(type_t type){
	return CLASS_SERIAL == type || Iterator::instanceof(type);
}

type_t ListIterator::type(){
	return CLASS_SERIAL;
}

} /* namespace utils */
} /* namespace tl */
