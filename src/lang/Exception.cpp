/*
 * Exception.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Exception.h>
#include <tl/lang/String.h>
#include <cstring>

namespace tl {
namespace lang {

using lang::Reference;

Reference Exception::sDefaultMessage = Reference(new String(DEFAULT_MESSAGE));

Exception::Exception() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Exception::Exception(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

const char* Exception::concatMessage(const char *str1, const char *str2) {
	tlint strlen1 = strlen(str1);
	tlint strlen2 = strlen(str2);

	char *msg = new char[strlen1 + strlen2 + 1];
	strncpy(msg, str1, strlen1);
	strncpy(msg + strlen1, str2, strlen2);

	return msg;
}

Reference Exception::message() {
	return mMessage;
}

Exception::~Exception() {
	// TODO Auto-generated destructor stub
}

type_t Exception::type() {
	return CLASS_SERIAL;
}

bool Exception::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
