/*
 * ThreadAttribute.cpp
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/ThreadAttribute.h>

namespace tl {
namespace thread {

ThreadAttribute::ThreadAttribute() {
	// TODO Auto-generated constructor stub
	if(pthread_attr_init(&mAttribute) != 0){
		//cast an exception
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

ThreadAttribute::~ThreadAttribute() {
	// TODO Auto-generated destructor stub
	pthread_attr_destroy(&mAttribute);
}

void ThreadAttribute::setDetachable(){
	if(pthread_attr_setdetachstate(&mAttribute, PTHREAD_CREATE_DETACHED) != 0){
		//cast an exception
	}
}

bool ThreadAttribute::isDetachable(){
	tlint state;

	if(pthread_attr_getdetachstate(&mAttribute, &state) != 0){
		//cast an exception
	}

	return state == PTHREAD_CREATE_DETACHED;
}

void ThreadAttribute::setStackGuardSize(tlint size){
	if(pthread_attr_setguardsize(&mAttribute, size) != 0){
		//cast an exception
	}
}

tlint ThreadAttribute::getStackGuardSize(){
	size_t size;

	if(pthread_attr_getguardsize(&mAttribute, &size) != 0){
		//cast an exception
	}

	return (tlint)size;
}

void ThreadAttribute::setSystemScope(){
	if(pthread_attr_setscope(&mAttribute, PTHREAD_SCOPE_SYSTEM) != 0){
		//cast an exception
	}
}

bool ThreadAttribute::isSystemScope(){
	tlint scope;

	if(pthread_attr_getscope(&mAttribute, &scope) != 0){
		//cast an exception
	}

	return scope == PTHREAD_SCOPE_SYSTEM;
}

//void ThreadAttribute::setSchedulePolicy(SchedulePolicy policy){
//	tlint sp;
//
//	switch(policy){
//	case SCHEDULE_FIFO:
//		sp = SCHED_FIFO;
//		break;
//	case SCHEDULE_RR:
//		sp = SCHED_RR;
//		break;
//	default:
//		//cast an exception
//	}
//
//	if(pthread_attr_setschedpolicy(&mAttribute, sp) != 0){
//		//cast an exception
//	}
//}
//
//ThreadAttribute::SchedulePolicy ThreadAttribute::getSchedulePolicy(){
//	tlint sp;
//
//	if(pthread_attr_getschedpolicy(&mAttribute, &sp) != 0){
//		//cast an exception
//	}
//
//	ThreadAttribute::SchedulePolicy policy;
//	switch(sp){
//	case SCHED_FIFO:
//		policy = SCHEDULE_FIFO;
//		break;
//	case SCHED_RR:
//		policy = SCHEDULE_RR;
//		break;
//	default:
//		policy = SCHEDULE_OTHER;
//		break;
//	}
//
//	return policy;
//}
//
//void ThreadAttribute::setPriority(tlint priority){
//	checkPriorityInput(priority);
//
//	sched_param parameter;
//	parameter.sched_priority = priority;
//
//	if(pthread_attr_setschedparam(&mAttribute, &parameter) != 0){
//		//cast an exception
//	}
//}
//
//tlint ThreadAttribute::getPriority(){
//	sched_param parameter;
//	if(pthread_attr_getschedparam(&mAttribute, &parameter) != 0){
//		//cast an exception
//	}
//
//	return parameter.sched_priority;
//}
//
//void ThreadAttribute::checkPriorityInput(tlint p){
//	SchedulePolicy policy = getSchedulePolicy();
//
//	if(policy == SCHEDULE_OTHER){
//		if(p != 0){
//			//cast an exception
//		}
//
//		return;
//	}
//
//	if(policy == SCHEDULE_FIFO || policy == SCHEDULE_RR){
//		if(p < 0 || p > 99){
//			//cast an exception
//		}
//
//		return;
//	}
//
//	//cast an exception
//}

pthread_attr_t ThreadAttribute::getAttribute(){
	return mAttribute;
}

type_t ThreadAttribute::type(){
	return CLASS_SERIAL;
}

bool ThreadAttribute::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
