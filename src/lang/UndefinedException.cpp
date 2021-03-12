/*
 * UndefinedException.cpp
 *
 *  Created on: Feb 24, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/lang/UndefinedException.h>

namespace tl {
namespace lang {

Reference UndefinedException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

UndefinedException::UndefinedException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UndefinedException::UndefinedException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

UndefinedException::~UndefinedException() {
	// TODO Auto-generated destructor stub
}

type_t UndefinedException::type() {
	return CLASS_SERIAL;
}

bool UndefinedException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
