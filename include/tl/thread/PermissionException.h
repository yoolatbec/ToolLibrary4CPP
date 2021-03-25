/*
 * PermissionException.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_PERMISSIONEXCEPTION_H_
#define TL_THREAD_PERMISSIONEXCEPTION_H_

#include <tl/thread/ThreadException.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace thread {

using lang::Reference;

class PermissionException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 124;
	const static constexpr char *DEFAULT_MESSAGE = "PermissionException:";
	static Reference sDefaultMessage;
public:
	PermissionException();
	PermissionException(const char*);
	virtual ~PermissionException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_PERMISSIONEXCEPTION_H_ */
