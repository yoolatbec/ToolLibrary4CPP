/*
 * Condition.h
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_CONDITION_H_
#define INCLUDE_THREAD_CONDITION_H_

#include <lang/Reference.h>

namespace tl {
namespace thread {

class Condition: public lang::Object {
public:
	Condition();
	virtual ~Condition();
	Condition(const Condition &other) = delete;
	Condition& operator=(const Condition &other) = delete;
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_CONDITION_H_ */
