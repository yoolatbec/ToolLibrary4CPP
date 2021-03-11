/*
 * IncompatibleArgumentException.h
 *
 *  Created on: Mar 11, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_INCOMPATIBLEMATRIXTYPEEXCEPTION_H_
#define ADVANCED_MATH_INCOMPATIBLEMATRIXTYPEEXCEPTION_H_

#include <lang/IllegalArgumentTypeException.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class IncompatibleMatrixTypeException: public virtual lang::IllegalArgumentTypeException {
private:
	const static type_t CLASS_SERIAL = 89;
	constexpr const static char *DEFAULT_MESSAGE =
		"IncompatibleMatrixTypeException:";
	static Reference sDefaultMessage;
public:
	IncompatibleMatrixTypeException();
	IncompatibleMatrixTypeException(const char*);
	virtual ~IncompatibleMatrixTypeException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* ADVANCED_MATH_INCOMPATIBLEMATRIXTYPEEXCEPTION_H_ */
