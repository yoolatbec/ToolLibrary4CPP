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
	/*
	 * Store in form of column vectors
	 */
	Reference mElements;

	void rowBoundCheck(tlint);
	void columnBoundCheck(tlint);

public:
	Matrix(tlint, tlint);
	Matrix(const Matrix &other) = delete;
	Matrix& operator=(const Matrix &other) = delete;
	~Matrix();
	tlint rowSize();
	tlint columnSize();
	Reference row(tlint) = 0;
	Reference column(tlint) = 0;
	Reference columns() = 0;
	float get(tlint, tlint) = 0;
	void set(tlint, tlint, float) = 0;
	void setRow(tlint, Reference) = 0;
	void setColumn(tlint, Reference) = 0;
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MATRIX_H_ */
