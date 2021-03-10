/*
 * CharSequence.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: yoolatbec
 */

#include <lang/CharSequence.h>
#include <lang/IndexOutOfBoundsException.h>
#include <lang/String.h>

namespace tl {
namespace lang {

CharSequence::CharSequence(tlint size)
	: mLength(size) {
	// TODO Auto-generated constructor stub
	mSequence = nullptr;

	mHashCode = genHashCode(CLASS_SERIAL);
}

CharSequence::~CharSequence() {
	// TODO Auto-generated destructor stub

	delete [] mSequence;
}

tlint CharSequence::length(){
	return mLength;
}

void CharSequence::indexBoundCheck(tlint index){
	if(index < 0 || index >= mLength){
		throw IndexOutOfBoundsException();
	}
}

const char* CharSequence::toCharArray(){
	return mSequence;
}

Reference CharSequence::toString(){
	return Reference(new String(mSequence));
}

char CharSequence::charAt(tlint index){
	indexBoundCheck(index);
	return mSequence[index];
}

} /* namespace lang */
} /* namespace tl */
