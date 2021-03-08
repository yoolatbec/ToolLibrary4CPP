/*
 * Thread.h
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_THREAD_H_
#define INCLUDE_THREAD_THREAD_H_

#include <lang/Reference.h>
#include <lang/Runnable.h>

namespace tl {
namespace thread {

using lang::Reference;

class Thread: public virtual lang::Runnable {
protected:
	pthread_t mThread;
	Reference mTarget;
public:
	Thread();
	Thread(Reference);
	Thread(Reference, Reference);
	virtual ~Thread();
	Thread(const Thread &other) = delete;
	Thread& operator=(const Thread &other) = delete;
	virtual void run();
	void start();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_THREAD_H_ */
