/*
 * IllegalOperationException.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/IllegalOperationException.h>

namespace tl {
namespace thread {

using lang::Reference;
using lang::String;

Reference IllegalOperationException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IllegalOperationException::IllegalOperationException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalOperationException::IllegalOperationException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalOperationException::~IllegalOperationException() {
	// TODO Auto-generated destructor stub
}

type_t IllegalOperationException::type() {
	return CLASS_SERIAL;
}

bool IllegalOperationException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
