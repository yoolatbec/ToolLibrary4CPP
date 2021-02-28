/*
 * UndefinedException.h
 *
 *  Created on: Feb 24, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_UNDEFINEDEXCEPTION_H_
#define SRC_LANG_UNDEFINEDEXCEPTION_H_

#include "Exception.h"

namespace tl {
namespace lang {

class UndefinedException: public virtual Exception {
public:
	UndefinedException();
	virtual ~UndefinedException();
	UndefinedException(const UndefinedException &other) = delete;
	UndefinedException& operator=(const UndefinedException &other) = delete;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_UNDEFINEDEXCEPTION_H_ */
