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
	enum MATRIX_TYPE {
		MATRIX_1X1,
		MATRIX_1X2,
		MATRIX_1X3,
		MATRIX_1X4,
		MATRIX_2X1,
		MATRIX_2X2,
		MATRIX_2X3,
		MATRIX_2X4,
		MATRIX_3X1,
		MATRIX_3X2,
		MATRIX_3X3,
		MATRIX_3X4,
		MATRIX_4X1,
		MATRIX_4X2,
		MATRIX_4X3,
		MATRIX_4X4,
		VECTOR_1,
		VECTOR_2,
		VECTOR_3,
		VECTOR_4
	};

	AbstractMatrix();
	virtual ~AbstractMatrix();
	AbstractMatrix(const AbstractMatrix &other) = delete;
	AbstractMatrix& operator=(const AbstractMatrix &other) = delete;
	Reference toString() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_ABSTRACTMATRIX_H_ */
