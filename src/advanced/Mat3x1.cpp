/*
 * Mat3x1.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include "Mat3x1.h"
#include "Mat1x3.h"
#include "Vec.h"
#include "Vec3.h"
#include "../../lang/String.h"
#include <stdio.h>
#include <string.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;

Mat3x1::Mat3x1() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat3x1::Mat3x1(mat3x1 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat3x1 Mat3x1::values() {
	return mValue;
}

mat1x3 Mat3x1::transpose0() {
	mat1x3 m;
	m.r0 = getColumn0(0);
	return m;
}

void Mat3x1::update() {
	mTranspose = transpose0();
}

vec Mat3x1::getRow0(tlint i) {
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
	default:
		//cast an exception
	}

	return v;
}

vec3 Mat3x1::getColumn0(tlint i) {
	if (i != MIN_COLUMN_INDEX) {
		//cast an exception
	}

	vec3 v;
	v.x = mValue.r0.x;
	v.y = mValue.r1.x;
	v.z = mValue.r2.x;
	return v;
}

Reference Mat3x1::getRow(tlint i) {
	vec v = getRow0(i);
	return Reference(new Vec(v));
}

Reference Mat3x1::getColumn(tlint i) {
	vec3 v = getColumn0(i);
	return Reference(new Vec3(v));
}

float Mat3x1::get(tlint i, tlint j) {
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

void Mat3x1::set(tlint i, tlint j, float value) {
	vec v = getRow0(i);
	if (j != MIN_ROW_INDEX) {
		//cast an exception
	}

	v.x = value;

	setRow(i, v);
}

void Mat3x1::setRow(tlint i, vec v) {
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

void Mat3x1::setColumn(tlint i, vec3 v) {
	if (i != MIN_ROW_INDEX) {
		//cast an exception
	}

	mValue.r0.x = v.x;
	mValue.r1.x = v.y;
	mValue.r2.x = v.z;

	update();
}

Reference Mat3x1::transpose() {
	return Reference(new Mat1x3(mTranspose));
}

Reference Mat3x1::toString() {
	char str[100];
	sprintf(str, "[%f\n %f\n %f]", mValue.r0.x, mValue.r1.x, mValue.r2.x);
	return Reference(new String(str));
}

tlint Mat3x1::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat3x1::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat3x1::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat3x1::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

Mat3x1::~Mat3x1() {
	// TODO Auto-generated destructor stub
}

type_t Mat3x1::type(){
	return CLASS_SERIAL;
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
