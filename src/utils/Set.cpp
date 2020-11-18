/*
 * Set.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "Set.h"

namespace tl {
namespace utils {

Set::Set(hash_t type)
		: Collection(type) {
	// TODO Auto-generated constructor stub
	mHash &= CLASS_HASH;
}

Set::~Set() {
	// TODO Auto-generated destructor stub
}

bool Set::instanceof(hash_t type) const{
	return (type == CLASS_HASH) || Collection::instanceof(type);
}

hash_t Set::getType(){
	return CLASS_HASH;
}

} /* namespace utils */
} /* namespace tl */
