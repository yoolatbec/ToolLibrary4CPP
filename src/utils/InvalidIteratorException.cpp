/*
 * InvalidIteratorException.cpp
 *
 *  Created on: Feb 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/utils/InvalidIteratorException.h>

namespace tl {
namespace utils {

using lang::Reference;
using lang::Exception;
using lang::String;

Reference InvalidIteratorException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

InvalidIteratorException::InvalidIteratorException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

InvalidIteratorException::InvalidIteratorException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

InvalidIteratorException::~InvalidIteratorException() {
	// TODO Auto-generated destructor stub
}

type_t InvalidIteratorException::type() {
	return CLASS_SERIAL;
}

bool InvalidIteratorException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
