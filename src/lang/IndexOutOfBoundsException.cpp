/*
 * IndexOutOfBoundsException.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: yoolatbec
 */

#include <lang/IndexOutOfBoundsException.h>
#include <lang/String.h>

namespace tl {
namespace lang {

Reference IndexOutOfBoundsException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IndexOutOfBoundsException::IndexOutOfBoundsException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IndexOutOfBoundsException::IndexOutOfBoundsException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IndexOutOfBoundsException::~IndexOutOfBoundsException() {
	// TODO Auto-generated destructor stub
}

type_t IndexOutOfBoundsException::type() {
	return CLASS_SERIAL;
}

bool IndexOutOfBoundsException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
