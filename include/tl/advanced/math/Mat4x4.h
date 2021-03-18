/*
 * Mat4x4.h
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MAT4X4_H_
#define INCLUDE_ADVANCED_MATH_MAT4X4_H_

#include <tl/advanced/math/SquareMatrix.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class Mat4x4: public virtual SquareMatrix {
private:
	const static type_t CLASS_SERIAL = 53;
	const static MatrixType MATRIX_ARRANGEMENT = MATRIX_4X4;
	const static tlint MAX_ROW_INDEX = 3;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 3;
	const static tlint MIN_COLUMN_INDEX =  0;

//	void rowBoundCheck(tlint);
//	void columnBoundCheck(tlint);

	mat4x4 mValue;
	mat4x4 mTranspose;
	mat4x4 mInverse;

	vec4 getRow0(tlint);
	vec4 getColumn0(tlint);
	mat4x4 transpose0();
	mat4x4 inverse0();
	double computeDeterminant();
	void update();

public:
	Mat4x4();
	Mat4x4(mat4x4);
	virtual ~Mat4x4();
	Mat4x4(const Mat4x4 &other) = delete;
	Mat4x4& operator=(const Mat4x4 &other) = delete;
	float get(tlint, tlint);
	Reference getRow(tlint);
	Reference getColumn(tlint);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	mat4x4 values();
	void set(tlint, tlint, float);
	void setRow(tlint, vec4);
	void setColumn(tlint, vec4);
	bool invertible();
	Reference inverse();
	Reference transpose();
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	MatrixType matrixType();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_MAT4X4_H_ */
