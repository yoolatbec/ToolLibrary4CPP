/*
 * ReopenStreamException.cpp
 *
 *  Created on: Mar 28, 2021
 *      Author: yoolatbec
 */

#include <tl/io/ReopenStreamException.h>
#include <tl/lang/String.h>

namespace tl {
namespace io {

using lang::String;
using lang::Reference;

Reference ReopenStreamException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

ReopenStreamException::ReopenStreamException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

ReopenStreamException::ReopenStreamException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

ReopenStreamException::~ReopenStreamException() {
	// TODO Auto-generated destructor stub
}

type_t ReopenStreamException::type() {
	return CLASS_SERIAL;
}

bool ReopenStreamException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || IOException::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
