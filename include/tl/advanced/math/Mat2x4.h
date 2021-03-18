/*
 * Mat2x4.h
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_ADVANCED_MATH_MAT2X4_H_
#define TL_ADVANCED_MATH_MAT2X4_H_

#include <tl/advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat2x4: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 131;
	const static MatrixType MATRIX_ARRANGEMENT = MATRIX_2X4;
	const static tlint MAX_ROW_INDEX = 3;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 1;
	const static tlint MIN_COLUMN_INDEX = 0;

	constexpr const static mat2x4 DEFAULT_VALUE = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

	mat2x4 mValue;
	mat4x2 mTranspose;

	mat4x2 transpose0();
	void update();
	vec4 getRow0(tlint);
	vec2 getColumn0(tlint);

public:
	Mat2x4();
	Mat2x4(mat2x4);
	virtual ~Mat2x4();
	Mat2x4(const Mat2x4 &other) = delete;
	Mat2x4& operator=(const Mat2x4 &other) = delete;
	mat2x4 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec4);
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

#endif /* TL_ADVANCED_MATH_MAT2X4_H_ */
