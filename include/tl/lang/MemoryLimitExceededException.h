/*
 * MemoryLimitExceededException.h
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_
#define INCLUDE_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace lang {

class MemoryLimitExceededException: public Exception {
private:
	const static type_t CLASS_SERIAL = 77;
	constexpr const static char *DEFAULT_MESSAGE =
		"MemoryLimitExceededException:";
	static Reference sDefaultMessage;
public:
	MemoryLimitExceededException();
	MemoryLimitExceededException(const char*);
	virtual ~MemoryLimitExceededException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_ */
