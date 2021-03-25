/*
 * Barrier.cpp
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/Barrier.h>
#include <tl/thread/BarrierAttribute.h>
#include "ErrorChecker.h"

namespace tl {
namespace thread {

using lang::Reference;

Barrier::Barrier(tlint count) {
	// TODO Auto-generated constructor stub
	tlint err = pthread_barrier_init(&mBarrier, nullptr, count);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Barrier::Barrier(Reference attri, tlint count) {
	dismissNull(attri);
	argumentTypeCheck(attri, BarrierAttribute::type());

	BarrierAttribute *attr = dynamic_cast<BarrierAttribute*>(attri.getEntity());
	tlint err = pthread_barrier_init(&mBarrier, attr->getAttribute(), count);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Barrier::~Barrier() {
	// TODO Auto-generated destructor stub
	pthread_barrier_destroy(&mBarrier);
}

void Barrier::wait() {
	pthread_barrier_wait(&mBarrier);
}

type_t Barrier::type() {
	return CLASS_SERIAL;
}

bool Barrier::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
