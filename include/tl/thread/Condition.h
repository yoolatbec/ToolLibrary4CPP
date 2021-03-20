/*
 * Condition.h
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_CONDITION_H_
#define INCLUDE_THREAD_CONDITION_H_

#include <tl/lang/Reference.h>
#include <pthread.h>

namespace tl {
namespace thread {

using lang::Reference;

class Condition: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 345;

	pthread_cond_t mCondition;
public:
	Condition();
	Condition(Reference);
	virtual ~Condition();
	Condition(const Condition &other) = delete;
	Condition& operator=(const Condition &other) = delete;
	void waitOn(Reference);
	void signal();
	void timedWait(Reference, tlint, tlint);
	void broadcast();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_CONDITION_H_ */
