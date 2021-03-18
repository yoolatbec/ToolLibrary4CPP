/*
 * ThreadOnceController.h
 *
 *  Created on: Mar 18, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_THREADONCECONTROLLER_H_
#define THREAD_THREADONCECONTROLLER_H_

#include <tl/lang/Object.h>
#include <pthread.h>

namespace tl {
namespace thread {

class ThreadOnceController: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 833;

public:
	ThreadOnceController();
	virtual ~ThreadOnceController();
	ThreadOnceController(const ThreadOnceController &other) = delete;
	ThreadOnceController& operator=(const ThreadOnceController &other) = delete;
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_THREADONCECONTROLLER_H_ */
