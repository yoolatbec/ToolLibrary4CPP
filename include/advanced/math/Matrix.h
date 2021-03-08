/*
 * Matrix.h
 *
 *  Created on: Dec 31, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MATRIX_H_
#define INCLUDE_ADVANCED_MATH_MATRIX_H_

#include <advanced/math/AbstractMatrix.h>
#include <advanced/math/mat_func.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

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
	MATRIX_4X4
};


class Matrix: public AbstractMatrix {
private:
	const static type_t CLASS_SERIAL = 402;

protected:
//	virtual void rowBoundCheck(tlint) = 0;
//	virtual void columnBoundCheck(tlint) = 0;

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
	virtual void setRow(tlint, Reference) = 0;
	virtual void setColumn(tlint, Reference) = 0;
	virtual Reference transpose() = 0;
	virtual tlint maxRowIndex() = 0;
	virtual tlint maxColumnIndex() = 0;
	virtual tlint minRowIndex() = 0;
	virtual tlint minColumnIndex() = 0;
	virtual MATRIX_TYPE matrixType() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_MATRIX_H_ */
