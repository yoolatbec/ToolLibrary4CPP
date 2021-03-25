/*
 * TimeOutException.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/TimeOutException.h>

namespace tl {
namespace thread {

using lang::String;

Reference TimeOutException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

TimeOutException::TimeOutException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

TimeOutException::TimeOutException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

TimeOutException::~TimeOutException() {
	// TODO Auto-generated destructor stub
}

type_t TimeOutException::type() {
	return CLASS_SERIAL;
}

bool TimeOutException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ThreadException::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
