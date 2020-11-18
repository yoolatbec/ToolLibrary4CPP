/*
 * HashSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "HashSet.h"

namespace tl {
namespace utils {

HashSet::HashSet(hash_t type)
		: Set(type) {
	// TODO Auto-generated constructor stub
	mHash &= CLASS_HASH;
}

HashSet::~HashSet() {
	// TODO Auto-generated destructor stub
}

} /* namespace utils */
} /* namespace tl */
