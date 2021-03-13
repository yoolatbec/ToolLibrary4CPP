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

namespace tl {
namespace thread {

using lang::Pointer;

Thread::Thread(Reference target) {
	// TODO Auto-generated constructor stub
	dismissNull(target);
	argumentTypeCheck(target, Function::type());

	mTarget = target;
	mThread = -1;
}

Thread::Thread(Reference target, Reference ref){
	dismissNull(target);
	argumentTypeCheck(target, Function::type());


}

void Thread::run(){
	Function* func = dynamic_cast<Function*>(mTarget.getEntity());

	pthread_attr_t attr;
	if(!mAttribute.isNull()){
		ThreadAttribute* attribute = dynamic_cast<ThreadAttribute*>(mAttribute.getEntity()));
		attr = attribute->getAttribute();
	} else {
		if(pthread_attr_init(&attr) != 0){
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

} /* namespace thread */
} /* namespace tl */
