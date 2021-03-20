/*
 * MutexAttribute.h
 *
 *  Created on: Mar 14, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_MUTEXATTRIBUTE_H_
#define TL_THREAD_MUTEXATTRIBUTE_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

class MutexAttribute: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 832;

	pthread_mutexattr_t mAttribute;
public:
	enum class MutexType{
		NORMAL,
		ERROR_CHECK,
		RECURSIVE,
		DEFAULT
	};

	MutexAttribute();
	virtual ~MutexAttribute();
	MutexAttribute(const MutexAttribute &other) = delete;
	MutexAttribute& operator=(const MutexAttribute &other) = delete;
	pthread_mutexattr_t* getAttribute();
	void setShared(bool);
	bool isShared();
	void setMutexType(MutexType);
	MutexType getMutexType();
	void setRobust(bool);
	bool isRobust();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_MUTEXATTRIBUTE_H_ */
