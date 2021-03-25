/*
 * NoSuchThreadException.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_NOSUCHTHREADEXCEPTION_H_
#define TL_THREAD_NOSUCHTHREADEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class NoSuchThreadException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 345;
	const static constexpr char *DEFAULT_MESSAGE = "NoSuchThreadException:";
	static Reference sDefaultMessage;
public:
	NoSuchThreadException();
	NoSuchThreadException(const char*);
	virtual ~NoSuchThreadException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_NOSUCHTHREADEXCEPTION_H_ */
