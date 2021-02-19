/*
 * Mat2x1.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: yoolatbec
 */

#include "Mat2x1.h"
#include "Mat1x2.h"
#include "Vec.h"
#include "Vec2.h"
#include <stdio.h>
#include <string.h>
#include "../../lang/String.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;

Mat2x1::Mat2x1() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat2x1::Mat2x1(mat2x1 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat2x1 Mat2x1::values() {
	return mValue;
}

mat1x2 Mat2x1::transpose0() {
	mat1x2 m;
	m.r0 = getColumn0(0);
	return m;
}

void Mat2x1::update() {
	mTranspose = transpose0();
}

vec Mat2x1::getRow0(tlint i) {
	vec v;
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

vec2 Mat2x1::getColumn0(tlint i) {
	if (i != MIN_COLUMN_INDEX) {
		//cast an exception
	}

	vec2 v;
	v.x = mValue.r0.x;
	v.y = mValue.r1.x;
	return v;
}

float Mat2x1::get(tlint i, tlint j) {
	vec v = getRow0(i);
	float value;
	switch (j) {
	case 0:
		value = v.x;
		break;
	default:
		//cast an exception
	}

	return value;
}

Reference Mat2x1::getRow(tlint i) {
	vec v = getRow0(i);
	return Reference(new Vec(v));
}

Reference Mat2x1::getColumn(tlint i) {
	vec2 v = getColumn0(i);
	return Reference(new Vec2(v));
}

void Mat2x1::set(tlint i, tlint j, float value) {
	vec v = getRow0(i);
	switch (j) {
	case 0:
		v.x = value;
		break;
	default:
		//cast an exception
	}

	setRow(i, v);
}

void Mat2x1::setRow(tlint i, vec v) {
	switch (i) {
	case 0:
		mValue.r0 = v;
		break;
	case 1:
		mValue.r1 = v;
		break;
	default:
		// cast an exception
	}

	update();
}

void Mat2x1::setColumn(tlint i, vec2 v) {
	switch (i) {
	case 0:
		mValue.r0.x = v.x;
		mValue.r1.x = v.y;
		break;
	default:
		//cast an exception
	}

	update();
}

Reference Mat2x1::transpose() {
	return Reference(new Mat1x2(mTranspose));
}

Reference Mat2x1::toString() {
	char str[100];
	sprintf(str, "[%f\n", mValue.r0.x);
	sprintf(str + strlen(str), " %f]", mValue.r1.x);
	return Reference(new String(str));
}

tlint Mat2x1::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat2x1::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat2x1::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat2x1::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

Mat2x1::~Mat2x1() {
	// TODO Auto-generated destructor stub
}

type_t Mat2x1::type() {
	return CLASS_SERIAL;
}

bool Mat2x1::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
