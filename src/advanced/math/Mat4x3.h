/*
 * Mat4x3.h
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT4X3_H_
#define SRC_ADVANCED_MATH_MAT4X3_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat4x3: public virtual Matrix {
private:
	const static type_t CLASS_SERIAL = 122;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_4X3;
	const static tlint MAX_ROW_INDEX = 3;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 2;
	const static tlint MIN_COLUMN_INDEX = 0;
	constexpr const static mat4x3 DEFAULT_VALUE = {
		{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
	};

	mat4x3 mValue;
	mat3x4 mTranspose;

	vec3 getRow0(tlint);
	vec4 getColumn0(tlint);

	mat3x4 transpose0();
	void update();

public:
	Mat4x3();
	Mat4x3(mat4x3);
	virtual ~Mat4x3();
	Mat4x3(const Mat4x3 &other) = delete;
	Mat4x3& operator=(const Mat4x3 &other) = delete;
	Reference getRow(tlint);
	Reference getColumn(tlint);
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec3);
	void setColumn(tlint, vec4);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	mat4x3 values();
	tlint maxRowIndex();
	tlint minRowIndex();
	tlint maxColumnIndex();
	tlint minColumnIndex();
	MATRIX_TYPE matrixType();
	Reference toString();
	Reference transpose();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT4X3_H_ */
