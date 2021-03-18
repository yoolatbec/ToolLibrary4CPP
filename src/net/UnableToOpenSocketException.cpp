/*
 * UnableToOpenSocketException.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/net/UnableToOpenSocketException.h>

namespace tl {
namespace net {

using lang::Reference;
using lang::String;

Reference UnableToOpenSocketException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

UnableToOpenSocketException::UnableToOpenSocketException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnableToOpenSocketException::UnableToOpenSocketException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnableToOpenSocketException::~UnableToOpenSocketException() {
	// TODO Auto-generated destructor stub
}

type_t UnableToOpenSocketException::type() {
	return CLASS_SERIAL;
}

bool UnableToOpenSocketException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NetworkException::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
