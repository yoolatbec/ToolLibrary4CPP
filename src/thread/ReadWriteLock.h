/*
 * ReadWriteLock.h
 *
 *  Created on: Mar 24, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_READWRITELOCK_H_
#define THREAD_READWRITELOCK_H_

#include <tl/lang/Object.h>

namespace tl {
namespace thread {

class ReadWriteLock: public virtual lang::Object {
public:
	ReadWriteLock();
	virtual ~ReadWriteLock();
	ReadWriteLock(const ReadWriteLock &other) = delete;
	ReadWriteLock& operator=(const ReadWriteLock &other) = delete;
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_READWRITELOCK_H_ */
