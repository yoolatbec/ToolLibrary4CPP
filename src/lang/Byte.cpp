/*
 * Byte.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include "Byte.h"

namespace tl {
namespace lang {

Byte::Byte(byte value) {
	// TODO Auto-generated constructor stub
	mValue = value;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Byte::~Byte() {
	// TODO Auto-generated destructor stub
}

type_t Byte::type(){
	return CLASS_SERIAL;
}

bool Byte::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
