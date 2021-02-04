/*
 * NavigableSet.cpp
 *
 *  Created on: 29 Jan 2021
 *      Author: yoolatbec
 */

#include "NavigableSet.h"

namespace tl {
namespace utils {

NavigableSet::NavigableSet(type_t elementType)
		: SortedSet(elementType) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

NavigableSet::~NavigableSet() {
	// TODO Auto-generated destructor stub
}

bool NavigableSet::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SortedSet::instanceof(type);
}

type_t NavigableSet::type() {
	return CLASS_SERIAL;
}

} /* namespace utils */
} /* namespace tl */
