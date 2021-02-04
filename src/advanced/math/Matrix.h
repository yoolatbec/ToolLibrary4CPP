/*
 * Matrix.h
 *
 *  Created on: Dec 31, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MATRIX_H_
#define SRC_ADVANCED_MATH_MATRIX_H_

#include "AbstractMatrix.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class Matrix: public AbstractMatrix {
private:
	const static type_t CLASS_SERIAL = 402;

protected:
	const tlint mRow, mColumn;

	void rowBoundCheck(tlint);
	void columnBoundCheck(tlint);

public:
	Matrix(tlint, tlint);
	Matrix(const Matrix &other) = delete;
	Matrix& operator=(const Matrix &other) = delete;
	~Matrix();

	/*
	 * Get the number of rows
	 */
	tlint rowSize();
	/*
	 * Get the number of columns
	 */
	tlint columnSize();

	/*
	 * Get the n-th row
	 */
	Reference row(tlint) = 0;
	/*
	 * Get the n-th column
	 */
	Reference column(tlint) = 0;

	/*
	 * Get the value of row i, column j
	 */
	float get(tlint i, tlint j) = 0;
	/*
	 * Set the value of row i, column j to v
	 */
	void set(tlint, tlint, float v) = 0;
	void setRow(tlint, Reference) = 0;
	void setColumn(tlint, Reference) = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MATRIX_H_ */
