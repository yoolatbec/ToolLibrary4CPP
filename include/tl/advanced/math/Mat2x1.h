/*
 * Mat2x1.h
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_ADVANCED_MATH_MAT2X1_H_
#define TL_ADVANCED_MATH_MAT2X1_H_

#include <tl/advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat2x1: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 133;
	const static MatrixType MATRIX_ARRANGEMENT = MATRIX_2X1;
	const static tlint MAX_ROW_INDEX = 1;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMN_INDEX = 0;
	constexpr const static mat2x1 DEFAULT_VALUE = { { 0 }, { 0 } };

	mat2x1 mValue;
	mat1x2 mTranspose;

	mat1x2 transpose0();
	void update();
	vec getRow0(tlint);
	vec2 getColumn0(tlint);

public:
	Mat2x1();
	Mat2x1(mat2x1);
	virtual ~Mat2x1();
	Mat2x1(const Mat2x1 &other) = delete;
	Mat2x1& operator=(const Mat2x1 &other) = delete;
	mat2x1 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec);
	void setColumn(tlint, vec2);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	Reference transpose();
	Reference toString();
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	MatrixType matrixType();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* TL_ADVANCED_MATH_MAT2X1_H_ */
