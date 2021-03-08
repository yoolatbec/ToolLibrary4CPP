/*
 * AbstractMatrix.cpp
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/AbstractMatrix.h>

namespace tl {
namespace advanced {
namespace math {

AbstractMatrix::AbstractMatrix() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

AbstractMatrix::~AbstractMatrix() {
	// TODO Auto-generated destructor stub
}

type_t AbstractMatrix::type(){
	return CLASS_SERIAL;
}

bool AbstractMatrix::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
