/*
 * FailedToExecuteException.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_FAILEDTOEXECUTEEXCEPTION_H_
#define TL_THREAD_FAILEDTOEXECUTEEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace thread {

using lang::Reference;

class FailedToExecuteException: public virtual lang::Exception {
private:
	const static type_t CLASS_SERIAL = 560;
	const static constexpr char *DEFAULT_MESSAGE = "FailedToExecuteException:";
	static Reference sDefaultMessage;
public:
	FailedToExecuteException();
	FailedToExecuteException(const char*);
	virtual ~FailedToExecuteException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_FAILEDTOEXECUTEEXCEPTION_H_ */
