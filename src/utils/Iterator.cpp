/*
 * Iterator.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "Iterator.h"

namespace tl {
namespace utils {

Iterator::Iterator() {
	// TODO Auto-generated constructor stub
	mHash &= CLASS_HASH;
	mValid = true;
}

Iterator::~Iterator() {
	// TODO Auto-generated destructor stub
}

bool Iterator::isValid() const{
	return mValid;
}

hash_t Iterator::getType(){
	return CLASS_HASH;
}

bool Iterator::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
