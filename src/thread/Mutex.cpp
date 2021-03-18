/*
 * Mutex.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#include <tl/thread/Mutex.h>
#include "MutexAttribute.h"
#include "ErrorCode.h"

namespace tl {
namespace thread {



Mutex::Mutex(Reference ref) {
	// TODO Auto-generated constructor stub
	if(ref.isNull()){
		pthread_mutex_init(&mMutex, nullptr);
	} else {
		MutexAttribute* attribute = dynamic_cast<MutexAttribute*>(ref.getEntity());
		pthread_mutexattr_t attr = attribute->getAttribute();
		pthread_mutex_init(&mMutex, &attr);
	}
}

void Mutex::lock(){

}

void Mutex::makeConsistent(){
	if(pthread_mutex_consistent(&mMutex) != ErrorCode::SUCCESS){
		//cast an exception
	}
}

Mutex::~Mutex() {
	// TODO Auto-generated destructor stub
}

} /* namespace thread */
} /* namespace tl */
