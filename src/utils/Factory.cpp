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

} /* namespace utils */
} /* namespace tl */
