/*
 * Thread.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/Thread.h>
#include <tl/thread/ThreadAttribute.h>
#include <tl/thread/ErrorChecker.h>
#include <tl/lang/Pointer.h>
#include <tl/lang/String.h>
#include <tl/lang/IllegalArgumentTypeException.h>
#include <tl/lang/UnacceptableArgumentException.h>
#include <tl/thread/Function.h>

#include <unistd.h>

namespace tl {
namespace thread {

using lang::Pointer;
using lang::IllegalArgumentTypeException;
using lang::IllegalArgumentException;
using lang::String;

Thread::Thread(Reference target) {
	// TODO Auto-generated constructor stub
	dismissNull(target);
	argumentTypeCheck(target, Function::type());

	mTarget = target;
	mThread = -1;
	mStatus = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Thread::Thread(Reference target, Reference ref) {
	dismissNull(target);
	argumentTypeCheck(target, Function::type());

	mTarget = target;

	if (ref.getEntity()->instanceof(ThreadAttribute::type())) {
		mAttribute = ref;
	} else if (ref.getEntity()->instanceof(String::type())) {
		mName = ref;
	} else {
		//cast an exception
		throw IllegalArgumentTypeException();
	}

	mThread = -1;
	mStatus = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Thread::Thread(Reference target, Reference attribute, Reference name) {
	dismissNull(target);
	dismissNull(attribute);
	dismissNull(name);
	argumentTypeCheck(target, Function::type());
	argumentTypeCheck(attribute, ThreadAttribute::type());
	argumentTypeCheck(name, String::type());

	mTarget = target;
	mAttribute = attribute;
	mName = name;

	mThread = -1;
	mStatus = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void Thread::run() {
	tlint err = 0;

	pthread_attr_t attr;
	if (!mAttribute.isNull()) {
		ThreadAttribute *attribute =
			dynamic_cast<ThreadAttribute*>(mAttribute.getEntity());
		attr = attribute->getAttribute();
	} else {
		err = pthread_attr_init(&attr);
		ErrorChecker::check(err);
	}

	Function *func = dynamic_cast<Function*>(mTarget.getEntity());
	Reference argument = func->getArgument();
	void *arg = nullptr;
	if (!argument.isNull()) {
		Pointer *p = dynamic_cast<Pointer*>(argument.getEntity());
		arg = p->get();
	}

	err = pthread_create(&mThread, &attr, func->getFunction(), arg);
	ErrorChecker::check(err);
}

Thread::~Thread() {
	// TODO Auto-generated destructor stub
}

void Thread::setAttribute(Reference attr) {
	dismissNull(attr);
	argumentTypeCheck(attr, ThreadAttribute::type());

	mAttribute = attr;
}

void Thread::setName(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, String::type());

	mName = ref;
}

Reference Thread::getName() {
	return mName;
}

Reference Thread::join() {
	void *status = nullptr;
	tlint err = pthread_join(mThread, &status);
	ErrorChecker::check(err);

	return Reference(new Pointer(status, sizeof(void*)));

}

void Thread::detach() {
	tlint err = pthread_detach(mThread);
	ErrorChecker::check(err);
}

//void Thread::sleep(tlint mili) {
//	if (mili <= 0) {
//		throw UnacceptableArgumentException();
//	}
//
//	usleep(mili);
//}

bool Thread::equals(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Thread::type());

	Thread *t = dynamic_cast<Thread*>(ref.getEntity());

	return pthread_equal(mThread, t->mThread) != 0;
}

void Thread::yield() {
	tlint err = sched_yield();
	ErrorChecker::check(err);
}

void Thread::cancel(Reference t) {
	dismissNull(t);
	argumentTypeCheck(t, Thread::type());

	Thread *thread = dynamic_cast<Thread*>(t.getEntity());
	tlint err = pthread_cancel(thread->mThread);

	ErrorChecker::check(err);
}

type_t Thread::type() {
	return CLASS_SERIAL;
}

bool Thread::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Runnable::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
