/*
 * UnacceptableArgumentException.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#include <lang/UnacceptableArgumentException.h>
#include <lang/String.h>

namespace tl {
namespace lang {

Reference UnacceptableArgumentException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

UnacceptableArgumentException::UnacceptableArgumentException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnacceptableArgumentException::UnacceptableArgumentException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnacceptableArgumentException::~UnacceptableArgumentException() {
	// TODO Auto-generated destructor stub
}

type_t UnacceptableArgumentException::type() {
	return CLASS_SERIAL;
}

bool UnacceptableArgumentException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
