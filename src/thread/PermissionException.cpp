/*
 * PermissionException.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/PermissionException.h>

namespace tl {
namespace thread {

using lang::String;

Reference PermissionException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

PermissionException::PermissionException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

PermissionException::PermissionException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

PermissionException::~PermissionException() {
	// TODO Auto-generated destructor stub
}

type_t PermissionException::type() {
	return CLASS_SERIAL;
}

bool PermissionException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
