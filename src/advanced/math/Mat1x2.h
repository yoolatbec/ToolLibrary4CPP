/*
 * Mat1x2.h
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_MAT1X2_H_
#define ADVANCED_MATH_MAT1X2_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat1x2: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 134;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_1X2;
	const static tlint MAX_ROW_INDEX = 1;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMN_INDEX = 0;
	const static mat1x2 DEFAULT_VALUE = { { 0, 0 } };

	mat1x2 mValue;
	mat2x1 mTranspose;

	mat2x1 transpose0();
	void update();
	vec2 getRow0(tlint);
	vec getColumn0(tlint);

public:
	Mat1x2();
	Mat1x2(mat1x2);
	virtual ~Mat1x2();
	Mat1x2(const Mat1x2 &other) = delete;
	Mat1x2& operator=(const Mat1x2 &other) = delete;
	mat1x2 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec2);
	void setColumn(tlint, vec);
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

#endif /* ADVANCED_MATH_MAT1X2_H_ */
