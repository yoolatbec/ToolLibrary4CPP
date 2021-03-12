/*
 * Mat1x4.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include <string.h>
#include <stdio.h>
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

Mat1x4::Mat1x4() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat1x4::Mat1x4(mat1x4 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat1x4 Mat1x4::values() {
	return mValue;
}

mat4x1 Mat1x4::transpose0() {
	mat4x1 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);
	m.r3 = getColumn0(3);
	return m;
}

void Mat1x4::update() {
	mTranspose = transpose0();
}

vec4 Mat1x4::getRow0(tlint i) {
	if (i != MIN_ROW_INDEX) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return mValue.r0;
}

vec Mat1x4::getColumn0(tlint i) {
	vec v;
	switch (i) {
	case 0:
		v.x = mValue.r0.x;
		break;
	case 1:
		v.x = mValue.r0.y;
		break;
	case 2:
		v.x = mValue.r0.z;
		break;
	case 3:
		v.x = mValue.r0.w;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return v;
}

Reference Mat1x4::getRow(tlint i) {
	vec4 v = getRow0(i);
	return Reference(new Vec4(v));
}

Reference Mat1x4::getColumn(tlint i) {
	vec v = getColumn0(i);
	return Reference(new Vec(v));
}

float Mat1x4::get(tlint i, tlint j) {
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
		throw IndexOutOfBoundsException();
	}

	return value;
}

void Mat1x4::set(tlint i, tlint j, float value) {
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
		throw IndexOutOfBoundsException();
	}

	setRow(i, v);
}

void Mat1x4::setRow(tlint i, vec4 v) {
	switch (i) {
	case 0:
		mValue.r0 = v;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat1x4::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec4::type());

	Vec4 *v = dynamic_cast<Vec4*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat1x4::setColumn(tlint i, vec v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		break;
	case 1:
		mValue.r0.y = v.x;
		break;
	case 2:
		mValue.r0.z = v.x;
		break;
	case 3:
		mValue.r0.w = v.x;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat1x4::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec::type());

	Vec *v = dynamic_cast<Vec*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat1x4::transpose() {
	return Reference(new Mat4x1(mTranspose));
}

Reference Mat1x4::toString() {
	char str[100];
	sprintf(str, "[%f, %f, %f, %f]", mValue.r0.x, mValue.r0.y, mValue.r0.z,
		mValue.r0.w);
	return Reference(new String(str));
}

tlint Mat1x4::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat1x4::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat1x4::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat1x4::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat1x4::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Mat1x4::~Mat1x4() {
	// TODO Auto-generated destructor stub
}

type_t Mat1x4::type() {
	return CLASS_SERIAL;
}

bool Mat1x4::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
