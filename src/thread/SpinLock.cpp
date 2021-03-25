/*
 * SpinLock.cpp
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/ErrorChecker.h>
#include <tl/thread/SpinLock.h>

namespace tl {
namespace thread {

SpinLock::SpinLock(bool shared) {
	// TODO Auto-generated constructor stub
	tlint err;
	if (shared) {
		err = pthread_spin_init(&mLock, PTHREAD_PROCESS_SHARED);
	} else {
		err = pthread_spin_init(&mLock, PTHREAD_PROCESS_PRIVATE);
	}

	ErrorChecker::check(err);
	mShared = shared;

	mHashCode = genHashCode(CLASS_SERIAL);
}

SpinLock::~SpinLock() {
	// TODO Auto-generated destructor stub
	pthread_spin_destroy(&mLock);
}

bool SpinLock::isShared() {
	return mShared;
}

void SpinLock::lock() {
	tlint err = pthread_spin_lock(&mLock);
	ErrorChecker::check(err);
}

void SpinLock::tryLock() {
	tlint err = pthread_spin_trylock(&mLock);
	ErrorChecker::check(err);
}

void SpinLock::unlock() {
	tlint err = pthread_spin_unlock(&mLock);
	ErrorChecker::check(err);
}

type_t SpinLock::type() {
	return CLASS_SERIAL;
}

bool SpinLock::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
