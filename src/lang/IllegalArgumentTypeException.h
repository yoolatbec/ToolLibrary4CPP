/*
 * IllegalArgumentTypeException.h
 *
 *  Created on: Feb 23, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ILLEGALARGUMENTTYPEEXCEPTION_H_
#define SRC_ILLEGALARGUMENTTYPEEXCEPTION_H_

#include "Exception.h"

namespace tl {
namespace lang {

class IllegalArgumentTypeException: public virtual Exception {
private:
	const static type_t CLASS_SERIAL = 13;
public:
	IllegalArgumentTypeException();
	virtual ~IllegalArgumentTypeException();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_ILLEGALARGUMENTTYPEEXCEPTION_H_ */
