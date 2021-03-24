/*
 * MutexAttribute.cpp
 *
 *  Created on: Mar 14, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/UnacceptableArgumentException.h>
#include <tl/thread/ErrorChecker.h>
#include <tl/thread/MutexAttribute.h>

namespace tl {
namespace thread {

using lang::UnacceptableArgumentException;
using MutexAttribute::MutexType;

MutexAttribute::MutexAttribute() {
	// TODO Auto-generated constructor stub
	tlint err = pthread_mutexattr_init(&mAttribute);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

MutexAttribute::~MutexAttribute() {
	// TODO Auto-generated destructor stub
	pthread_mutexattr_destroy(&mAttribute);
}

pthread_mutexattr_t* MutexAttribute::getAttribute() {
	return &mAttribute;
}

void MutexAttribute::setShared(bool isShared) {
	if (isShared) {
		pthread_mutexattr_setpshared(&mAttribute, PTHREAD_PROCESS_SHARED);
	} else {
		pthread_mutexattr_setpshared(&mAttribute, PTHREAD_PROCESS_PRIVATE);
	}
}

bool MutexAttribute::isShared() {
	tlint shared;
	pthread_mutexattr_getpshared(&mAttribute, &shared);

	return shared == PTHREAD_PROCESS_SHARED;
}

void MutexAttribute::setMutexType(MutexType type) {
	switch (type) {
	case MutexType::NORMAL:
		pthread_mutexattr_settype(&mAttribute, PTHREAD_MUTEX_NORMAL);
		break;
	case MutexType::ERROR_CHECK:
		pthread_mutexattr_settype(&mAttribute, PTHREAD_MUTEX_ERRORCHECK);
		break;
	case MutexType::RECURSIVE:
		pthread_mutexattr_settype(&mAttribute, PTHREAD_MUTEX_RECURSIVE);
		break;
	case MutexType::DEFAULT:
		pthread_mutexattr_settype(&mAttribute, PTHREAD_MUTEX_DEFAULT);
		break;
	default:
		//cast an exception
		throw UnacceptableArgumentException();
	}
}

MutexType MutexAttribute::getMutexType() {
	tlint type;
	pthread_mutexattr_gettype(&mAttribute, &type);

	MutexType mutexType;
	switch (type) {
	case PTHREAD_MUTEX_NORMAL:
		mutexType = MutexType::NORMAL;
		break;
	case PTHREAD_MUTEX_ERRORCHECK:
		mutexType = MutexType::ERROR_CHECK;
		break;
	case PTHREAD_MUTEX_RECURSIVE:
		mutexType = MutexType::RECURSIVE;
		break;
	}

	return mutexType;
}

void MutexAttribute::setRobust(bool robust) {
	if (robust) {
		pthread_mutexattr_setrobust(&mAttribute, PTHREAD_MUTEX_ROBUST);
	} else {
		pthread_mutexattr_setrobust(&mAttribute, PTHREAD_MUTEX_STALLED);
	}
}

bool MutexAttribute::isRobust() {
	tlint robust;
	pthread_mutexattr_getrobust(&mAttribute, &robust);
	return robust == PTHREAD_MUTEX_ROBUST;
}

type_t MutexAttribute::type() {
	return CLASS_SERIAL;
}

bool MutexAttribute::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
