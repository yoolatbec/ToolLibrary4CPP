/*
 * Mat4x1.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_MAT4X1_H_
#define ADVANCED_MATH_MAT4X1_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat4x1: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 137;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_4X1;
	const static tlint MAX_ROW_INDEX = 0;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMN_INDEX = 0;

	const static mat4x1 DEFAULT_VALUE = { { 0 }, { 0 }, { 0 }, { 0 } };

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
	Reference transpose();
	Reference toString();
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* ADVANCED_MATH_MAT4X1_H_ */
