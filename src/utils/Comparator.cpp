/*
 * Comparator.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Comparator.h>

namespace tl {
namespace utils {

Comparator::Comparator() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Comparator::~Comparator() {
	// TODO Auto-generated destructor stub
}

type_t Comparator::type() {
	return CLASS_SERIAL;
}

bool Comparator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
