/*
 * Reference.cpp
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Reference.h>

namespace tl {
namespace lang {

Reference::Reference(Object *entity, bool autoFree)
		: mEntity(entity), mAutoFree(autoFree) {
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
			if (mAutoFree) {
				delete mEntity;
			}
			delete mRef;
		} else {
			(*mRef)--;
		}
	}
}

Reference& Reference::operator=(Reference other) {
	if (mEntity != nullptr) {
		if ((*mRef) == 1) {
			if (mAutoFree) {
				delete mEntity;
			}
			delete mRef;
		} else {
			(*mRef)--;
		}
	}

	mEntity = other.mEntity;
	mRef = other.mRef;
	mAutoFree = other.mAutoFree;
	if (mEntity != nullptr) {
		(*mRef)++;
	}

	return *this;
}

Reference::Reference(const Reference &other) {
	// TODO Auto-generated constructor stub
	if (mEntity != nullptr) {
		if ((*mRef) == 1) {
			if (mAutoFree) {
				delete mEntity;
			}
			delete mRef;
		} else {
			(*mRef)--;
		}
	}

	mRef = other.mRef;
	mEntity = other.mEntity;
	mAutoFree = other.mAutoFree;
	if (mEntity != nullptr) {
		(*mRef)++;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

Object* Reference::getEntity() const {
	return mEntity;
}

type_t Reference::entityType() const {
	if (isNull()) {
		//cast an exception
	}

	return mEntity->type();
}

bool Reference::equals(Reference another) const {
	if (another.isNull()) {
		return isNull();
	}

	if (isNull()) {
		return false;
	}

	return mEntity->hashCode() == another.mEntity->hashCode();
}

bool Reference::isNull() const {
	return mEntity == nullptr;
}

type_t Reference::type() {
	return CLASS_SERIAL;
}

bool Reference::instanceof(type_t type) const {
	return CLASS_SERIAL == type || Object::type() == type;
}

} /* namespace lang */
} /* namespace tl */
