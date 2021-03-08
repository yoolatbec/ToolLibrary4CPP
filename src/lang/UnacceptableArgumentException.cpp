/*
 * UnacceptableArgumentException.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#include <lang/UnacceptableArgumentException.h>

namespace tl {
namespace lang {

UnacceptableArgumentException::UnacceptableArgumentException() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

UnacceptableArgumentException::~UnacceptableArgumentException() {
	// TODO Auto-generated destructor stub
}

type_t UnacceptableArgumentException::type() {
	return CLASS_SERIAL;
}

bool UnacceptableArgumentException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
