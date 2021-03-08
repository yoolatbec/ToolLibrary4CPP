/*
 * Cloneable.cpp
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#include <lang/Cloneable.h>

namespace tl {
namespace lang {

Cloneable::Cloneable() {
	// TODO Auto-generated constructor stub

}

Cloneable::~Cloneable() {
	// TODO Auto-generated destructor stub
}

type_t Cloneable::type(){
	return CLASS_SERIAL;
}

bool Cloneable::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
