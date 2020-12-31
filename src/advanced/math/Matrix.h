/*
 * Matrix.h
 *
 *  Created on: Dec 31, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MATRIX_H_
#define SRC_ADVANCED_MATH_MATRIX_H_

#include "../../lang/Reference.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class Matrix: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 402;
public:
	Matrix();
	Matrix(const Matrix &other) = delete;
	Matrix& operator=(const Matrix &other) = delete;
	Reference multiply(Reference) = 0;
	Reference multiply(float) = 0;
	Reference add(Reference) = 0;
	Reference add(float) = 0;
	Reference negate() = 0;
	Reference transpose() = 0;
	Reference inverse() = 0;
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MATRIX_H_ */
