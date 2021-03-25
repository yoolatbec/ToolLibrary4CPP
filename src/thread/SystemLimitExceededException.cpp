/*
 * SystemLimitExceededException.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Reference.h>
#include <tl/lang/String.h>
#include <tl/thread/SystemLimitExceededException.h>

namespace tl {
namespace thread {

using lang::Reference;
using lang::String;

Reference SystemLimitExceededException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

SystemLimitExceededException::SystemLimitExceededException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

SystemLimitExceededException::SystemLimitExceededException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

SystemLimitExceededException::~SystemLimitExceededException() {
	// TODO Auto-generated destructor stub
}

type_t SystemLimitExceededException::type() {
	return CLASS_SERIAL;
}

bool SystemLimitExceededException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
