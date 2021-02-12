/*
 * Mutex.h
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_THREAD_MUTEX_H_
#define SRC_THREAD_MUTEX_H_

#include "../lang/Reference.h"
#include <pthread.h>

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

#endif /* SRC_THREAD_MUTEX_H_ */
