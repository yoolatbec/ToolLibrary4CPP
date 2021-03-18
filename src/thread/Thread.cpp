/*
 * Thread.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Pointer.h>
#include <tl/thread/Thread.h>
#include <tl/thread/ThreadAttribute.h>
#include "Function.h"
#include "ErrorCode.h"

namespace tl {
namespace thread {

using lang::Pointer;

Thread::Thread(Reference target) {
	// TODO Auto-generated constructor stub
	dismissNull(target);
	argumentTypeCheck(target, Function::type());

	mTarget = target;
	mThread = -1;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Thread::Thread(Reference target, Reference ref){
	dismissNull(target);
	argumentTypeCheck(target, Function::type());


}

void Thread::run(){
	Function* func = dynamic_cast<Function*>(mTarget.getEntity());

	pthread_attr_t attr;
	if(!mAttribute.isNull()){
		ThreadAttribute* attribute = dynamic_cast<ThreadAttribute*>(mAttribute.getEntity());
		attr = attribute->getAttribute();
	} else {
		if(pthread_attr_init(&attr) != ErrorCode::SUCCESS){
			//cast an exception
		}
	}

	Reference argument = func->getArgument();
	void* arg = nullptr;
	if(!argument.isNull()){
		Pointer* p = dynamic_cast<Pointer*>(argument.getEntity());
		arg = p->get();
	}

	pthread_create(&mThread, &attr, func->getFunction(), arg);
}

Thread::~Thread() {
	// TODO Auto-generated destructor stub
}

void Thread::setAttribute(Reference attr){
	dismissNull(attr);
	argumentTypeCheck(attr, ThreadAttribute::type());

	mAttribute = attr;
}

void Thread::join(){
	if(pthread_join(mThread, nullptr) != ErrorCode::SUCCESS){
		//cast an exception
	}
}

void Thread::detach(){
	if(pthread_detach(mThread) != ErrorCode::SUCCESS){
		//cast an exception
	}
}

void Thread::sleep(tlint sec, tlint nano){

}

bool Thread::equals(Reference ref){
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, Thread::type());

	Thread* t = dynamic_cast<Thread*>(ref.getEntity());

	return pthread_equal(mThread, t->mThread) != 0;
}

void Thread::yield(){
	tlint ret = sched_yield();
}

} /* namespace thread */
} /* namespace tl */
