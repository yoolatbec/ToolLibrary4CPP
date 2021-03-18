/*
 * MutexAttribute.h
 *
 *  Created on: Mar 14, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_MUTEXATTRIBUTE_H_
#define THREAD_MUTEXATTRIBUTE_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

class MutexAttribute: public virtual lang::Object {
public:
	MutexAttribute();
	virtual ~MutexAttribute();
	MutexAttribute(const MutexAttribute &other) = delete;
	MutexAttribute& operator=(const MutexAttribute &other) = delete;
	pthread_mutexattr_t getAttribute();
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_MUTEXATTRIBUTE_H_ */
