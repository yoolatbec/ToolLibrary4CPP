/*
 * SquareMatrix.h
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_SQUAREMATRIX_H_
#define SRC_ADVANCED_MATH_SQUAREMATRIX_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

class SquareMatrix: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 111;

protected:
	double mDeterminant;
	virtual double computeDeterminant() = 0;

public:
	SquareMatrix();
	virtual ~SquareMatrix();
	SquareMatrix(const SquareMatrix &other) = delete;
	SquareMatrix& operator=(const SquareMatrix &other) = delete;
	virtual double determinant() = 0;
	virtual bool invertible() = 0;
	virtual Reference inverse() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_SQUAREMATRIX_H_ */
