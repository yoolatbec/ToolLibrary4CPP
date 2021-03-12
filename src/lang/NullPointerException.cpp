/*
 * NullPointerException.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/NullPointerException.h>
#include <tl/lang/String.h>

namespace tl {
namespace lang {

Reference NullPointerException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

NullPointerException::NullPointerException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NullPointerException::NullPointerException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

NullPointerException::~NullPointerException() {
	// TODO Auto-generated destructor stub
}

type_t NullPointerException::type() {
	return CLASS_SERIAL;
}

bool NullPointerException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
