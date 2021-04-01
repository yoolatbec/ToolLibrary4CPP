/*
 * Pointer.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Pointer.h>
#include <tl/lang/IllegalArgumentException.h>

namespace tl {
namespace lang {

Pointer::Pointer(void *ptr, tlint64 length)
	: mPointer(ptr) {
	// TODO Auto-generated constructor stub
	if(length <= 0){
		throw IllegalArgumentException();
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

tlint64 Pointer::length(){
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
