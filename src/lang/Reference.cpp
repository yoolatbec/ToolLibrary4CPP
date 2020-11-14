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
	mRef = nullptr;
	// TODO Auto-generated constructor stub
	if (mEntity != nullptr) {
		mRef = new size_t;
		*mRef = 1;
	}
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

Reference& Reference::operator=(const Reference &other) {
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
	if(mRef != nullptr){
		(*mRef)++;
	}

	return *this;
}

Reference::Reference(const Reference &other)
		: mEntity(other.mEntity) {
	// TODO Auto-generated constructor stub
	mRef = other.mRef;
	if (mEntity != nullptr) {
		(*mRef)++;
	}
}

hash_t Reference::getType() const {
	return mEntity->type();
}

Object* Reference::getEntity() const {
	return mEntity;
}

bool Reference::equals(const Reference &another) const {
	return mEntity == another.mEntity;
}

bool Reference::isNull() const {
	return mEntity == nullptr;
}

bool Reference::instanceof(hash_t type) const {
	return mEntity->instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
