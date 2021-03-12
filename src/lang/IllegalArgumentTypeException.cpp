/*
 * IllegalArgumentTypeException.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/IllegalArgumentTypeException.h>
#include <tl/lang/String.h>

namespace tl {
namespace lang {

Reference IllegalArgumentTypeException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IllegalArgumentTypeException::IllegalArgumentTypeException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalArgumentTypeException::IllegalArgumentTypeException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalArgumentTypeException::~IllegalArgumentTypeException() {
	// TODO Auto-generated destructor stub
}

type_t IllegalArgumentTypeException::type() {
	return CLASS_SERIAL;
}

bool IllegalArgumentTypeException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
