/*
 * DeadlockException.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_DEADLOCKEXCEPTION_H_
#define TL_THREAD_DEADLOCKEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class DeadlockException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 535;
	const static constexpr char *DEFAULT_MESSAGE = "DeadlockException:";
	static Reference sDefaultMessage;
public:
	DeadlockException();
	DeadlockException(const char*);
	virtual ~DeadlockException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_DEADLOCKEXCEPTION_H_ */
