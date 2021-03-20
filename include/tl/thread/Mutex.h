/*
 * Mutex.h
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_MUTEX_H_
#define INCLUDE_THREAD_MUTEX_H_

#include <pthread.h>
#include <tl/lang/Reference.h>


namespace tl {
namespace thread {

using lang::Reference;

class Mutex: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 70;

	pthread_mutex_t mMutex;
	Mutex(Reference);
	Mutex();
	void makeConsistent();
public:
	virtual ~Mutex();
	Mutex(const Mutex &other) = delete;
	Mutex& operator=(const Mutex &other) = delete;
	Reference newInstance(Reference);
	Reference newInstance();
	pthread_mutex_t* getValue();
	void lock();
	void tryLock();
	void unlock();
	void timedLock(tlint, tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_MUTEX_H_ */
