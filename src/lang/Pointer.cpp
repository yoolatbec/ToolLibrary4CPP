/*
 * Pointer.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Pointer.h>
#include <tl/lang/UnacceptableArgumentException.h>

namespace tl {
namespace lang {

Pointer::Pointer(void *ptr, tlint length)
	: mPointer(ptr) {
	// TODO Auto-generated constructor stub
	if(length <= 0){
		throw UnacceptableArgumentException();
	}
	mLength = length;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Pointer::~Pointer() {
	// TODO Auto-generated destructor stub

}

void* Pointer::get(){
	return mPointer;
}

tlint Pointer::length(){
	return mLength;
}

type_t Pointer::type(){
	return CLASS_SERIAL;
}

bool Pointer::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
