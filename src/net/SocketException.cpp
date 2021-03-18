/*
 * SocketException.cpp
 *
 *  Created on: Mar 18, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/net/SocketException.h>

namespace tl {
namespace net {

using lang::String;

Reference SocketException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

SocketException::SocketException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

SocketException::SocketException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

SocketException::~SocketException() {
	// TODO Auto-generated destructor stub
}

type_t SocketException::type() {
	return CLASS_SERIAL;
}

bool SocketException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
