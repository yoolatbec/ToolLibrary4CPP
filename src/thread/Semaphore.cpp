/*
 * Semaphore.cpp
 *
 *  Created on: Mar 24, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/IllegalArgumentException.h>
#include <tl/thread/ErrorChecker.h>
#include <tl/thread/Semaphore.h>

namespace tl {
namespace thread {

using lang::IllegalArgumentException;

Semaphore::Semaphore(bool shared, tlint value) {
	// TODO Auto-generated constructor stub
	if (value <= 0) {
		throw IllegalArgumentException();
	}

	tlint err = sem_init(&mSemaphore, shared, value);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Semaphore::~Semaphore() {
	// TODO Auto-generated destructor stub
	sem_destroy(&mSemaphore);
}

void Semaphore::post() {
	sem_post(&mSemaphore);
}

void Semaphore::wait() {
	tlint err = sem_wait(&mSemaphore);
	ErrorChecker::check(err);
}

void Semaphore::tryWait() {
	tlint err = sem_trywait(&mSemaphore);
	ErrorChecker::check(err);
}

type_t Semaphore::type() {
	return CLASS_SERIAL;
}

bool Semaphore::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
