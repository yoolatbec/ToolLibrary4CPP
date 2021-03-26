/*
 * IrrecoverableException.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_IRRECOVERABLEEXCEPTION_H_
#define TL_THREAD_IRRECOVERABLEEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class IrrecoverableException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 208;
	const static constexpr char *DEFAULT_MESSAGE = "IrrecoverableException:";
	static Reference sDefaultMessage;
public:
	IrrecoverableException();
	IrrecoverableException(const char*);
	virtual ~IrrecoverableException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_IRRECOVERABLEEXCEPTION_H_ */
