/*
 * DeadOwnerException.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_DEADOWNEREXCEPTION_H_
#define TL_THREAD_DEADOWNEREXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class DeadOwnerException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 358;
	const static constexpr char *DEFAULT_MESSAGE = "DeadOwnerException:";
	static Reference sDefaultMessage;
public:
	DeadOwnerException();
	DeadOwnerException(const char*);
	virtual ~DeadOwnerException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_DEADOWNEREXCEPTION_H_ */
