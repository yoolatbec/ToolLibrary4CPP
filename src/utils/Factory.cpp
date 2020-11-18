/*
 * Factory.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: yoolatbec
 */

#include "Factory.h"

namespace tl {
namespace utils {

Factory::Factory(Reference (*g)(Reference))
		: generator(g) {
	mHash &= CLASS_HASH;
}

tl::lang::Reference Factory::generate(const Reference &argument) const {
	return generator(argument);
}

bool Factory::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
