/*
 * IllegalArgumentTypeException.h
 *
 *  Created on: Feb 23, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ILLEGALARGUMENTTYPEEXCEPTION_H_
#define SRC_ILLEGALARGUMENTTYPEEXCEPTION_H_

#include <lang/Exception.h>

namespace tl {
namespace lang {

class IllegalArgumentTypeException: public virtual Exception {
private:
	const static type_t CLASS_SERIAL = 13;
	constexpr const static char *DEFAULT_MESSAGE =
		"IllegalArgumentTypeException:";
	static Reference sDefaultMessage;
public:
	IllegalArgumentTypeException();
	IllegalArgumentTypeException(const char*);
	virtual ~IllegalArgumentTypeException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_ILLEGALARGUMENTTYPEEXCEPTION_H_ */
