/*
 * Mat2x2.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <string.h>
#include <tl/advanced/math/Mat2x2.h>
#include <tl/advanced/math/Vec2.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/Math.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::String;
using lang::Math;
using lang::IndexOutOfBoundsException;

Mat2x2::Mat2x2() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat2x2();
	mTranspose = mValue;
	mDeterminant = 1.0;
	mInverse = mValue;

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
		throw IndexOutOfBoundsException();
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
		throw IndexOutOfBoundsException();
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

mat2x2 Mat2x2::inverse0() {
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
		mInverse = { { 0, 0 }, { 0, 0 } };
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
		throw IndexOutOfBoundsException();
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
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat2x2::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec2::type());

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setRow(i, v->values());
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
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat2x2::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec2::type());

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setColumn(i, v->values());
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
		//cast an exception
		throw IndexOutOfBoundsException();
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
	return Reference(new Mat2x2(mInverse));
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

tlint Mat2x2::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat2x2::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat2x2::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat2x2::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat2x2::matrixType(){
	return MATRIX_ARRANGEMENT;
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
