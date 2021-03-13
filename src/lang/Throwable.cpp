/*
 * Throwable.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Throwable.h>

namespace tl {
namespace lang {

Throwable::Throwable() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Throwable::~Throwable() {
	// TODO Auto-generated destructor stub
}

type_t Throwable::type() {
	return CLASS_SERIAL;
}

bool Throwable::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
