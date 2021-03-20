/*
 * SpinLock.h
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_SPINLOCK_H_
#define THREAD_SPINLOCK_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

using lang::Reference;

class SpinLock: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 3465;

	pthread_spinlock_t mValue;
public:
	SpinLock();
	virtual ~SpinLock();
	SpinLock(const SpinLock &other) = delete;
	SpinLock& operator=(const SpinLock &other) = delete;
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_SPINLOCK_H_ */
