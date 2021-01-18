/*
 * AbstractMatrix.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_ABSTRACTMATRIX_H_
#define SRC_ADVANCED_MATH_ABSTRACTMATRIX_H_

#include "../../lang/Reference.h"

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
	tlint rowSize() = 0;
	tlint columnSize() = 0;
	Reference toString() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_ABSTRACTMATRIX_H_ */
