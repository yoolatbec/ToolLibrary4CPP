/*
 * TimeOutException.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_TIMEOUTEXCEPTION_H_
#define TL_THREAD_TIMEOUTEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class TimeOutException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 254;
	const static constexpr char *DEFAULT_MESSAGE = "TimeOutException:";
	static Reference sDefaultMessage;
public:
	TimeOutException();
	TimeOutException(const char*);
	virtual ~TimeOutException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_TIMEOUTEXCEPTION_H_ */
