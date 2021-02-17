/*
 * Mat2x2.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#include "Mat2x2.h"
#include "Vec2.h"
#include <stdio.h>
#include <string.h>
#include "../../lang/String.h"
#include "../../lang/Math.h"

namespace tl {
namespace advanced {
namespace math {

using lang::String;
using lang::Math;

Mat2x2::Mat2x2() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat2x2();
	mTranspose = mValue;
	mDeterminant = 1.0;
	mInverse = Reference(new Mat2x2(mValue));

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat2x2::Mat2x2(mat2x2 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat2x2::~Mat2x2() {
	// TODO Auto-generated destructor stub
}

vec2 Mat2x2::getRow0(tlint i) {
	vec2 v;
	switch (i) {
	case 0:
		v = mValue.r0;
		break;
	case 1:
		v = mValue.r1;
		break;
	default:
		//cast an exception
	}

	return v;
}

vec2 Mat2x2::getColumn0(tlint i) {
	vec2 v;
	switch (i) {
	case 0:
		v.x = mValue.r0.x;
		v.y = mValue.r1.x;
		break;
	case 1:
		v.x = mValue.r0.y;
		v.y = mValue.r1.y;
		break;
	default:
		//cast an exception
	}

	return v;
}

mat2x2 Mat2x2::transpose0() {
	mat2x2 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);

	return m;
}

double Mat2x2::computeDeterminant() {
	return (mValue.r0.x * mValue.r1.y - mValue.r0.y * mValue.r1.x);
}

Reference Mat2x2::inverse0() {
	mat2x2 m;
	m.r0.x = mValue.r1.y / mDeterminant;
	m.r0.y = -mValue.r1.x / mDeterminant;
	m.r1.x = -mValue.r0.y / mDeterminant;
	m.r1.y = mValue.r0.x / mDeterminant;

	return m;
}

void Mat2x2::update() {
	mTranspose = transpose0();
	mDeterminant = computeDeterminant();
	if (invertible()) {
		mInverse = inverse0();
	} else {
		mInverse = Reference();
	}
}

void Mat2x2::set(tlint i, tlint j, float value) {
	vec2 v = getRow0(i);
	switch (j) {
	case 0:
		v.x = value;
		break;
	case 1:
		v.y = value;
		break;
	default:
		//cast an exception
	}

	setRow(i, v);
}

void Mat2x2::setRow(tlint i, vec2 v) {
	switch (i) {
	case 0:
		mValue.r0 = v;
		break;
	case 1:
		mValue.r1 = v;
		break;
	default:
		//cast an exception
	}

	update();
}

void Mat2x2::setColumn(tlint i, vec2 v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		mValue.r1.x = v.y;
		break;
	case 1:
		mValue.r0.y = v.x;
		mValue.r1.y = v.y;
		break;
	default:
		//cast an exception
	}

	update();
}

float Mat2x2::get(tlint i, tlint j) {
	vec2 v = getRow0(i);
	float value;
	switch (j) {
	case 0:
		value = v.x;
		break;
	case 1:
		value = v.y;
		break;
	default:
		//cast an exceptoin
	}

	return value;
}

Reference Mat2x2::getRow(tlint i) {
	vec2 v = getRow0(i);
	return Reference(new Vec2(v));
}

Reference Mat2x2::getColumn(tlint i) {
	vec2 v = getColumn0(i);
	return Reference(new Vec2(v));
}

mat2x2 Mat2x2::values() {
	return mValue;
}

bool Mat2x2::invertible() {
	return Math::abs(mDeterminant) < SquareMatrix::CRITICAL_DETERMINANT;
}

Reference Mat2x2::inverse() {
	return mInverse;
}

Reference Mat2x2::transpose() {
	return Reference(new Mat2x2(mTranspose));
}

Reference Mat2x2::toString() {
	char str[200];
	sprintf(str, "[%f, %f,\n", mValue.r0.x, mValue.r0.y);
	sprintf(str + strlen(str), " %f, %f]", mValue.r1.x, mValue.r1.y);
	return Reference(new String(str));
}

type_t Mat2x2::type() {
	return CLASS_SERIAL;
}

bool Mat2x2::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SquareMatrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
