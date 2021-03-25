/*
 * SpinLock.h
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_SPINLOCK_H_
#define TL_THREAD_SPINLOCK_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

using lang::Reference;

class SpinLock: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 3465;

	pthread_spinlock_t mLock;
	bool mShared;
public:
	SpinLock(bool);
	virtual ~SpinLock();
	SpinLock(const SpinLock &other) = delete;
	SpinLock& operator=(const SpinLock &other) = delete;
	bool isShared();
	void lock();
	void tryLock();
	void unlock();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_SPINLOCK_H_ */
