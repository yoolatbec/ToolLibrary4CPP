/*
 * SquareMatrix.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#include "SquareMatrix.h"

namespace tl {
namespace advanced {
namespace math {

SquareMatrix::SquareMatrix() {
	// TODO Auto-generated constructor stub

}

SquareMatrix::~SquareMatrix() {
	// TODO Auto-generated destructor stub
}

type_t SquareMatrix::type(){
	return CLASS_SERIAL;
}

bool SquareMatrix::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
