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

Matrix::Matrix(tlint row, tlint col) {
	// TODO Auto-generated constructor stub
	//should check if row and col is legal
	initParameterCheck(row, col);

	mRow = row;
	mColumn = col;

	mElements = new float[mRow * mColumn];
}

Matrix::~Matrix(){
	delete [] mElements;
}

tlint Matrix::rowSize(){
	return mRow;
}

tlint Matrix::columnSize(){
	return mColumn;
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
