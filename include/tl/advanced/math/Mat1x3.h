/*
 * Mat1x3.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_ADVANCED_MATH_MAT1X3_H_
#define TL_ADVANCED_MATH_MAT1X3_H_

#include <tl/advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat1x3: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 135;
	const static MatrixType MATRIX_ARRANGEMENT = MATRIX_1X3;
	const static tlint MAX_ROW_INDEX = 2;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMN_INDEX = 0;
	constexpr const static mat1x3 DEFAULT_VALUE = { { 0, 0, 0 } };

	mat1x3 mValue;
	mat3x1 mTranspose;

	mat3x1 transpose0();
	void update();
	vec3 getRow0(tlint);
	vec getColumn0(tlint);
public:
	Mat1x3();
	Mat1x3(mat1x3);
	virtual ~Mat1x3();
	Mat1x3(const Mat1x3 &other) = delete;
	Mat1x3& operator=(const Mat1x3 &other) = delete;
	mat1x3 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec3);
	void setColumn(tlint, vec);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	Reference transpose();
	Reference toString();
	tlint maxRowIndex();
	tlint maxColumnIndex();
	tlint minRowIndex();
	tlint minColumnIndex();
	MatrixType matrixType();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* TL_ADVANCED_MATH_MAT1X3_H_ */
