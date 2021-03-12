/*
 * Pointer.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Pointer.h>

namespace tl {
namespace lang {

Pointer::Pointer(void *ptr)
	: mPointer(ptr) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Pointer::~Pointer() {
	// TODO Auto-generated destructor stub

}

void* Pointer::get(){
	return mPointer;
}

type_t Pointer::type(){
	return CLASS_SERIAL;
}

bool Pointer::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
