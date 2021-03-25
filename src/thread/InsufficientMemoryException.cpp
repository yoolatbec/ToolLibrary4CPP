/*
 * InsufficientMemoryException.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/InsufficientMemoryException.h>

namespace tl {
namespace thread {

using lang::String;

Reference InsufficientMemoryException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

InsufficientMemoryException::InsufficientMemoryException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

InsufficientMemoryException::InsufficientMemoryException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

InsufficientMemoryException::~InsufficientMemoryException() {
	// TODO Auto-generated destructor stub
}

type_t InsufficientMemoryException::type() {
	return CLASS_SERIAL;
}

bool InsufficientMemoryException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
