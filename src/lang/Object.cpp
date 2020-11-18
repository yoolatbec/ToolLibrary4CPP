/*
 * Object.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "Reference.h"
#include "String.h"
#include <cstdio>

namespace tl {
namespace lang {

Object::Object() {
	// TODO Auto-generated constructor stub
	mHash = genHash();
}

Object::Object(const Reference& another) {
	// TODO Auto-generated constructor stub
	mHash = genHash();
}

Object::~Object() {

}

hash_t Object::genHash() {
	return (CLASS_HASH & CLASS_MASK) + ((hash_t)this & INSTANCE_MASK);
}

bool Object::equals(const Reference& other) const {
	return this->mHash == other.getEntity()->mHash;
}

bool Object::operator==(const Reference& other) const {
	return equals(other);
}

Object* Object::clone() const {
	return new Object;
}

bool Object::instanceof(hash_t type) const {
	return CLASS_HASH == type;
}

String* Object::toString() const {
	char str[20];
	sprintf(str, "%llX", mHash);
	return new String(str);
}

hash_t Object::type() const{
	return mHash & CLASS_MASK;
}

hash_t Object::getType(){
	return CLASS_HASH;
}

hash_t Object::hashcode() const{
	return mHash;
}

} /* namespace lang */
} /* namespace tl */
