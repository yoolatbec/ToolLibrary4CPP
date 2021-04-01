/*
 * Object.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/IllegalArgumentTypeException.h>
#include <tl/lang/NullPointerException.h>
#include <tl/lang/IllegalArgumentException.h>
#include <tl/lang/String.h>
#include <cstdio>

namespace tl {
namespace lang {

Object::Object() {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Object::~Object() {

}

Object& Object::operator =(const Object &other) {
	return *this;
}

Object::Object(const Object &other) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

void Object::argumentTypeCheck(Reference ref, type_t type) {
	if (!ref.getEntity()->instanceof(type)) {
		throw IllegalArgumentTypeException();
	}
}

void Object::dismissNull(Reference ref) {
	if (ref.isNull()) {
		throw NullPointerException();
	}
}

void Object::dismissNegative(tlint i) {
	if (i < 0) {
		throw IllegalArgumentException();
	}
}

bool Object::equals(Reference other) {
	return operator==(other);
}

bool Object::operator ==(Reference other) {
	return this->mHashCode == other.getEntity()->mHashCode;
}

Reference Object::clone() {
	return Reference(new Object);
}

Reference Object::toString() {
	char hash[20];
	sprintf(hash, "%llX", mHashCode);
	return Reference(new String(hash));
}

bool Object::instanceof(type_t otherType) {
	return (CLASS_SERIAL == otherType);
}

hash_t Object::hashCode() {
	return mHashCode;
}

type_t Object::type() {
	return CLASS_SERIAL;
}

hash_t Object::genHashCode(type_t type) {
	return (hash_t)((((hash_t)this) ^ (((hash_t)this) >> 32)) | (type << 32));
}

} /* namespace lang */
} /* namespace tl */
