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
}

Matrix::~Matrix() {
}

tlint Matrix::rowSize() {
	return mRow;
}

tlint Matrix::columnSize() {
	return mColumn;
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
