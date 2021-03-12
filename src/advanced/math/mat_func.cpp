/*
 * mat_func.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#include <tl/advanced/math/mat_def.h>
#include <tl/lang/Float.h>

namespace tl {
namespace advanced {
namespace math {

mat1x1 identity_initialiser_mat1x1() {
	mat1x1 m;
	m.r0 =
		{ 1 };

	return m;
}

mat2x2 identity_initialiser_mat2x2() {
	mat2x2 m;
	m.r0 =
		{ 1, 0 };
	m.r1 =
		{ 0, 1 };

	return m;
}

mat3x3 identity_initialiser_mat3x3() {
	mat3x3 m;
	m.r0 =
		{ 1, 0, 0 };
	m.r1 =
		{ 0, 1, 0 };
	m.r2 =
		{ 0, 0, 1 };

	return m;
}

mat4x4 identity_initialiser_mat4x4() {
	mat4x4 m;
	m.r0 =
		{ 1, 0, 0, 0 };
	m.r1 =
		{ 0, 1, 0, 0 };
	m.r2 =
		{ 0, 0, 1, 0 };
	m.r3 =
		{ 0, 0, 0, 1 };

	return m;
}

}
}
}
