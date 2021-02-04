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

Matrix::Matrix(tlint row, tlint col)
		: mRow(row), mColumn(col) {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

Matrix::~Matrix() {
}

tlint Matrix::rowSize() {
	return mRow;
}

tlint Matrix::columnSize() {
	return mColumn;
}

type_t Matrix::type(){
	return CLASS_SERIAL;
}

bool Matrix::instanceof(type_t type){
	return (CLASS_SERIAL == type) || AbstractMatrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
