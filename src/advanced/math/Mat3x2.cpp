/*
 * Mat3x2.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#include <string.h>
#include <stdio.h>
#include <tl/advanced/math/Mat2x3.h>
#include <tl/advanced/math/Mat3x2.h>
#include <tl/advanced/math/Vec2.h>
#include <tl/advanced/math/Vec3.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;
using lang::IndexOutOfBoundsException;

Mat3x2::Mat3x2() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x2::Mat3x2(mat3x2 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x2::~Mat3x2() {
	// TODO Auto-generated destructor stub
}

vec2 Mat3x2::getRow0(tlint i) {
	vec2 v;
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
		throw IndexOutOfBoundsException();
	}

	return v;
}

vec3 Mat3x2::getColumn0(tlint i) {
	vec3 v;
	switch (i) {
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
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return v;
}

mat2x3 Mat3x2::transpose0() {
	mat2x3 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	return m;
}

void Mat3x2::update() {
	mTranspose = transpose0();
}

mat3x2 Mat3x2::values() {
	return mValue;
}

Reference Mat3x2::getRow(tlint i) {
	vec2 v = getRow0(i);
	return Reference(new Vec2(v));
}

Reference Mat3x2::getColumn(tlint i) {
	vec3 v = getColumn0(i);
	return Reference(new Vec3(v));
}

float Mat3x2::get(tlint i, tlint j) {
	vec2 v = getRow0(i);
	float value;
	switch (i) {
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

void Mat3x2::set(tlint i, tlint j, float value) {
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

void Mat3x2::setRow(tlint i, vec2 v) {
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
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat3x2::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec2::type());

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat3x2::setColumn(tlint i, vec3 v) {
	switch (i) {
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
	default:
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat3x2::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec3::type());

	Vec3 *v = dynamic_cast<Vec3*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat3x2::transpose() {
	return Reference(new Mat2x3(mTranspose));
}

Reference Mat3x2::toString() {
	char str[200];
	sprintf(str, "[%f, %f\n", mValue.r0.x, mValue.r0.y);
	sprintf(str + strlen(str), " %f, %f\n", mValue.r1.x, mValue.r1.y);
	sprintf(str + strlen(str), " %f, %f]", mValue.r2.x, mValue.r2.y);
	return Reference(new String(str));
}

tlint Mat3x2::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat3x2::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat3x2::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat3x2::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat3x2::matrixType() {
	return MATRIX_ARRANGEMENT;
}

type_t Mat3x2::type() {
	return CLASS_SERIAL;
}

bool Mat3x2::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
