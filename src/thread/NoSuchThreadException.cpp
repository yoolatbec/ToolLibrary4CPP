/*
 * NoSuchThreadException.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/NoSuchThreadException.h>

namespace tl {
namespace thread {

using lang::String;

Reference NoSuchThreadException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

NoSuchThreadException::NoSuchThreadException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NoSuchThreadException::NoSuchThreadException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NoSuchThreadException::~NoSuchThreadException() {
	// TODO Auto-generated destructor stub
}

type_t NoSuchThreadException::type() {
	return CLASS_SERIAL;
}

bool NoSuchThreadException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
