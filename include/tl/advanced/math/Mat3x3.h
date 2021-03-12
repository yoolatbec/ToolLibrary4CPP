/*
 * Mat3x3.h
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MAT3X3_H_
#define INCLUDE_ADVANCED_MATH_MAT3X3_H_

#include <tl/advanced/math/SquareMatrix.h>

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
	mat3x3 mInverse;

	vec3 getRow0(tlint);
	vec3 getColumn0(tlint);
	mat3x3 transpose0();
	mat3x3 inverse0();
	double computeDeterminant();
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
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	Reference toString();
	mat3x3 values();
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

#endif /* INCLUDE_ADVANCED_MATH_MAT3X3_H_ */
