/*
 * Iterable.cpp
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Iterable.h>

namespace tl {
namespace utils {

Iterable::Iterable() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Iterable::~Iterable() {
	// TODO Auto-generated destructor stub
}

type_t Iterable::type() {
	return CLASS_SERIAL;
}

bool Iterable::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
