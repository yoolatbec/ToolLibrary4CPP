/*
 * Mat3x4.h
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT3X4_H_
#define SRC_ADVANCED_MATH_MAT3X4_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat3x4: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 121;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_3X4;
	const static tlint MAX_ROW_INDEX = 2;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 3;
	const static tlint MIN_COLUMN_INDEX = 0;
	const static mat3x4 DEFAULT_VALUE =
		{ { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

	mat3x4 mValue;
	mat4x3 mTranspose;

	vec4 getRow0(tlint);
	vec3 getColumn0(tlint);
	mat4x3 transpose0();
	void update();

public:
	Mat3x4();
	Mat3x4(mat3x4);
	virtual ~Mat3x4();
	Mat3x4(const Mat3x4 &other) = delete;
	Mat3x4& operator=(const Mat3x4 &other) = delete;
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec4);
	void setColumn(tlint, vec3);
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	Reference transpose();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT3X4_H_ */
