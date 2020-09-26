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
	// TODO Auto-generated constructor stub
	mRef = new size_t;
	*mRef = 1;
}

Reference::~Reference() {
	// TODO Auto-generated destructor stub
	if ((*mRef) == 1) {
		delete mEntity;
		delete mRef;
	}
}

Reference::Reference(const Reference &other)
		: mEntity(other.mEntity) {
	// TODO Auto-generated constructor stub
	mRef = other.mRef;
	(*mRef)++;
}

hash_t Reference::getType() const {
	return Object::instanceof(*mEntity);
}

void* Reference::getEntity() const {
	return mEntity;
}

} /* namespace lang */
} /* namespace tl */
