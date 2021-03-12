/*
 * ThreadAttribute.h
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_THREAD_THREADATTRIBUTE_H_
#define INCLUDE_THREAD_THREADATTRIBUTE_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

class ThreadAttribute: public lang::Object {
public:
	ThreadAttribute();
	virtual ~ThreadAttribute();
	ThreadAttribute(const ThreadAttribute &other) = delete;
	ThreadAttribute& operator=(const ThreadAttribute &other) = delete;
};

} /* namespace thread */
} /* namespace tl */

#endif /* INCLUDE_THREAD_THREADATTRIBUTE_H_ */
