/*
 * ThreadAttribute.h
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_THREADATTRIBUTE_H_
#define INCLUDE_THREAD_THREADATTRIBUTE_H_

#include <tl/lang/Reference.h>
#include <pthread.h>

namespace tl {
namespace thread {

class ThreadAttribute: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 890;
	pthread_attr_t mAttribute;

//	void checkPriorityInput(tlint);
public:
//	enum SchedulePolicy{
//		SCHEDULE_FIFO,
//		SCHEDULE_RR,
//		SCHEDULE_OTHER
//	};

	ThreadAttribute();
	virtual ~ThreadAttribute();
	ThreadAttribute(const ThreadAttribute &other) = delete;
	ThreadAttribute& operator=(const ThreadAttribute &other) = delete;
	void setDetachable();
	bool isDetachable();
	void setStackGuardSize(tlint);
	tlint getStackGuardSize();
	void setSystemScope();
	bool isSystemScope();
//	void setSchedulePolicy(SchedulePolicy);
//	SchedulePolicy getSchedulePolicy();
//	void setPriority(tlint);
//	tlint getPriority();
	pthread_attr_t getAttribute();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_THREADATTRIBUTE_H_ */
