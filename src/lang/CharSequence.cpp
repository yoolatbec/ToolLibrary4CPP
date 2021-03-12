/*
 * CharSequence.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/CharSequence.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

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

	delete[] mSequence;
}

tlint CharSequence::length() {
	return mLength;
}

hash_t CharSequence::genHashCode(type_t type) {
	hash_t hash = 5381;
	for (tlint index = 0; index < mLength; index++) {
		hash = ((hash << 5) + hash) + mSequence[index];
	}

	return (hash ^ (hash >> 32)) | (type << 32);
}

void CharSequence::indexBoundCheck(tlint index) {
	if (index < 0 || index >= mLength) {
		throw IndexOutOfBoundsException();
	}
}

const char* CharSequence::toCharArray() {
	return mSequence;
}

Reference CharSequence::toString() {
	return Reference(new String(mSequence));
}

char CharSequence::charAt(tlint index) {
	indexBoundCheck(index);
	return mSequence[index];
}

type_t CharSequence::type() {
	return CLASS_SERIAL;
}

bool CharSequence::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
