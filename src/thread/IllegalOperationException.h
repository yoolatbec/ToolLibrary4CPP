/*
 * IllegalOperationException.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_ILLEGALOPERATIONEXCEPTION_H_
#define THREAD_ILLEGALOPERATIONEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace thread {

using lang::Reference;

class IllegalOperationException: public virtual lang::Exception {
private:
	const static type_t CLASS_SERIAL = 569;
	const static constexpr char * DEFAULT_MESSAGE = "IllegalOperationException:";
	static Reference sDefaultMessage;
public:
	IllegalOperationException();
	IllegalOperationException(const char*);
	virtual ~IllegalOperationException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_ILLEGALOPERATIONEXCEPTION_H_ */
