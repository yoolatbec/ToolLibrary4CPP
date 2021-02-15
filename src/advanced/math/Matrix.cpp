/*
 * Matrix.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: yoolatbec
 */

#include "Matrix.h"
#include "../../lang/Array.h"

namespace tl {
namespace advanced {
namespace math {

Matrix::Matrix() {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

Matrix::~Matrix() {
}

type_t Matrix::type() {
	return CLASS_SERIAL;
}

bool Matrix::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || AbstractMatrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
