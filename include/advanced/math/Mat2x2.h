/*
 * Mat2x2.h
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MAT2X2_H_
#define INCLUDE_ADVANCED_MATH_MAT2X2_H_

#include <advanced/math/SquareMatrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat2x2: public virtual SquareMatrix {
private:
	const static type_t CLASS_SERIAL = 113;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_2X2;
	const static tlint MAX_ROW_INDEX = 1;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 1;
	const static tlint MIN_COLUMN_INDEX = 0;

	mat2x2 mValue;
	mat2x2 mTranspose;
	mat2x2 mInverse;

	vec2 getRow0(tlint);
	vec2 getColumn0(tlint);
	mat2x2 transpose0();
	double computeDeterminant();
	mat2x2 inverse0();
	void update();

public:
	Mat2x2();
	Mat2x2(mat2x2);
	virtual ~Mat2x2();
	Mat2x2(const Mat2x2 &other) = delete;
	Mat2x2& operator=(const Mat2x2 &other) = delete;
	void set(tlint, tlint, float);
	void setRow(tlint, vec2);
	void setColumn(tlint, vec2);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	float get(tlint, tlint);
	Reference getColumn(tlint);
	Reference getRow(tlint);
	mat2x2 values();
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	MATRIX_TYPE matrixType();
	bool invertible();
	Reference inverse();
	Reference transpose();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_MAT2X2_H_ */
