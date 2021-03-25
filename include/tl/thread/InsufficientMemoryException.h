/*
 * InsufficientMemoryException.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_INSUFFICIENTMEMORYEXCEPTION_H_
#define TL_THREAD_INSUFFICIENTMEMORYEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class InsufficientMemoryException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 294;
	const static constexpr char *DEFAULT_MESSAGE =
		"InsufficientMemoryException:";
	static Reference sDefaultMessage;
public:
	InsufficientMemoryException();
	InsufficientMemoryException(const char*);
	virtual ~InsufficientMemoryException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_INSUFFICIENTMEMORYEXCEPTION_H_ */
