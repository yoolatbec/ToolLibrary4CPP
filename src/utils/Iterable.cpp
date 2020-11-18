/*
 * Iterable.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#include "Iterable.h"

namespace tl {
namespace utils {

Iterable::Iterable() {
	// TODO Auto-generated constructor stub
	mHash &= CLASS_HASH;
}

Iterable::~Iterable() {
	// TODO Auto-generated destructor stub
}

bool Iterable::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
