/*
 * Object.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "String.h"
#include <cstdio>

namespace tl {
namespace lang {

Object::Object() {
	// TODO Auto-generated constructor stub
	mHash = genHash();
}

Object::Object(const Object &other) {
	// TODO Auto-generated constructor stub
	mHash = genHash();
}

Object& Object::operator =(const Object &other) {

}

Object::~Object() {

}

hash_t Object::genHash() {
	return CLASS_HASH & CLASS_MASK + this & INSTANCE_MASK;
}

bool Object::equals(const Object &other) const {
	return this->mHash == other.mHash;
}

bool Object::operator==(const Object& other) const{
	return equals(other);
}

Object Object::clone() const{

}

hash_t Object::instanceof(const Object &instance) {
	return mHash & CLASS_HASH;
}

tl::lang::String* Object::toString() const{
	char str[20];
	sprintf(str, "%X", mHash);
	return new String(str);
}



} /* namespace lang */
} /* namespace tl */
