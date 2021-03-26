/*
 * NoMemoryException.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/NoMemoryException.h>

namespace tl {
namespace thread {

using lang::String;

Reference NoMemoryException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

NoMemoryException::NoMemoryException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NoMemoryException::NoMemoryException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NoMemoryException::~NoMemoryException() {
	// TODO Auto-generated destructor stub
}

type_t NoMemoryException::type() {
	return CLASS_SERIAL;
}

bool NoMemoryException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
