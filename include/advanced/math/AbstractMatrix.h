/*
 * AbstractMatrix.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_ABSTRACTMATRIX_H_
#define INCLUDE_ADVANCED_MATH_ABSTRACTMATRIX_H_

#include <lang/Reference.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class AbstractMatrix: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 77;

public:
	AbstractMatrix();
	virtual ~AbstractMatrix();
	AbstractMatrix(const AbstractMatrix &other) = delete;
	AbstractMatrix& operator=(const AbstractMatrix &other) = delete;
	virtual Reference toString() = 0;
	static type_t type();
	virtual bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_ABSTRACTMATRIX_H_ */
