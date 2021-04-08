/*
 * UnacceptableArgumentException.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/lang/IllegalArgumentException.h>

namespace tl {
namespace lang {

Reference IllegalArgumentException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IllegalArgumentException::IllegalArgumentException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalArgumentException::IllegalArgumentException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalArgumentException::~IllegalArgumentException() {
	// TODO Auto-generated destructor stub
}

type_t IllegalArgumentException::type() {
	return CLASS_SERIAL;
}

bool IllegalArgumentException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
