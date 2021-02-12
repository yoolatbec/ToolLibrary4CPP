/*
 * ThreadAttribute.h
 *
 *  Created on: Feb 5, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_THREAD_THREADATTRIBUTE_H_
#define SRC_THREAD_THREADATTRIBUTE_H_

#include "../lang/Reference.h"

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

#endif /* SRC_THREAD_THREADATTRIBUTE_H_ */
