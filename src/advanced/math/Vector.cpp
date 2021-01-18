/*
 * Vector.cpp
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#include "Vector.h"

namespace tl {
namespace advanced {
namespace math {

Vector::Vector(tlint size) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

tlint Vector::columnSize() {
	return 1;
}

type_t Vector::type() {
	return CLASS_SERIAL;
}

bool Vector::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || AbstractMatrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
