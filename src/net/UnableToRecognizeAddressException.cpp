/*
 * UnableToRecognizeAddressException.cpp
 *
 *  Created on: Mar 18, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/net/UnableToRecognizeAddressException.h>

namespace tl {
namespace net {

using lang::Reference;
using lang::String;

Reference UnableToRecognizeAddressException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

UnableToRecognizeAddressException::UnableToRecognizeAddressException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnableToRecognizeAddressException::UnableToRecognizeAddressException(
	const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnableToRecognizeAddressException::~UnableToRecognizeAddressException() {
	// TODO Auto-generated destructor stub
}

type_t UnableToRecognizeAddressException::type() {
	return CLASS_SERIAL;
}

bool UnableToRecognizeAddressException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NetworkException::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
