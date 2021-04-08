/*
 * RecloseException.cpp
 *
 *  Created on: Apr 6, 2021
 *      Author: yoolatbec
 */

#include <tl/io/IllegalStreamException.h>
#include <tl/lang/String.h>

namespace tl {
namespace io {

using lang::String;
using lang::Reference;

Reference IllegalStreamException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IllegalStreamException::IllegalStreamException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalStreamException::IllegalStreamException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IllegalStreamException::~IllegalStreamException() {
	// TODO Auto-generated destructor stub
}

type_t IllegalStreamException::type() {
	return CLASS_SERIAL;
}

bool IllegalStreamException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || IOException::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
