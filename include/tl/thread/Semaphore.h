/*
 * Semaphore.h
 *
 *  Created on: Mar 24, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_SEMAPHORE_H_
#define TL_THREAD_SEMAPHORE_H_

#include <tl/lang/Reference.h>
#include <semaphore.h>

namespace tl {
namespace thread {

using lang::Reference;

class Semaphore: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 248;
	const static tlint DEFAULT_VALUE = 1;

	sem_t mSemaphore;
public:
	Semaphore(bool, tlint = DEFAULT_VALUE);
	virtual ~Semaphore();
	Semaphore(const Semaphore &other) = delete;
	Semaphore& operator=(const Semaphore &other) = delete;
	void post();
	void wait();
	void tryWait();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_SEMAPHORE_H_ */
