/*
 * Mat4x2.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <string.h>
#include <tl/advanced/math/Mat2x4.h>
#include <tl/advanced/math/Mat4x2.h>
#include <tl/advanced/math/Vec2.h>
#include <tl/advanced/math/Vec4.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;
using lang::IndexOutOfBoundsException;

Mat4x2::Mat4x2() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x2::Mat4x2(mat4x2 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat2x4 Mat4x2::transpose0() {
	mat2x4 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	return m;
}

void Mat4x2::update() {
	mTranspose = transpose0();
}

mat4x2 Mat4x2::values() {
	return mValue;
}

Reference Mat4x2::getRow(tlint i) {
	vec2 v = getRow0(i);
	return Reference(new Vec2(v));
}

Reference Mat4x2::getColumn(tlint i) {
	vec4 v = getColumn0(i);
	return Reference(new Vec4(v));
}

float Mat4x2::get(tlint i, tlint j) {
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
		throw IndexOutOfBoundsException();
	}

	return value;
}

void Mat4x2::set(tlint i, tlint j, float value) {
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

void Mat4x2::setRow(tlint i, vec2 v) {
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
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat4x2::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec2::type());

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat4x2::setColumn(tlint i, vec4 v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		mValue.r1.x = v.y;
		mValue.r2.x = v.z;
		mValue.r3.x = v.w;
		break;
	case 1:
		mValue.r0.y = v.x;
		mValue.r1.y = v.y;
		mValue.r2.y = v.z;
		mValue.r3.y = v.w;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat4x2::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec4::type());

	Vec4 *v = dynamic_cast<Vec4*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat4x2::transpose() {
	return Reference(new Mat2x4(mTranspose));
}

Reference Mat4x2::toString() {
	char str[200];
	sprintf(str, "[%f, %f\n", mValue.r0.x, mValue.r0.y);
	sprintf(str + strlen(str), " %f, %f\n", mValue.r1.x, mValue.r1.y);
	sprintf(str + strlen(str), " %f, %f\n", mValue.r2.x, mValue.r2.y);
	sprintf(str + strlen(str), " %f, %f]", mValue.r3.x, mValue.r3.y);
	return Reference(new String(str));
}

tlint Mat4x2::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat4x2::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat4x2::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat4x2::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat4x2::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Mat4x2::~Mat4x2() {
	// TODO Auto-generated destructor stub
}

type_t Mat4x2::type() {
	return CLASS_SERIAL;
}

bool Mat4x2::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
