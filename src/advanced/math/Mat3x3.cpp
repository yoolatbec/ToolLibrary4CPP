/*
 * Mat3x3.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/Mat3x3.h>
#include <advanced/math/Vec3.h>
#include <lang/Math.h>
#include <lang/String.h>

#include <stdio.h>
#include <string.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::Math;
using lang::String;

Mat3x3::Mat3x3() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat3x3();
	mTranspose = mValue;
	mInverse = mValue;
	mDeterminant = 1.0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x3::Mat3x3(mat3x3 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x3::~Mat3x3() {
	// TODO Auto-generated destructor stub
}

vec3 Mat3x3::getRow0(tlint i) {
	vec3 v;
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

vec3 Mat3x3::getColumn0(tlint j) {
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
	default:
		//cast an exception
	}

	return v;
}

mat3x3 Mat3x3::transpose0() {
	mat3x3 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);

	return m;
}

double Mat3x3::computeDeterminant() {
	return (mValue.r0.x
		* (mValue.r1.y * mValue.r2.z - mValue.r1.z * mValue.r2.y)
		- mValue.r0.y * (mValue.r1.x * mValue.r2.z - mValue.r1.z * mValue.r2.x)
		+ mValue.r0.z * (mValue.r1.x * mValue.r2.y - mValue.r1.y * mValue.r2.x));
}

mat3x3 Mat3x3::inverse0() {
	mat3x3 m;
	m.r0.x = (mValue.r1.y * mValue.r2.z - mValue.r1.z * mValue.r2.y)
		/ mDeterminant;
	m.r0.y = -(mValue.r1.x * mValue.r2.z - mValue.r1.z * mValue.r2.x)
		/ mDeterminant;
	m.r0.z = (mValue.r1.x * mValue.r2.y - mValue.r1.y * mValue.r2.x)
		/ mDeterminant;

	m.r1.x = -(mValue.r0.y * mValue.r2.z - mValue.r0.z * mValue.r2.y)
		/ mDeterminant;
	m.r1.y = (mValue.r0.x * mValue.r2.z - mValue.r0.z * mValue.r2.x)
		/ mDeterminant;
	m.r1.z = -(mValue.r0.x * mValue.r2.y - mValue.r0.y * mValue.r2.x)
		/ mDeterminant;

	m.r2.x = (mValue.r0.y * mValue.r1.z - mValue.r0.z * mValue.r1.y)
		/ mDeterminant;
	m.r2.y = -(mValue.r0.x * mValue.r1.z - mValue.r0.z * mValue.r1.x)
		/ mDeterminant;
	m.r2.z = (mValue.r0.x * mValue.r1.y - mValue.r0.y * mValue.r1.x)
		/ mDeterminant;

	return m;
}

void Mat3x3::update() {
	mTranspose = transpose0();
	mDeterminant = computeDeterminant();
	if (invertible()) {
		mInverse = inverse0();
	} else {
		mInverse = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
	}
}

bool Mat3x3::invertible() {
	return Math::abs(mDeterminant) < SquareMatrix::CRITICAL_DETERMINANT;
}

Reference Mat3x3::inverse() {
	return Reference(new Mat3x3(mInverse));
}

Reference Mat3x3::transpose() {
	return Reference(new Mat3x3(mTranspose));
}

float Mat3x3::get(tlint i, tlint j) {
	vec3 v = getRow0(i);
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
	default:
		//cast an exception
	}

	return value;
}

Reference Mat3x3::getRow(tlint i) {
	vec3 v = getRow0(i);

	return Reference(new Vec3(v));
}

Reference Mat3x3::getColumn(tlint j) {
	vec3 v = getColumn0(j);

	return Reference(new Vec3(v));
}

void Mat3x3::set(tlint i, tlint j, float value) {
	vec3 v = getRow0(i);
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
	default:
		//cast an exception
	}

	setRow(i, v);
}

void Mat3x3::setRow(tlint i, vec3 v) {
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

void Mat3x3::setRow(tlint i, Reference ref) {
	if (!ref.getEntity()->instanceof(Vec3::type())) {
		//cast an exception
	}

	Vec3 *v = dynamic_cast<Vec3*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat3x3::setColumn(tlint j, vec3 v) {
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
	default:
		//cast an exception
	}

	update();
}

void Mat3x3::setColumn(tlint i, Reference ref) {
	if (!ref.getEntity()->instanceof(Vec3::type())) {
		//cast an exception
	}

	Vec3 *v = dynamic_cast<Vec3*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat3x3::toString() {
	char str[200];
	sprintf(str, "[%f, %f, %f\n", mValue.r0.x, mValue.r0.y, mValue.r0.z);
	sprintf(str + strlen(str), " %f, %f, %f\n", mValue.r1.x, mValue.r1.y,
		mValue.r1.z);
	sprintf(str + strlen(str), " %f, %f, %f]", mValue.r2.x, mValue.r2.y,
		mValue.r2.z);
	return Reference(new String(str));
}

tlint Mat3x3::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat3x3::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat3x3::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat3x3::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat3x3::matrixType() {
	return MATRIX_ARRANGEMENT;
}

type_t Mat3x3::type() {
	return CLASS_SERIAL;
}

bool Mat3x3::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SquareMatrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
