/*
 * Condition.cpp
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/Condition.h>
#include <tl/thread/ConditionAttribute.h>
#include <tl/thread/Mutex.h>
#include <tl/thread/ErrorChecker.h>
#include <tl/lang/UnacceptableArgumentException.h>

namespace tl {
namespace thread {

using lang::Reference;
using lang::IllegalArgumentException;

Condition::Condition() {
	// TODO Auto-generated constructor stub
	tlint err = pthread_cond_init(&mCondition, nullptr);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Condition::Condition(Reference attribute) {
	dismissNull(attribute);
	argumentTypeCheck(attribute, ConditionAttribute::type());

	ConditionAttribute *attr =
		dynamic_cast<ConditionAttribute*>(attribute.getEntity());
	tlint err = pthread_cond_init(&mCondition, attr->getValue());
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Condition::~Condition() {
	// TODO Auto-generated destructor stub
	pthread_cond_destroy(&mCondition);
}

void Condition::waitOn(Reference lock) {
	dismissNull(lock);
	argumentTypeCheck(lock, Mutex::type());

	Mutex *mutex = dynamic_cast<Mutex*>(lock.getEntity());
	pthread_cond_wait(&mCondition, mutex->getValue());
}

void Condition::signal() {
	pthread_cond_signal(&mCondition);
}

void Condition::timedWait(Reference mutex, tlint sec, tlint nano) {
	dismissNull(mutex);
	argumentTypeCheck(mutex, Mutex::type());

	if (sec < 0 || nano < 0) {
		throw IllegalArgumentException();
	}

	timespec time;
	time.tv_sec = sec;
	time.tv_nsec = nano;

	Mutex *m = dynamic_cast<Mutex*>(mutex.getEntity());

	tlint err = pthread_cond_timedwait(&mCondition, m->getValue(), &time);
	ErrorChecker::check(err);
}

void Condition::broadcast() {
	pthread_cond_broadcast(&mCondition);
}

type_t Condition::type() {
	return CLASS_SERIAL;
}

bool Condition::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
