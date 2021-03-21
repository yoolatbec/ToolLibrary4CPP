/*
 * BarrierAttribute.cpp
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#include "BarrierAttribute.h"

namespace tl {
namespace thread {

BarrierAttribute::BarrierAttribute() {
	// TODO Auto-generated constructor stub
	pthread_barrierattr_init(&mAttribute);

	mHashCode = genHashCode(CLASS_SERIAL);
}

BarrierAttribute::~BarrierAttribute() {
	// TODO Auto-generated destructor stub
	pthread_barrierattr_destroy(&mAttribute);
}

void BarrierAttribute::setShared(bool shared) {
	if (shared) {
		pthread_barrierattr_setpshared(&mAttribute, PTHREAD_PROCESS_SHARED);
	} else {
		pthread_barrierattr_setpshared(&mAttribute, PTHREAD_PROCESS_PRIVATE);
	}
}

bool BarrierAttribute::isShared() {
	tlint shared;
	pthread_barrierattr_getpshared(&mAttribute, &shared);

	return shared == PTHREAD_PROCESS_SHARED;
}

type_t BarrierAttribute::type() {
	return CLASS_SERIAL;
}

bool BarrierAttribute::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
