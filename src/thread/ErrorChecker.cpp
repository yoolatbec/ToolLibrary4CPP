/*
 * ErrorChecker.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/ErrorChecker.h>
#include <tl/thread/ErrorCode.h>
#include <tl/thread/SystemLimitExceededException.h>
#include <tl/thread/TimeOutException.h>
#include <tl/thread/PermissionException.h>
#include <tl/thread/DeadlockException.h>
#include <tl/thread/InsufficientMemoryException.h>
#include <tl/thread/NoSuchThreadException.h>
#include <tl/lang/IllegalArgumentException.h>

namespace tl {
namespace thread {

using lang::IllegalArgumentException;

ErrorChecker::ErrorChecker() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

ErrorChecker::~ErrorChecker() {
	// TODO Auto-generated destructor stub
}

void ErrorChecker::check(tlint err) {
	switch (err) {
	case SUCCESS:
		break;
	case INVALID_ARGUMENT:
		throw IllegalArgumentException();
		break;
	case PERMISSION:
		throw PermissionException();
		break;
	case NO_SUCH_THREAD:
		throw NoSuchThreadException();
		break;
	case DEADLOCK:
		throw DeadlockException();
		break;
	case LIMIT_EXCEEDED:
		throw SystemLimitExceededException();
		break;
	case OUT_OF_MEMORY:
		throw InsufficientMemoryException();
		break;
	case TIMEDOUT:
		throw TimeOutException();
		break;
	default:
		throw ThreadException();
		break;
	}
}

type_t ErrorChecker::type() {
	return CLASS_SERIAL;
}

bool ErrorChecker::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
