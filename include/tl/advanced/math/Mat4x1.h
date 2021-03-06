/*
 * Mat4x1.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_ADVANCED_MATH_MAT4X1_H_
#define TL_ADVANCED_MATH_MAT4X1_H_

#include <tl/advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat4x1: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 137;
	const static MatrixType MATRIX_ARRANGEMENT = MATRIX_4X1;
	const static tlint MAX_ROW_INDEX = 0;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMN_INDEX = 0;

	constexpr const static mat4x1 DEFAULT_VALUE = { { 0 }, { 0 }, { 0 }, { 0 } };

	mat4x1 mValue;
	mat1x4 mTranspose;

	mat1x4 transpose0();
	void update();
	vec getRow0(tlint);
	vec4 getColumn0(tlint);
public:
	Mat4x1();
	Mat4x1(mat4x1);
	virtual ~Mat4x1();
	Mat4x1(const Mat4x1 &other) = delete;
	Mat4x1& operator=(const Mat4x1 &other) = delete;
	mat4x1 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec);
	void setColumn(tlint, vec4);
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

#endif /* TL_ADVANCED_MATH_MAT4X1_H_ */
