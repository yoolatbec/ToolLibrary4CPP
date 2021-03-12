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

class Mutex: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 70;
protected:
	pthread_mutex_t mMutex;
public:
	Mutex();
	virtual ~Mutex();
	Mutex(const Mutex &other) = delete;
	Mutex& operator=(const Mutex &other) = delete;
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_MUTEX_H_ */
