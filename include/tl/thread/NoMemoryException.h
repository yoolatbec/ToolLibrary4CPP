/*
 * NoMemoryException.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_NOMEMORYEXCEPTION_H_
#define TL_THREAD_NOMEMORYEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class NoMemoryException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 324;
	const static constexpr char *DEFAULT_MESSAGE = "NoMemoryException:";
	static Reference sDefaultMessage;
public:
	NoMemoryException();
	NoMemoryException(const char*);
	virtual ~NoMemoryException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_NOMEMORYEXCEPTION_H_ */
