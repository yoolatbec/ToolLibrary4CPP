/*
 * Mat4x2.h
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_MAT4X2_H_
#define ADVANCED_MATH_MAT4X2_H_

#include <advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat4x2: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 132;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_4X2;
	const static tlint MAX_ROW_INDEX = 1;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 3;
	const static tlint MIN_COLUMN_INDEX = 0;

	constexpr const static mat4x2 DEFAULT_VALUE =
		{ { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

	mat4x2 mValue;
	mat2x4 mTranspose;

	mat2x4 transpose0();
	void update();
	vec2 getRow0(tlint);
	vec4 getColumn0(tlint);

public:
	Mat4x2();
	Mat4x2(mat4x2);
	virtual ~Mat4x2();
	Mat4x2(const Mat4x2 &other) = delete;
	Mat4x2& operator=(const Mat4x2 &other) = delete;
	mat4x2 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec2);
	void setColumn(tlint, vec4);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	Reference transpose();
	Reference toString();
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

#endif /* ADVANCED_MATH_MAT4X2_H_ */
