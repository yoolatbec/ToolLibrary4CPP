/*
 * MatrixFactory.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: yoolatbec
 */

#include "MatrixFactory.h"

namespace tl {
namespace advanced {
namespace math {

MatrixFactory::MatrixFactory() {
	// TODO Auto-generated constructor stub
}

type_t MatrixFactory::type(){
	return CLASS_SERIAL;
}

bool MatrixFactory::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
