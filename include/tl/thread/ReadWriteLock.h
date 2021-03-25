/*
 * ReadWriteLock.h
 *
 *  Created on: Mar 24, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_READWRITELOCK_H_
#define TL_THREAD_READWRITELOCK_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

class ReadWriteLock: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 249;

	pthread_rwlock_t mLock;
	bool mShared;
public:
	ReadWriteLock(bool);
	virtual ~ReadWriteLock();
	ReadWriteLock(const ReadWriteLock &other) = delete;
	ReadWriteLock& operator=(const ReadWriteLock &other) = delete;
	void readLock();
	void writeLock();
	void timedReadLock(tlint, tlint);
	void timedWriteLock(tlint, tlint);
	void tryReadLock();
	void tryWriteLock();
	void unlock();
	bool isShared();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_READWRITELOCK_H_ */
