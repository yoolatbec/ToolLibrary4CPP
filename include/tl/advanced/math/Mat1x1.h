/*
 * Mat1x1.h
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MAT1X1_H_
#define INCLUDE_ADVANCED_MATH_MAT1X1_H_

#include <tl/advanced/math/SquareMatrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat1x1: public virtual SquareMatrix {
private:
	const static type_t CLASS_SERIAL = 114;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_1X1;
	const static tlint MAX_ROW_INDEX = 0;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMN_INDEX = 0;

	mat1x1 mValue;
	mat1x1 mInverse;

	double computeDeterminant();
	mat1x1 inverse0();
	void update();

	void rowIndexCheck(tlint);
	void columnIndexCheck(tlint);

public:
	Mat1x1();
	Mat1x1(mat1x1);
	virtual ~Mat1x1();
	Mat1x1(const Mat1x1 &other) = delete;
	Mat1x1& operator=(const Mat1x1 &other) = delete;
	bool invertible();
	Reference inverse();
	Reference transpose();
	void set(tlint, tlint, float);
	void setColumn(tlint, vec);
	void setRow(tlint, vec);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	float get(tlint, tlint);
	Reference getRow(tlint);
	Reference getColumn(tlint);
	Reference toString();
	mat1x1 values();
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	MATRIX_TYPE matrixType();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_MAT1X1_H_ */
