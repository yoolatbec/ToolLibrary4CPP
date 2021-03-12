/*
 * Mat2x3.h
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_ADVANCED_MATH_MAT2X3_H_
#define TL_ADVANCED_MATH_MAT2X3_H_

#include <tl/advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat2x3: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 123;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_2X3;
	const static tlint MAX_ROW_INDEX = 2;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 1;
	const static tlint MIN_COLUMN_INDEX = 0;

	constexpr const static mat2x3 DEFAULT_VALUE = { { 0, 0, 0 }, { 0, 0, 0 } };

	mat2x3 mValue;
	mat3x2 mTranspose;

	mat3x2 transpose0();
	vec3 getRow0(tlint);
	vec2 getColumn0(tlint);
	void update();

public:
	Mat2x3();
	Mat2x3(mat2x3);
	virtual ~Mat2x3();
	Mat2x3(const Mat2x3 &other) = delete;
	Mat2x3& operator=(const Mat2x3 &other) = delete;
	mat2x3 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec3);
	void setColumn(tlint, vec2);
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

#endif /* TL_ADVANCED_MATH_MAT2X3_H_ */
