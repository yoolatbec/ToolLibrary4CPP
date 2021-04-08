/*
 * Mutex.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/Mutex.h>
#include <tl/thread/ErrorChecker.h>
#include <time.h>
#include <tl/thread/MutexAttribute.h>
#include <tl/lang/IllegalArgumentException.h>

namespace tl {
namespace thread {

using lang::Reference;
using lang::IllegalArgumentException;

Mutex::Mutex(Reference ref) {
	// TODO Auto-generated constructor stub
	dismissNull(ref);
	argumentTypeCheck(ref, MutexAttribute::type());

	MutexAttribute *attribute = dynamic_cast<MutexAttribute*>(ref.getEntity());
	tlint err = pthread_mutex_init(&mMutex, attribute->getAttribute());
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mutex::Mutex() {
	mMutex = PTHREAD_MUTEX_INITIALIZER;

	mHashCode = genHashCode(CLASS_SERIAL);
}

pthread_mutex_t* Mutex::getValue() {
	return &mMutex;
}

void Mutex::lock() {
	tlint err = pthread_mutex_lock(&mMutex);
	ErrorChecker::check(err);
}

void Mutex::makeConsistent() {
	tlint err = pthread_mutex_consistent(&mMutex);
	ErrorChecker::check(err);
}

void Mutex::tryLock() {
	tlint err = pthread_mutex_trylock(&mMutex);
	ErrorChecker::check(err);
}

void Mutex::unlock() {
	tlint err = pthread_mutex_unlock(&mMutex);
	ErrorChecker::check(err);
}

void Mutex::timedLock(tlint sec, tlint nano) {
	if (sec < 0 || nano < 0) {
		throw IllegalArgumentException();
	}

	timespec time;
	time.tv_sec = sec;
	time.tv_nsec = nano;

	tlint err = pthread_mutex_timedlock(&mMutex, &time);
	ErrorChecker::check(err);
}

Mutex::~Mutex() {
	// TODO Auto-generated destructor stub
	pthread_mutex_destroy(&mMutex);
}

type_t Mutex::type() {
	return CLASS_SERIAL;
}

bool Mutex::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
