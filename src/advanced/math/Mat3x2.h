/*
 * Mat3x2.h
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_MAT3X2_H_
#define ADVANCED_MATH_MAT3X2_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat3x2: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 125;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_3X2;
	const static tlint MAX_ROW_INDEX = 2;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 1;
	const static tlint MIN_COLUMN_INDEX = 0;

	constexpr const static mat3x2 DEFAULT_VALUE = { { 0, 0 }, { 0, 0 }, { 0, 0 } };

	mat3x2 mValue;
	mat2x3 mTranspose;

	vec2 getRow0(tlint);
	vec3 getColumn0(tlint);
	mat2x3 transpose0();
	void update();

public:
	Mat3x2();
	Mat3x2(mat3x2);
	virtual ~Mat3x2();
	Mat3x2(const Mat3x2 &other) = delete;
	Mat3x2& operator=(const Mat3x2 &other) = delete;
	mat3x2 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec2);
	void setColumn(tlint, vec3);
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

#endif /* ADVANCED_MATH_MAT3X2_H_ */
