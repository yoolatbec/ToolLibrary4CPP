/*
 * Mat3x4.cpp
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#include "Mat3x4.h"
#include "Mat4x3.h"
#include "Vec3.h"
#include "Vec4.h"
#include "../../lang/String.h"
#include <stdio.h>
#include <string.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Math;
using lang::String;
using lang::Reference;

Mat3x4::Mat3x4() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x4::Mat3x4(mat3x4 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x4::~Mat3x4() {
	// TODO Auto-generated destructor stub
}

vec4 Mat3x4::getRow0(tlint i) {
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
	default:
		//cast an exception
	}

	return v;
}

vec3 Mat3x4::getColumn0(tlint j) {
	vec3 v;
	switch (j) {
	case 0:
		v.x = mValue.r0.x;
		v.y = mValue.r1.x;
		v.z = mValue.r2.x;
		break;
	case 1:
		v.x = mValue.r0.y;
		v.y = mValue.r1.y;
		v.z = mValue.r2.y;
		break;
	case 2:
		v.x = mValue.r0.z;
		v.y = mValue.r1.z;
		v.z = mValue.r2.z;
		break;
	case 3:
		v.x = mValue.r0.w;
		v.y = mValue.r1.w;
		v.z = mValue.r2.w;
		break;
	default:
		//cast an exception
	}

	return v;
}

float Mat3x4::get(tlint i, tlint j) {
	vec4 v = getRow0(i);
	float value;
	switch (j) {
	case 0:
		value = v.x;
		break;
	case 1:
		value = v.y;
		break;
	case 2:
		value = v.z;
		break;
	case 3:
		value = v.w;
		break;
	default:
		//cast an exception
	}

	return value;
}

mat4x3 Mat3x4::transpose0() {
	mat4x3 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);
	m.r3 = getColumn0(3);
	return m;
}

void Mat3x4::update() {
	mTranspose = transpose0();
}

Reference Mat3x4::getRow(tlint i) {
	vec4 v = getRow0(i);
	return Reference(new Vec4(v));
}

Reference Mat3x4::getColumn(tlint j) {
	vec3 v = getColumn0(j);
	return Reference(new Vec3(v));
}

void Mat3x4::set(tlint i, tlint j, float value) {
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

void Mat3x4::setRow(tlint i, vec4 v) {
	switch (i) {
	case 0:
		mValue.r0 = v;
		break;
	case 1:
		mValue.r1 = v;
		break;
	case 2:
		mValue.r2 = v;
		break;
	default:
		//cast an exception
	}

	update();
}

void Mat3x4::setColumn(tlint j, vec3 v) {
	switch (j) {
	case 0:
		mValue.r0.x = v.x;
		mValue.r1.x = v.y;
		mValue.r2.x = v.z;
		break;
	case 1:
		mValue.r0.y = v.x;
		mValue.r1.y = v.y;
		mValue.r2.y = v.z;
		break;
	case 2:
		mValue.r0.z = v.x;
		mValue.r1.z = v.y;
		mValue.r2.z = v.z;
		break;
	case 3:
		mValue.r0.w = v.x;
		mValue.r1.w = v.y;
		mValue.r2.w = v.z;
		break;
	default:
		//cast an exception
	}

	update();
}

tlint Mat3x4::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat3x4::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat3x4::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat3x4::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

type_t Mat3x4::type() {
	return CLASS_SERIAL;
}

Reference Mat3x4::transpose() {
	return Reference(new Mat4x3(mTranspose));
}

Reference Mat3x4::toString() {
	char str[200];
	sprintf(str, "[%f, %f, %f, %f\n", mValue.r0.x, mValue.r0.y, mValue.r0.z);
	sprintf(str + strlen(str), " %f, %f, %f, %f\n", mValue.r1.x, mValue.r1.y,
		mValue.r1.z);
	sprintf(str + strlen(str), " %f, %f, %f, %f]", mValue.r2.x, mValue.r2.y,
		mValue.r2.z);
	return Reference(new String(str));
}

bool Mat3x4::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
