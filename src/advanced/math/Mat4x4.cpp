/*
 * Mat4x4.cpp
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#include "Mat4x4.h"
#include "Vec4.h"
#include "../../lang/String.h"
#include "../../lang/Math.h"
#include <stdio.h>
#include <string.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;
using lang::Math;

Mat4x4::Mat4x4() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat4x4();
	mTranspose = mValue;
	mDeterminant = 1.0;
	mInverse = mValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x4::Mat4x4(mat4x4 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x4::~Mat4x4() {
	// TODO Auto-generated destructor stub
}

mat4x4 Mat4x4::transpose0() {
	mat4x4 m;

	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);
	m.r3 = getColumn0(3);

	return m;
}

mat4x4 Mat4x4::inverse0() {
	mat4x4 m;

	m.r0.x = (mValue.r1.y
		* (mValue.r2.z * mValue.r3.w - mValue.r2.w * mValue.r3.z)
		- mValue.r1.z * (mValue.r2.y * mValue.r3.w - mValue.r2.w * mValue.r3.y)
		+ mValue.r1.w * (mValue.r2.y * mValue.r3.z - mValue.r2.z * mValue.r3.y))
		/ mDeterminant;
	m.r0.y = -(mValue.r1.x
		* (mValue.r2.z * mValue.r3.w - mValue.r2.w * mValue.r3.z)
		- mValue.r1.z * (mValue.r2.x * mValue.r3.w - mValue.r2.w * mValue.r3.x)
		+ mValue.r1.w * (mValue.r2.x * mValue.r3.z - mValue.r2.z * mValue.r3.x))
		/ mDeterminant;
	m.r0.z = (mValue.r1.x
		* (mValue.r2.y * mValue.r3.w - mValue.r2.w * mValue.r3.y)
		- mValue.r1.y * (mValue.r2.x * mValue.r3.w - mValue.r2.w * mValue.r3.x)
		+ mValue.r1.w * (mValue.r2.x * mValue.r3.y - mValue.r2.y * mValue.r3.x))
		/ mDeterminant;
	m.r0.w = -(mValue.r1.x
		* (mValue.r2.y * mValue.r3.z - mValue.r2.z * mValue.r3.y)
		- mValue.r1.y * (mValue.r2.x * mValue.r3.z - mValue.r2.z * mValue.r3.x)
		+ mValue.r1.z * (mValue.r2.x * mValue.r3.y - mValue.r2.y * mValue.r3.x))
		/ mDeterminant;

	m.r1.x = -(mValue.r0.y
		* (mValue.r2.z * mValue.r3.w - mValue.r2.w * mValue.r3.z)
		- mValue.r0.z * (mValue.r2.y * mValue.r3.w - mValue.r2.w * mValue.r3.y)
		+ mValue.r0.w * (mValue.r2.y * mValue.r3.z - mValue.r2.z * mValue.r3.y))
		/ mDeterminant;
	m.r1.y = (mValue.r0.x
		* (mValue.r2.z * mValue.r3.w - mValue.r2.w * mValue.r3.z)
		- mValue.r0.z * (mValue.r2.x * mValue.r3.w - mValue.r2.w * mValue.r3.x)
		+ mValue.r0.w * (mValue.r2.x * mValue.r3.z - mValue.r2.z * mValue.r3.x))
		/ mDeterminant;
	m.r1.z = -(mValue.r0.x
		* (mValue.r2.y * mValue.r3.w - mValue.r2.w * mValue.r3.y)
		- mValue.r0.y * (mValue.r2.x * mValue.r3.w - mValue.r2.w * mValue.r3.x)
		+ mValue.r0.w * (mValue.r2.x * mValue.r3.y - mValue.r2.y * mValue.r3.x))
		/ mDeterminant;
	m.r1.w = (mValue.r0.x
		* (mValue.r2.y * mValue.r3.z - mValue.r2.z * mValue.r3.y)
		- mValue.r0.y * (mValue.r2.x * mValue.r3.z - mValue.r2.z * mValue.r3.x)
		+ mValue.r0.z * (mValue.r2.x * mValue.r3.y - mValue.r2.y * mValue.r3.x))
		/ mDeterminant;

	m.r2.x = (mValue.r0.y
		* (mValue.r1.z * mValue.r3.w - mValue.r1.w * mValue.r3.z)
		- mValue.r0.z * (mValue.r1.y * mValue.r3.w - mValue.r1.w * mValue.r3.y)
		+ mValue.r0.w * (mValue.r1.y * mValue.r3.z - mValue.r1.z * mValue.r3.y))
		/ mDeterminant;
	m.r2.y = -(mValue.r0.x
		* (mValue.r1.z * mValue.r3.w - mValue.r1.w * mValue.r3.z)
		- mValue.r0.z * (mValue.r1.x * mValue.r3.w - mValue.r1.w * mValue.r3.x)
		+ mValue.r0.w * (mValue.r1.x * mValue.r3.z - mValue.r1.z * mValue.r3.x))
		/ mDeterminant;
	m.r2.z = (mValue.r0.x
		* (mValue.r1.y * mValue.r3.w - mValue.r1.w * mValue.r3.y)
		- mValue.r0.y * (mValue.r1.x * mValue.r3.w - mValue.r1.w * mValue.r3.x)
		+ mValue.r0.w * (mValue.r1.x * mValue.r3.y - mValue.r1.y * mValue.r3.x))
		/ mDeterminant;
	m.r2.w = -(mValue.r0.x
		* (mValue.r1.y * mValue.r3.z - mValue.r1.z * mValue.r3.y)
		- mValue.r0.y * (mValue.r1.x * mValue.r3.z - mValue.r1.z * mValue.r3.z)
		+ mValue.r0.z * (mValue.r1.x * mValue.r3.y - mValue.r1.y * mValue.r3.x))
		/ mDeterminant;

	m.r3.x = -(mValue.r0.y
		* (mValue.r1.z * mValue.r2.w - mValue.r1.w * mValue.r2.z)
		- mValue.r0.z * (mValue.r1.y * mValue.r2.w - mValue.r1.w * mValue.r2.y)
		+ mValue.r0.w * (mValue.r1.y * mValue.r2.z - mValue.r1.z * mValue.r2.y))
		/ mDeterminant;
	m.r3.y = (mValue.r0.x * (mValue.r1.z * mValue.r2.w)
		- mValue.r0.z * (mValue.r1.x * mValue.r2.w - mValue.r1.w * mValue.r2.x)
		+ mValue.r0.w * (mValue.r1.x * mValue.r2.z - mValue.r1.z * mValue.r2.x))
		/ mDeterminant;
	m.r3.z = -(mValue.r0.x
		* (mValue.r1.y * mValue.r2.w - mValue.r1.w * mValue.r2.y)
		- mValue.r0.y * (mValue.r1.x * mValue.r2.w - mValue.r1.w * mValue.r2.x)
		+ mValue.r0.w * (mValue.r1.x * mValue.r2.y - mValue.r1.y * mValue.r2.x))
		/ mDeterminant;
	m.r3.w = (mValue.r0.x
		* (mValue.r1.y * mValue.r2.z - mValue.r1.z * mValue.r2.y)
		- mValue.r0.y * (mValue.r1.x * mValue.r2.z - mValue.r1.z * mValue.r2.x)
		+ mValue.r0.z * (mValue.r1.x * mValue.r2.y - mValue.r1.y * mValue.r2.x))
		/ mDeterminant;

	return m;
}

double Mat4x4::computeDeterminant() {
	double v1, v2, v3, v4;
	v1 = mValue.r1.y * (mValue.r2.z * mValue.r3.w - mValue.r3.z * mValue.r2.w)
		- mValue.r1.z * (mValue.r2.y * mValue.r3.w - mValue.r2.w * mValue.r3.y)
		+ mValue.r1.w * (mValue.r2.y * mValue.r3.z - mValue.r2.z * mValue.r3.y);

	v2 = mValue.r1.x * (mValue.r2.y * mValue.r3.w - mValue.r3.y * mValue.r2.w)
		- mValue.r1.z * (mValue.r2.x * mValue.r3.w - mValue.r2.w * mValue.r3.x)
		+ mValue.r1.w * (mValue.r2.x * mValue.r3.z - mValue.r3.x * mValue.r2.z);

	v3 = mValue.r1.x * (mValue.r2.y * mValue.r3.w - mValue.r2.w * mValue.r3.y)
		- mValue.r1.y * (mValue.r2.x * mValue.r3.w - mValue.r2.w * mValue.r3.x)
		+ mValue.r1.w * (mValue.r2.x * mValue.r3.y - mValue.r2.y * mValue.r3.x);

	v4 = mValue.r1.x * (mValue.r2.y * mValue.r3.z - mValue.r2.z * mValue.r3.y)
		- mValue.r1.y * (mValue.r2.x * mValue.r3.z - mValue.r2.z * mValue.r3.x)
		+ mValue.r1.z * (mValue.r2.x * mValue.r3.y - mValue.r2.y * mValue.r3.x);

	return mValue.r0.x * v1 - mValue.r0.y * v2 + mValue.r0.z * v3
		- mValue.r0.w * v4;
}

void Mat4x4::update() {
	mTranspose = transpose0();
	mDeterminant = computeDeterminant();
	if (invertible()) {
		mInverse = inverse0();
	} else {
		mInverse =
			{ { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
	}
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

mat4x4 Mat4x4::values() {
	return mValue;
}

Reference Mat4x4::getRow(tlint index) {
	vec4 v = getRow0(index);

	return Reference(new Vec4(v));
}

Reference Mat4x4::getColumn(tlint index) {
	vec4 v = getColumn0(index);

	return Reference(new Vec4(v));
}

void Mat4x4::set(tlint i, tlint j, float value) {
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

void Mat4x4::setRow(tlint i, vec4 v) {
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
	case 3:
		mValue.r3 = v;
		break;
	default:
		//cast an exception
	}

	update();
}

void Mat4x4::setColumn(tlint j, vec4 u) {
	switch (j) {
	case 0:
		mValue.r0.x = u.x;
		mValue.r1.x = u.y;
		mValue.r2.x = u.z;
		mValue.r3.x = u.w;
		break;
	case 1:
		mValue.r0.y = u.x;
		mValue.r1.y = u.y;
		mValue.r2.y = u.z;
		mValue.r3.y = u.w;
		break;
	case 2:
		mValue.r0.z = u.x;
		mValue.r1.z = u.y;
		mValue.r2.z = u.z;
		mValue.r3.z = u.w;
		break;
	case 3:
		mValue.r0.w = u.x;
		mValue.r1.w = u.y;
		mValue.r2.w = u.z;
		mValue.r3.w = u.w;
		break;
	default:
		//cast an exception
	}

	update();
}

bool Mat4x4::invertible() {
	return Math::abs(mDeterminant) < SquareMatrix::CRITICAL_DETERMINANT;
}

Reference Mat4x4::inverse() {
	return Reference(new Mat4x4(mInverse));
}

Reference Mat4x4::transpose() {
	return Reference(new Mat4x4(mTranspose));
}

Reference Mat4x4::toString() {
	char str[512];
	sprintf(str, "[%f, %f, %f, %f,\n", mValue.r0.x, mValue.r0.y, mValue.r0.z,
		mValue.r0.w);
	sprintf(str + strlen(str), " %f, %f, %f, %f,\n", mValue.r1.x, mValue.r1.y,
		mValue.r1.z, mValue.r1.w);
	sprintf(str + strlen(str), " %f, %f, %f, %f,\n", mValue.r2.x, mValue.r2.y,
		mValue.r2.z, mValue.r2.w);
	sprintf(str + strlen(str), " %f, %f, %f, %f]", mValue.r3.x, mValue.r3.y,
		mValue.r3.z, mValue.r3.w);

	return Reference(new String(str));
}

tlint Mat4x4::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat4x4::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat4x4::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat4x4::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

type_t Mat4x4::type() {
	return CLASS_SERIAL;
}

bool Mat4x4::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
