/*
 * ReadWriteLock.cpp
 *
 *  Created on: Mar 24, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/ErrorChecker.h>
#include <tl/lang/UnacceptableArgumentException.h>
#include <tl/thread/ReadWriteLock.h>

namespace tl {
namespace thread {

using lang::UnacceptableArgumentException;

ReadWriteLock::ReadWriteLock(bool shared) {
	// TODO Auto-generated constructor stub
	pthread_rwlockattr_t attr;
	if (shared) {
		pthread_rwlockattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
	} else {
		pthread_rwlockattr_setpshared(&attr, PTHREAD_PROCESS_PRIVATE);
	}

	mShared = shared;
	mLock = pthread_rwlock_init(&mLock, &attr);

	mHashCode = genHashCode(CLASS_SERIAL);
}

ReadWriteLock::~ReadWriteLock() {
	// TODO Auto-generated destructor stub
	pthread_rwlock_destroy(&mLock);
}

bool ReadWriteLock::isShared() {
	return mShared;
}

void ReadWriteLock::readLock() {
	pthread_rwlock_rdlock(&mLock);
}

void ReadWriteLock::writeLock() {
	pthread_rwlock_wrlock(&mLock);
}

void ReadWriteLock::timedReadLock(tlint sec, tlint nano) {
	if (sec < 0 || nano < 0) {
		throw UnacceptableArgumentException();
	}

	timespec timeout;
	timeout.tv_sec = sec;
	timeout.tv_nsec = nano;

	tlint err = pthread_rwlock_timedrdlock(&mLock, &timeout);
	ErrorChecker::check(err);
}

void ReadWriteLock::timedWriteLock(tlint sec, tlint nano) {
	if (sec < 0 || nano < 0) {
		throw UnacceptableArgumentException();
	}

	timespec timeout;
	timeout.tv_sec = sec;
	timeout.tv_nsec = nano;

	tlint err = pthread_rwlock_timedwrlock(&mLock, &timeout);
	ErrorChecker::check(err);
}

void ReadWriteLock::tryReadLock() {
	tlint err = pthread_rwlock_tryrdlock(&mLock);
	ErrorChecker::check(err);
}

void ReadWriteLock::tryWriteLock() {
	tlint err = pthread_rwlock_trywrlock(&mLock);
	ErrorChecker::check(err);
}

void ReadWriteLock::unlock() {
	tlint err = pthread_rwlock_unlock(&mLock);
	ErrorChecker::check(err);
}

type_t ReadWriteLock::type() {
	return CLASS_SERIAL;
}

bool ReadWriteLock::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
