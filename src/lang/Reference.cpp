/*
 * Reference.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#include "Reference.h"

namespace tl {
namespace lang {

Reference::Reference(Object *entity)
		: mEntity(entity) {
	if (mEntity != nullptr) {
		mRef = new size_t;
		(*mRef) = 1;
	} else {
		mRef = nullptr;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference::~Reference() {
	// TODO Auto-generated destructor stub
	if (mEntity != nullptr) {
		if ((*mRef) == 1) {
			delete mEntity;
			delete mRef;
		} else {
			(*mRef)--;
		}
	}
}

Reference& Reference::operator=(Reference other) {
	if (mEntity != nullptr) {
		if ((*mRef) == 1) {
			delete mEntity;
			delete mRef;
		} else {
			(*mRef)--;
		}
	}
	mEntity = other.mEntity;
	mRef = other.mRef;
	if (mRef != nullptr) {
		(*mRef)++;
	}

	return *this;
}

Reference::Reference(Reference other)
		: mEntity(other.mEntity) {
	// TODO Auto-generated constructor stub
	mRef = other.mRef;
	if (mEntity != nullptr) {
		(*mRef)++;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

Object* Reference::getEntity() {
	return mEntity;
}

type_t Reference::entityType() {
	return mEntity->type();
}

bool Reference::equals(Reference another) {
	return mEntity == another.mEntity;
}

bool Reference::isNull() {
	return mEntity == nullptr;
}

type_t Reference::type() {
	return CLASS_SERIAL;
}

bool Reference::instanceof(type_t type){
	return CLASS_SERIAL == type || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
