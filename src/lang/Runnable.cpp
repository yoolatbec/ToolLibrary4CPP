/*
 * Runnable.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#include "Runnable.h"

namespace tl {
namespace lang {

Runnable::Runnable() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Runnable::~Runnable() {
	// TODO Auto-generated destructor stub
}

type_t Runnable::type(){
	return CLASS_SERIAL;
}

bool Runnable::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
