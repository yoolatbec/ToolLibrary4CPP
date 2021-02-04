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
}

Iterator::~Iterator() {
	// TODO Auto-generated destructor stub
}

type_t Iterator::type() {
	return CLASS_SERIAL;
}

bool Iterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
