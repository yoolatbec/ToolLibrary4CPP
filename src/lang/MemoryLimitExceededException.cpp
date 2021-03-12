/*
 * MemoryLimitExceededException.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/MemoryLimitExceededException.h>
#include <tl/lang/String.h>

namespace tl {
namespace lang {

Reference MemoryLimitExceededException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

MemoryLimitExceededException::MemoryLimitExceededException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

MemoryLimitExceededException::MemoryLimitExceededException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

MemoryLimitExceededException::~MemoryLimitExceededException() {
	// TODO Auto-generated destructor stub
}

type_t MemoryLimitExceededException::type() {
	return CLASS_SERIAL;
}

bool MemoryLimitExceededException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
