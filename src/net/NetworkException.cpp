/*
 * NetworkException.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/net/NetworkException.h>

namespace tl {
namespace net {

using lang::Reference;
using lang::String;

Reference NetworkException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

NetworkException::NetworkException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NetworkException::NetworkException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NetworkException::~NetworkException() {
	// TODO Auto-generated destructor stub
}

type_t NetworkException::type() {
	return CLASS_SERIAL;
}

bool NetworkException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || lang::Exception::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
