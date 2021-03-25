/*
 * SystemLimitExceededException.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_SYSTEMLIMITEXCEEDEDEXCEPTION_H_
#define TL_THREAD_SYSTEMLIMITEXCEEDEDEXCEPTION_H_

#include <tl/thread/ThreadException.h>

namespace tl {
namespace thread {

class SystemLimitExceededException: public virtual ThreadException {
private:
	const static type_t CLASS_SERIAL = 980;
	const static constexpr char *DEFAULT_MESSAGE =
		"SystemLimitExceededException:";
	static Reference sDefaultMessage;
public:
	SystemLimitExceededException();
	SystemLimitExceededException(const char*);
	virtual ~SystemLimitExceededException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_SYSTEMLIMITEXCEEDEDEXCEPTION_H_ */
