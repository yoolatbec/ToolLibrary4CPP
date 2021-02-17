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

float MatrixFactory::dot0(vec4 v, vec4 u) {
	return v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w;
}

float MatrixFactory::dot0(vec3 v, vec3 u) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
}

float MatrixFactory::dot0(vec2 v, vec2 u) {
	return v.x * u.x + v.y * u.y;
}

float MatrixFactory::dot0(vec v, vec u) {
	return v.x * u.x;
}

float MatrixFactory::dot(Reference v, Reference u) {
	if (!v.getEntity()->instanceof(Vector::type())
		|| !u.getEntity()->instanceof(Vector::type())) {
		//cast an exception
	}
}

type_t MatrixFactory::type() {
	return CLASS_SERIAL;
}

bool MatrixFactory::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
