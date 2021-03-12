/*
 * NoSuchElementException.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/utils/NoSuchElementException.h>

namespace tl {
namespace utils {

using lang::Reference;
using lang::String;

NoSuchElementException::NoSuchElementException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NoSuchElementException::NoSuchElementException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NoSuchElementException::~NoSuchElementException() {
	// TODO Auto-generated destructor stub
}

type_t NoSuchElementException::type() {
	return CLASS_SERIAL;
}

bool NoSuchElementException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
