/*
 * SortedSet.cpp
 *
 *  Created on: 29 Jan 2021
 *      Author: yoolatbec
 */

#include "SortedSet.h"

namespace tl {
namespace utils {

SortedSet::SortedSet(type_t elementType)
		: Set(elementType) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

SortedSet::~SortedSet() {
	// TODO Auto-generated destructor stub
}

bool SortedSet::instanceof(type_t type) {
	return (type == CLASS_SERIAL) || Set::instanceof(type);
}

type_t SortedSet::type() {
	return CLASS_SERIAL;
}

} /* namespace utils */
} /* namespace tl */
