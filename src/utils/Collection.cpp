/*
 * Collection.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#include "Collection.h"

namespace tl {
namespace utils {

Collection::Collection() {
	// TODO Auto-generated constructor stub

}

Collection::~Collection() {
	// TODO Auto-generated destructor stub
}

bool Collection::instanceof(hash_t type) const {
	return (CLASS_HASH == type) || Iterable::instanceof(type);
}

hash_t Collection::getType() {
	return CLASS_HASH;
}

} /* namespace utils */
} /* namespace tl */
