/*
 * Matrix.h
 *
 *  Created on: Dec 31, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MATRIX_H_
#define SRC_ADVANCED_MATH_MATRIX_H_

#include "AbstractMatrix.h"
#include "mat_func.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class Matrix: public AbstractMatrix {
private:
	const static type_t CLASS_SERIAL = 402;

protected:
	virtual void rowBoundCheck(tlint) = 0;
	virtual void columnBoundCheck(tlint) = 0;

public:
	Matrix();
	Matrix(const Matrix &other) = delete;
	Matrix& operator=(const Matrix &other) = delete;
	virtual ~Matrix();

	/*
	 * Get the n-th row
	 */
	virtual Reference getRow(tlint) = 0;
	/*
	 * Get the n-th column
	 */
	virtual Reference getColumn(tlint) = 0;

	/*
	 * Get the value of row i, column j
	 */
	virtual float get(tlint i, tlint j) = 0;
	/*
	 * Set the value of row i, column j to v
	 */
	virtual void set(tlint, tlint, float v) = 0;
	virtual Reference transpose() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MATRIX_H_ */
