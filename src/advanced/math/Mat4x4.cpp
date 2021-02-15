/*
 * Mat4x4.cpp
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#include "Mat4x4.h"
#include "Vec4.h"
#include "../../lang/FloatArray.h"
#include "../../lang/Array.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Array;
using lang::FloatArray;
using lang::Reference;

Mat4x4::Mat4x4() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat4x4();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x4::Mat4x4(mat4x4 initValue) {
	mValue = initValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x4::~Mat4x4() {
	// TODO Auto-generated destructor stub
}

vec4 Mat4x4::getRow0(tlint i) {
	vec4 v;
	switch (i) {
	case 0:
		v = mValue.r0;
		break;
	case 1:
		v = mValue.r1;
		break;
	case 2:
		v = mValue.r2;
		break;
	case 3:
		v = mValue.r3;
		break;
	default:
		//case an exception
		break;
	}

	return v;
}

vec4 Mat4x4::getColumn0(tlint j) {
	vec4 v;
	switch (j) {
	case 0:
		v.x = mValue.r0.x;
		v.y = mValue.r1.x;
		v.z = mValue.r2.x;
		v.w = mValue.r3.x;
		break;
	case 1:
		v.x = mValue.r0.y;
		v.y = mValue.r1.y;
		v.z = mValue.r2.y;
		v.w = mValue.r3.y;
		break;
	case 2:
		v.x = mValue.r0.z;
		v.y = mValue.r1.z;
		v.z = mValue.r2.z;
		v.w = mValue.r3.z;
		break;
	case 3:
		v.x = mValue.r0.w;
		v.y = mValue.r1.w;
		v.z = mValue.r2.w;
		v.w = mValue.r3.w;
		break;
	default:
		//cast an exception;
	}

	return v;
}

float Mat4x4::get(tlint i, tlint j) {
	rowBoundCheck(i);
	columnBoundCheck(j);

	vec4 r = getRow0(i);

	float value;
	switch (j) {
	case 0:
		j = r.x;
		break;
	case 1:
		j = r.y;
		break;
	case 2:
		j = r.z;
		break;
	case 3:
		j = r.w;
		break;
	default:
		//case an exception
	}

	return value;
}

Reference Mat4x4::getRow(tlint index) {
	rowBoundCheck(index);

	vec4 v = getRow0(index);

	return Reference(new Vec4(v));
}

Reference Mat4x4::getColumn(tlint index) {
	columnBoundCheck(index);

	vec4 v = getColumn0(index);

	return Reference(new Vec4(v));
}

void Mat4x4::set(tlint i, tlint j, float value) {
	rowBoundCheck(i);
	columnBoundCheck(j);

	vec4 v = getRow0(i);

	switch (j) {
	case 0:
		v.x = value;
		break;
	case 1:
		v.y = value;
		break;
	case 2:
		v.z = value;
		break;
	case 3:
		v.w = value;
		break;
	default:
		//cast an exception
	}

	setRow(i, v);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
