/*
 * Collection.cpp
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Collection.h>
#include <tl/lang/UnsupportedOperationException.h>

namespace tl {
namespace utils {

using lang::UnsupportedOperationException;

Collection::Collection(type_t type) {
	// TODO Auto-generated constructor stub
	mElementType = type;
	mSize = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Collection::~Collection() {
	// TODO Auto-generated destructor stub
}

type_t Collection::elementType() {
	return mElementType;
}
bool Collection::isEmpty() {
	return mSize == 0;
}

tlint Collection::size() {
	return mSize;
}

bool Collection::add(Reference ref) {
	throw UnsupportedOperationException();
}

bool Collection::addAll(Reference ref) {
	throw UnsupportedOperationException();
}

void Collection::clear() {
	throw UnsupportedOperationException();
}

bool Collection::remove(Reference ref) {
	throw UnsupportedOperationException();
}

void Collection::removeAll(Reference ref) {
	throw UnsupportedOperationException();
}

type_t Collection::type() {
	return CLASS_SERIAL;
}

bool Collection::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterable::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
