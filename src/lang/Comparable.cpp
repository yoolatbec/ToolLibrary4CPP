/*
 * Comparable.cpp
 *
 *  Created on: Sep 28, 2020
 *      Author: yoolatbec
 */

#include "Comparable.h"

namespace tl {
namespace lang {

bool Comparable::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
