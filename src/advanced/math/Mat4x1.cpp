/*
 * Mat4x1.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <string.h>
#include <tl/advanced/math/Mat1x4.h>
#include <tl/advanced/math/Mat4x1.h>
#include <tl/advanced/math/Vec.h>
#include <tl/advanced/math/Vec4.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;
using lang::IndexOutOfBoundsException;

Mat4x1::Mat4x1() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x1::Mat4x1(mat4x1 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat4x1 Mat4x1::values() {
	return mValue;
}

mat1x4 Mat4x1::transpose0() {
	mat1x4 m;
	m.r0 = getColumn0(0);
	return m;
}

void Mat4x1::update() {
	mTranspose = transpose0();
}

vec4 Mat4x1::getColumn0(tlint i) {
	if (i != MIN_COLUMN_INDEX) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	vec4 v;
	v.x = mValue.r0.x;
	v.y = mValue.r1.x;
	v.z = mValue.r2.x;
	v.w = mValue.r3.x;
	return v;
}

vec Mat4x1::getRow0(tlint i) {
	vec v;
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
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return v;
}

Reference Mat4x1::getRow(tlint i) {
	vec v = getRow0(i);
	return Reference(new Vec(v));
}

Reference Mat4x1::getColumn(tlint i) {
	vec4 v = getColumn0(i);
	return Reference(new Vec4(v));
}

float Mat4x1::get(tlint i, tlint j) {
	vec v = getRow0(i);
	float value;
	switch (j) {
	case 0:
		value = v.x;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return value;
}

void Mat4x1::set(tlint i, tlint j, float value) {
	vec v = getRow0(i);
	switch (j) {
	case 0:
		v.x = value;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	setRow(i, v);
}

void Mat4x1::setRow(tlint i, vec v) {
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

void Mat4x1::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec::type());

	Vec *v = dynamic_cast<Vec*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat4x1::setColumn(tlint i, vec4 v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		mValue.r1.x = v.y;
		mValue.r2.x = v.z;
		mValue.r3.x = v.w;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat4x1::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec4::type());

	Vec4 *v = dynamic_cast<Vec4*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat4x1::transpose() {
	return Reference(new Mat1x4(mTranspose));
}

Reference Mat4x1::toString() {
	char str[100];
	sprintf(str, "[%f\n %f\n %f\n %f]", mValue.r0.x, mValue.r1.x, mValue.r2.x,
		mValue.r3.x);
	return Reference(new String(str));
}

tlint Mat4x1::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat4x1::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat4x1::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat4x1::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MatrixType Mat4x1::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Mat4x1::~Mat4x1() {
	// TODO Auto-generated destructor stub
}

type_t Mat4x1::type() {
	return CLASS_SERIAL;
}

bool Mat4x1::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
