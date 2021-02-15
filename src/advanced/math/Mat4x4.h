/*
 * Mat4x4.h
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT4X4_H_
#define SRC_ADVANCED_MATH_MAT4X4_H_

#include "Matrix.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class Mat4x4: public Matrix {
private:
	const static type_t CLASS_SERIAL = 53;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_4X4;
	const static tlint MAX_ROW_INDEX = 3;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 3;
	const static tlint MIN_COLUMN_INDEX =  0;

	void rowBoundCheck(tlint);
	void columnBoundCheck(tlint);

	mat4x4 mValue;

	vec4 getRow0(tlint);
	vec4 getColumn0(tlint);

public:
	Mat4x4();
	Mat4x4(mat4x4);
	virtual ~Mat4x4();
	Mat4x4(const Mat4x4 &other) = delete;
	Mat4x4& operator=(const Mat4x4 &other) = delete;
	float get(tlint, tlint);
	Reference getRow(tlint);
	Reference getColumn(tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, vec4);
	void setColumn(tlint, vec4);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT4X4_H_ */
