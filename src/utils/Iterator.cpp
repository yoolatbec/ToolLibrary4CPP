/*
 * Iterator.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "Iterator.h"
#include "InvalidIteratorException.h"

namespace tl {
namespace utils {

Iterator::Iterator() {
	// TODO Auto-generated constructor stub
	mValid = true;
}

Iterator::~Iterator() {
	// TODO Auto-generated destructor stub
}

void Iterator::invalidate() {
	mValid = false;
}

void Iterator::checkValidation(){
	if(!valid()){
		//cast an exception
		throw InvalidIteratorException();
	}
}

bool Iterator::valid() {
	return mValid;
}

type_t Iterator::type() {
	return CLASS_SERIAL;
}

bool Iterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
