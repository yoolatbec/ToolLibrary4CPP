/*
 * Mat1x2.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <string.h>
#include <tl/advanced/math/Mat1x2.h>
#include <tl/advanced/math/Mat2x1.h>
#include <tl/advanced/math/Vec.h>
#include <tl/advanced/math/Vec2.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;
using lang::IndexOutOfBoundsException;

Mat1x2::Mat1x2() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat1x2::Mat1x2(mat1x2 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat1x2 Mat1x2::values() {
	return mValue;
}

mat2x1 Mat1x2::transpose0() {
	mat2x1 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	return m;
}

void Mat1x2::update() {
	mTranspose = transpose0();
}

vec2 Mat1x2::getRow0(tlint i) {
	if (i != MIN_ROW_INDEX) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return mValue.r0;
}

vec Mat1x2::getColumn0(tlint i) {
	vec v;
	switch (i) {
	case 0:
		v.x = mValue.r0.x;
		break;
	case 1:
		v.x = mValue.r0.y;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return v;
}

Reference Mat1x2::getRow(tlint i) {
	vec2 v = getRow0(i);
	return Reference(new Vec2(v));
}

Reference Mat1x2::getColumn(tlint i) {
	vec v = getColumn0(i);
	return Reference(new Vec(v));
}

float Mat1x2::get(tlint i, tlint j) {
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

void Mat1x2::set(tlint i, tlint j, float value) {
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

void Mat1x2::setRow(tlint i, vec2 v) {
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

void Mat1x2::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec2::type());

	Vec2 *v = dynamic_cast<Vec2*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat1x2::setColumn(tlint i, vec v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		break;
	case 1:
		mValue.r0.y = v.x;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat1x2::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec::type());

	Vec *v = dynamic_cast<Vec*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat1x2::transpose() {
	return Reference(new Mat2x1(mTranspose));
}

Reference Mat1x2::toString() {
	char str[100];
	sprintf(str, "[%f, %f]", mValue.r0.x, mValue.r0.y);
	return Reference(new String(str));
}

tlint Mat1x2::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat1x2::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat1x2::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat1x2::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat1x2::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Mat1x2::~Mat1x2() {
	// TODO Auto-generated destructor stub
}

type_t Mat1x2::type() {
	return CLASS_SERIAL;
}

bool Mat1x2::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
