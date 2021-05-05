/*
 * Set.cpp
 *
 *  Created on: Apr 24, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Set.h>

namespace tl {
namespace utils {

Set::Set(type_t elementType)
	: Collection(elementType) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Set::~Set() {
	// TODO Auto-generated destructor stub
}

type_t Set::type() {
	return CLASS_SERIAL;
}

bool Set::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
