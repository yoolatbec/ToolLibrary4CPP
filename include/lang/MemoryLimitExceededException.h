/*
 * MemoryLimitExceededException.h
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_
#define INCLUDE_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_

#include <lang/Exception.h>

namespace tl {
namespace lang {

class MemoryLimitExceededException: public Exception {
public:
	MemoryLimitExceededException();
	virtual ~MemoryLimitExceededException();
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_ */
