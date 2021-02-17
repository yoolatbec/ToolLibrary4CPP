/*
 * Mat3x3.h
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT3X3_H_
#define SRC_ADVANCED_MATH_MAT3X3_H_

#include "SquareMatrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat3x3: public virtual SquareMatrix {
private:
	const static type_t CLASS_SERIAL = 102;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_3X3;
	const static tlint MAX_ROW_INDEX = 2;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 2;
	const static tlint MIN_COLUMN_INDEX = 0;

//	void rowBoundCheck(tlint);
//	void columnBoundCheck(tlint);

	mat3x3 mValue;
	mat3x3 mTranspose;
	Reference mInverse;

	vec3 getRow0(tlint);
	vec3 getColumn0(tlint);
	mat3x3 transpose0();
	double computeDeterminant();
	Reference inverse0();
	void update();


public:
	Mat3x3();
	Mat3x3(mat3x3);
	virtual ~Mat3x3();
	Mat3x3(const Mat3x3 &other) = delete;
	Mat3x3& operator=(const Mat3x3 &other) = delete;
	bool invertible();
	Reference inverse();
	Reference transpose();
	float get(tlint, tlint);
	Reference getRow(tlint);
	Reference getColumn(tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec3);
	void setColumn(tlint, vec3);
	Reference toString();
	mat3x3 values();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT3X3_H_ */
