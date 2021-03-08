/*
 * Mat1x3.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include <advanced/math/Mat1x3.h>
#include <advanced/math/Mat3x1.h>
#include <advanced/math/Vec.h>
#include <advanced/math/Vec3.h>
#include <lang/String.h>

#include <stdio.h>
#include <string.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;

Mat1x3::Mat1x3() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat1x3::Mat1x3(mat1x3 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

mat1x3 Mat1x3::values() {
	return mValue;
}

mat3x1 Mat1x3::transpose0() {
	mat3x1 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);
	return m;
}

void Mat1x3::update() {
	mTranspose = transpose0();

}

vec3 Mat1x3::getRow0(tlint i) {
	if (i != MIN_ROW_INDEX) {
		//cast an exception
	}

	return mValue.r0;
}

vec Mat1x3::getColumn0(tlint i) {
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
	default:
		//cast an exception
	}

	return v;
}

Reference Mat1x3::getRow(tlint i) {
	vec3 v = getRow0(i);
	return Reference(new Vec3(v));
}

Reference Mat1x3::getColumn(tlint i) {
	vec v = getColumn0(i);
	return Reference(new Vec(v));
}

float Mat1x3::get(tlint i, tlint j) {
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

void Mat1x3::set(tlint i, tlint j, float value) {
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

void Mat1x3::setRow(tlint i, vec3 v) {
	switch (i) {
	case 0:
		mValue.r0 = v;
		break;
	default:
		//cast an exception
	}

	update();
}

void Mat1x3::setRow(tlint i, Reference ref) {
	if (!ref.getEntity()->instanceof(Vec3::type())) {
		//cast an exception
	}

	Vec3 *v = dynamic_cast<Vec3*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat1x3::setColumn(tlint i, vec v) {
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
	default:
		//cast an exception
	}

	update();
}

void Mat1x3::setColumn(tlint i, Reference ref) {
	if (!ref.getEntity()->instanceof(Vec::type())) {
		//cast an exception
	}

	Vec *v = dynamic_cast<Vec*>(ref.getEntity());
	setColumn(i, v->values());
}

Reference Mat1x3::transpose() {
	return Reference(new Mat3x1(mTranspose));
}

Reference Mat1x3::toString() {
	char str[100];
	sprintf(str, "[%f, %f, %f]", mValue.r0.x, mValue.r0.y, mValue.r0.z);
	return Reference(new String(str));
}

tlint Mat1x3::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat1x3::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat1x3::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat1x3::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat1x3::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Mat1x3::~Mat1x3() {
	// TODO Auto-generated destructor stub
}

type_t Mat1x3::type() {
	return CLASS_SERIAL;
}

bool Mat1x3::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
