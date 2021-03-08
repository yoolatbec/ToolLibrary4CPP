/*
 * mat_func.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/mat_def.h>

#include <lang/Float.h>

namespace tl {
namespace advanced {
namespace math {

mat1x1 identity_initialiser() {
	mat1x1 m;
	m.r0 = { 1 };

	return m;
}

mat2x2 identity_initialiser() {
	mat2x2 m;
	m.r0 = { 1, 0 };
	m.r1 = { 0, 1 };

	return m;
}

mat3x3 identity_initialiser() {
	mat3x3 m;
	m.r0 = { 1, 0, 0 };
	m.r1 = { 0, 1, 0 };
	m.r2 = { 0, 0, 1 };

	return m;
}

mat4x4 identity_initialiser() {
	mat4x4 m;
	m.r0 = { 1, 0, 0, 0 };
	m.r1 = { 0, 1, 0, 0 };
	m.r2 = { 0, 0, 1, 0 };
	m.r3 = { 0, 0, 0, 1 };

	return m;
}

}
}
}
