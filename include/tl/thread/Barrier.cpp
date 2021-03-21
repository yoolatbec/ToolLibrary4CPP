/*
 * Barrier.cpp
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/Barrier.h>
#include "ErrorChecker.h"
#include <BarrierAttribute.h>

namespace tl {
namespace thread {

using lang::Reference;

Barrier::Barrier(tlint count) {
	// TODO Auto-generated constructor stub
	tlint err = pthread_barrier_init(&mBarrier, nullptr, count);
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

} /* namespace thread */
} /* namespace tl */
