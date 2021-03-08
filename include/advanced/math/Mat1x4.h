/*
 * Mat1x4.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_MAT1X4_H_
#define ADVANCED_MATH_MAT1X4_H_

#include <advanced/math/Matrix.h>

namespace tl {
namespace advanced {
namespace math {

class Mat1x4: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 137;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_1X4;
	const static tlint MAX_ROW_INDEX = 0;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 3;
	const static tlint MIN_COLUMN_INDEX = 0;

	constexpr const static mat1x4 DEFAULT_VALUE = {
		{0, 0, 0, 0}
	};

	mat1x4 mValue;
	mat4x1 mTranspose;

	mat4x1 transpose0();
	void update();
	vec4 getRow0(tlint);
	vec getColumn0(tlint);
public:
	Mat1x4();
	Mat1x4(mat1x4);
	virtual ~Mat1x4();
	Mat1x4(const Mat1x4 &other) = delete;
	Mat1x4& operator=(const Mat1x4 &other) = delete;
	mat1x4 values();
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec4);
	void setColumn(tlint, vec);
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

#endif /* ADVANCED_MATH_MAT1X4_H_ */
