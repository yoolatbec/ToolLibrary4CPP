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
public:
	Mat4x4();
	virtual ~Mat4x4();
	Mat4x4(const Mat4x4 &other) = delete;
	Mat4x4& operator=(const Mat4x4 &other) = delete;
	Reference column(tlint = 0);
	Reference row(tlint = 0);
	Reference columns();
	float get(tlint, tlint);
	void set(tlint, tlint, float);
	void setRow(tlint, Reference);
	void setColumn(tlint, Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT4X4_H_ */
