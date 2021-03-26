/*
 * DeadOwnerException.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/DeadOwnerException.h>

namespace tl {
namespace thread {

using lang::String;

Reference DeadOwnerException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

DeadOwnerException::DeadOwnerException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

DeadOwnerException::DeadOwnerException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

DeadOwnerException::~DeadOwnerException() {
	// TODO Auto-generated destructor stub
}

type_t DeadOwnerException::type() {
	return CLASS_SERIAL;
}

bool DeadOwnerException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
