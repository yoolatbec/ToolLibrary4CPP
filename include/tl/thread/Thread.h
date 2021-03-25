/*
 * Thread.h
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_THREAD_H_
#define INCLUDE_THREAD_THREAD_H_

#include <tl/lang/Reference.h>
#include <tl/lang/Runnable.h>

namespace tl {
namespace thread {

using lang::Reference;

class Thread: public virtual lang::Runnable {
private:
	const static type_t CLASS_SERIAL = 40;
protected:
	pthread_t mThread;
	Reference mTarget;
	Reference mName;
	Reference mAttribute;

	bool mStatus;
public:
	Thread(Reference target);
	Thread(Reference, Reference);
	Thread(Reference target, Reference attribute, Reference name);
	virtual ~Thread();
	Thread(const Thread &other) = delete;
	Thread& operator=(const Thread &other) = delete;
	void run();
//	bool isRunning();
	void setName(Reference);
	Reference getName();
	void setAttribute(Reference);
	static void cancel(Reference);
	Reference join();
	void detach();
	static void yield();
//	void sleep(tlint);
	bool equals(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_THREAD_H_ */
