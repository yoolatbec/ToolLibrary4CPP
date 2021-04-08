/*
 * FailedToOpenFileException.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: yoolatbec
 */

#include <tl/io/FailedToOpenFileException.h>
#include <tl/lang/String.h>

namespace tl {
namespace io {

using lang::String;
using lang::Reference;

Reference FailedToOpenFileException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

FailedToOpenFileException::FailedToOpenFileException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

FailedToOpenFileException::FailedToOpenFileException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

FailedToOpenFileException::~FailedToOpenFileException() {
	// TODO Auto-generated destructor stub
}

type_t FailedToOpenFileException::type() {
	return CLASS_SERIAL;
}

bool FailedToOpenFileException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || IOException::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
