/*
 * Mat3x1.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MAT3X1_H_
#define ADVANCED_MAT3X1_H_

#include <advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat3x1: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 136;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_3X1;
	const static tlint MAX_ROW_INDEX = 0;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 2;
	const static tlint MIN_COLUMN_INDEX = 0;
	constexpr const static mat3x1 DEFAULT_VALUE = { { 0 }, { 0 }, { 0 } };

	mat3x1 mValue;
	mat1x3 mTranspose;

	mat1x3 transpose0();
	void update();
	vec getRow0(tlint);
	vec3 getColumn0(tlint);

public:
	Mat3x1();
	Mat3x1(mat3x1);
	virtual ~Mat3x1();
	Mat3x1(const Mat3x1 &other) = delete;
	Mat3x1& operator=(const Mat3x1 &other) = delete;
	mat3x1 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec);
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

#endif /* ADVANCED_MAT3X1_H_ */
