/*
 * ErrorChecker.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/ErrorChecker.h>
#include <tl/thread/ErrorCode.h>

namespace tl {
namespace thread {

ErrorChecker::ErrorChecker() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

ErrorChecker::~ErrorChecker() {
	// TODO Auto-generated destructor stub
}

void ErrorChecker::check(tlint err) {

}

type_t ErrorChecker::type() {
	return CLASS_SERIAL;
}

bool ErrorChecker::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
