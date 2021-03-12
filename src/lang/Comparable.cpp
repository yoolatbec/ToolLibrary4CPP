/*
 * Comparable.cpp
 *
 *  Created on: Sep 28, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Comparable.h>

namespace tl {
namespace lang {

bool Comparable::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

type_t Comparable::type(){
	return CLASS_SERIAL;
}

} /* namespace lang */
} /* namespace tl */
