/*
 * UnsupportedOperationException.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/lang/UnsupportedOperationException.h>

namespace tl {
namespace lang {

Reference UnsupportedOperationException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

UnsupportedOperationException::UnsupportedOperationException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnsupportedOperationException::UnsupportedOperationException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UnsupportedOperationException::~UnsupportedOperationException() {
	// TODO Auto-generated destructor stub
}

type_t UnsupportedOperationException::type() {
	return CLASS_SERIAL;
}

bool UnsupportedOperationException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
