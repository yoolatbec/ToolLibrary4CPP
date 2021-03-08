/*
 * Mat2x4.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/Mat2x4.h>
#include <advanced/math/Mat4x2.h>
#include <advanced/math/Vec2.h>
#include <advanced/math/Vec4.h>
#include <lang/String.h>

#include <stdio.h>
#include <string.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;

Mat2x4::Mat2x4() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat2x4::Mat2x4(mat2x4 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat2x4 Mat2x4::values() {
	return mValue;
}

mat4x2 Mat2x4::transpose0() {
	mat4x2 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);
	m.r3 = getColumn0(3);
	return m;
}

void Mat2x4::update() {
	mTranspose = transpose0();
}

vec4 Mat2x4::getRow0(tlint i) {
	vec4 v;
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

vec2 Mat2x4::getColumn0(tlint i) {
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
	case 3:
		v.x = mValue.r0.w;
		v.y = mValue.r1.w;
		break;
	default:
		//cast an exception
	}

	return v;
}

Reference Mat2x4::getRow(tlint i) {
	vec4 v = getRow0(i);
	return Reference(new Vec4(v));
}

Reference Mat2x4::getColumn(tlint i) {
	vec2 v = getColumn0(i);
	return Reference(new Vec2(v));
}

float Mat2x4::get(tlint i, tlint j) {
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

void Mat2x4::set(tlint i, tlint j, float value) {
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

void Mat2x4::setRow(tlint i, vec4 v) {
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

void Mat2x4::setRow(tlint i, Reference ref) {
	if (!ref.getEntity()->instanceof(Vec4::type())) {
		//cast an exception
	}

	Vec4 *v = dynamic_cast<Vec4*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat2x4::setColumn(tlint i, vec2 v) {
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
	case 3:
		mValue.r0.w = v.x;
		mValue.r1.w = v.y;
		break;
	default:
		//cast an exception
	}

	update();
}

void Mat2x4::setColumn(tlint i, Reference ref) {
	if (!ref.getEntity()->instanceof(Vec2::type())) {
		//cast an exception
	}

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat2x4::transpose() {
	return Reference(new Mat4x2(mTranspose));
}

Reference Mat2x4::toString() {
	char str[200];
	sprintf(str, "[%f, %f, %f, %f\n", mValue.r0.x, mValue.r0.y, mValue.r0.z,
		mValue.r0.w);
	sprintf(str + strlen(str), " %f, %f, %f, %f]", mValue.r1.x, mValue.r1.y,
		mValue.r1.z, mValue.r1.w);
	return Reference(new String(str));
}

tlint Mat2x4::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat2x4::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat2x4::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat2x4::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat2x4::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Mat2x4::~Mat2x4() {
	// TODO Auto-generated destructor stub
}

type_t Mat2x4::type() {
	return CLASS_SERIAL;
}

bool Mat2x4::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
