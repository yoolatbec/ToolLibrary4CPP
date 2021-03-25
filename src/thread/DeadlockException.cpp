/*
 * DeadlockException.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/DeadlockException.h>

namespace tl {
namespace thread {

using lang::String;

DeadlockException::DeadlockException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

DeadlockException::DeadlockException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

DeadlockException::~DeadlockException() {
	// TODO Auto-generated destructor stub
}

type_t DeadlockException::type() {
	return CLASS_SERIAL;
}

bool DeadlockException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
