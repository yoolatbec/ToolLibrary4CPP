/*
 * Barrier.h
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_BARRIER_H_
#define TL_THREAD_BARRIER_H_

#include <tl/lang/Reference.h>
#include <pthread.h>

namespace tl {
namespace thread {

using lang::Reference;

class Barrier: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 246;

	pthread_barrier_t mBarrier;
public:
	Barrier(tlint);
	Barrier(Reference, tlint);
	virtual ~Barrier();
	Barrier(const Barrier &other) = delete;
	Barrier& operator=(const Barrier &other) = delete;
	void wait();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_BARRIER_H_ */
