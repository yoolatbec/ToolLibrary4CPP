/*
 * MemoryLimitExceededException.h
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_
#define SRC_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_

#include "Exception.h"

namespace tl {
namespace lang {

class MemoryLimitExceededException: public Exception {
public:
	MemoryLimitExceededException();
	virtual ~MemoryLimitExceededException();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_MEMORYLIMITEXCEEDEDEXCEPTION_H_ */
