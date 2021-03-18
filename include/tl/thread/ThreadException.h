/*
 * ThreadException.h
 *
 *  Created on: Mar 16, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_THREADEXCEPTION_H_
#define TL_THREAD_THREADEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace thread {

using lang::Reference;

class ThreadException: public virtual lang::Exception {
private:
	const static type_t CLASS_SERIAL = 822;
	constexpr const static char* DEFAULT_MESSAGE = "ThreadException:";
	static Reference sDefaultMessage;
public:
	ThreadException();
	ThreadException(const char*);
	virtual ~ThreadException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_THREADEXCEPTION_H_ */
