/*
 * Iterable.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#include <utils/Iterable.h>

namespace tl {
namespace utils {

Iterable::Iterable() {
	// TODO Auto-generated constructor stub
}

Iterable::~Iterable() {
	// TODO Auto-generated destructor stub
}

bool Iterable::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

type_t Iterable::type() {
	return CLASS_SERIAL;
}

} /* namespace utils */
} /* namespace tl */
