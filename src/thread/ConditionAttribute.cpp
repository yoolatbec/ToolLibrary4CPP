/*
 * ConditionAttribute.cpp
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/ConditionAttribute.h>
#include <tl/thread/ErrorChecker.h>

namespace tl {
namespace thread {

using lang::Reference;

ConditionAttribute::ConditionAttribute() {
	// TODO Auto-generated constructor stub
	tlint err = pthread_condattr_init(&mAttribute);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

ConditionAttribute::~ConditionAttribute() {
	// TODO Auto-generated destructor stub
	pthread_condattr_destroy(&mAttribute);
}

void ConditionAttribute::setShared(bool shared) {
	if (shared) {
		pthread_condattr_setpshared(&mAttribute, PTHREAD_PROCESS_SHARED);
	} else {
		pthread_condattr_setpshared(&mAttribute, PTHREAD_PROCESS_PRIVATE);
	}
}

bool ConditionAttribute::isShared() {
	tlint shared;
	pthread_condattr_getpshared(&mAttribute, &shared);

	return shared == PTHREAD_PROCESS_SHARED;
}

pthread_condattr_t* ConditionAttribute::getValue() {
	return &mAttribute;
}

type_t ConditionAttribute::type() {
	return CLASS_SERIAL;
}

bool ConditionAttribute::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
