/*
 * Function.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef THREAD_FUNCTION_H_
#define THREAD_FUNCTION_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

typedef void* (*fp)(void*);
class Function: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 893;

	fp mFunction;
	Reference mArguments;

public:
	Function(fp);
	virtual ~Function();
	Function(const Function &other) = delete;
	Function& operator=(const Function &other) = delete;
	fp getFunction();
	void* perform(void*);
	void* perform();
	void setArgument(Reference);
	void setArgument(void*);
	Reference getArgument();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* THREAD_FUNCTION_H_ */
