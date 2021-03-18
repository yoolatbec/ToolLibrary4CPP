/*
 * FailedToExecuteException.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/FailedToExecuteException.h>

namespace tl {
namespace thread {

using lang::Reference;
using lang::String;

Reference FailedToExecuteException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

FailedToExecuteException::FailedToExecuteException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

FailedToExecuteException::FailedToExecuteException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

FailedToExecuteException::~FailedToExecuteException() {
	// TODO Auto-generated destructor stub
}

type_t FailedToExecuteException::type() {
	return CLASS_SERIAL;
}

bool FailedToExecuteException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
