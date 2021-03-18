/*
 * Mat2x3.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <string.h>
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

Mat2x3::Mat2x3() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat2x3::Mat2x3(mat2x3 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat3x2 Mat2x3::transpose0() {
	mat3x2 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);

	return m;
}

vec3 Mat2x3::getRow0(tlint i) {
	vec3 v;
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

vec2 Mat2x3::getColumn0(tlint i) {
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
	case 2:
		v.x = mValue.r0.z;
		v.y = mValue.r1.z;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return v;
}

void Mat2x3::update() {
	mTranspose = transpose0();
}

mat2x3 Mat2x3::values() {
	return mValue;
}

Reference Mat2x3::getRow(tlint i) {
	vec3 v = getRow0(i);
	return Reference(new Vec3(v));
}

Reference Mat2x3::getColumn(tlint i) {
	vec2 v = getColumn0(i);
	return Reference(new Vec2(v));
}

float Mat2x3::get(tlint i, tlint j) {
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
		throw IndexOutOfBoundsException();
	}

	return value;
}

void Mat2x3::set(tlint i, tlint j, float value) {
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
		throw IndexOutOfBoundsException();
	}

	setRow(i, v);
}

void Mat2x3::setRow(tlint i, vec3 v) {
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

void Mat2x3::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec3::type());

	Vec3 *v = dynamic_cast<Vec3*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat2x3::setColumn(tlint i, vec2 v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		mValue.r1.x = v.y;
		break;
	case 1:
		mValue.r0.y = v.x;
		mValue.r1.y = v.y;
		break;
	case 2:
		mValue.r0.z = v.x;
		mValue.r1.z = v.y;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat2x3::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec2::type());

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat2x3::transpose() {
	return Reference(new Mat3x2(mTranspose));
}

tlint Mat2x3::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat2x3::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat2x3::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat2x3::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MatrixType Mat2x3::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Reference Mat2x3::toString() {
	char str[200];
	sprintf(str, "[%f, %f, %f\n", mValue.r0.x, mValue.r0.y, mValue.r0.z);
	sprintf(str + strlen(str), " %f, %f, %f]", mValue.r1.x, mValue.r1.y,
		mValue.r1.z);
	return Reference(new String(str));
}

Mat2x3::~Mat2x3() {
	// TODO Auto-generated destructor stub
}

type_t Mat2x3::type() {
	return CLASS_SERIAL;
}

bool Mat2x3::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
