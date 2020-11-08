/*
 * Factory.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: yoolatbec
 */

#include "Factory.h"

namespace tl {
namespace utils {

Factory::Factory(Reference (*g)(Reference), hash_t type)
		: generator(g) {

}

tl::lang::Reference Factory::generate(const Reference &argument) const {
	return generator(argument);
}

bool Factory::instanceof(hash_t type) const{
	return (mHash & CLASS_MASK == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
