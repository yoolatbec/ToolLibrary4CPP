/*
 * Iterator.cpp
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Iterator.h>
#include <tl/utils/InvalidIteratorException.h>

namespace tl {
namespace utils {

Iterator::Iterator() {
	// TODO Auto-generated constructor stub
	mValid = true;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Iterator::~Iterator() {
	// TODO Auto-generated destructor stub
}

bool Iterator::hasNext() {
	return !mNext.isNull();
}

bool Iterator::isValid() {
	return mValid;
}

void Iterator::invalidate() {
	mValid = false;
}

void Iterator::checkValidation() {
	if (!mValid) {
		//cast an exception
		throw InvalidIteratorException();
	}
}

type_t Iterator::type() {
	return CLASS_SERIAL;
}

bool Iterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
