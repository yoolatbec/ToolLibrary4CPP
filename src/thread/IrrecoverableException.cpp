/*
 * IrrecoverableException.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/IrrecoverableException.h>

namespace tl {
namespace thread {

using lang::String;

Reference IrrecoverableException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IrrecoverableException::IrrecoverableException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IrrecoverableException::IrrecoverableException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IrrecoverableException::~IrrecoverableException() {
	// TODO Auto-generated destructor stub
}

type_t IrrecoverableException::type() {
	return CLASS_SERIAL;
}

bool IrrecoverableException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
