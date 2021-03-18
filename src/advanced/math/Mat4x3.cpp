/*
 * Mat4x3.cpp
 *
 *  Created on: Feb 17, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <string.h>
#include <tl/advanced/math/Mat3x4.h>
#include <tl/advanced/math/Mat4x3.h>
#include <tl/advanced/math/Vec3.h>
#include <tl/advanced/math/Vec4.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::IndexOutOfBoundsException;
using lang::String;

Mat4x3::Mat4x3() {
	// TODO Auto-generated constructor stub
	mValue = DEFAULT_VALUE;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x3::Mat4x3(mat4x3 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat4x3::~Mat4x3() {
	// TODO Auto-generated destructor stub
}

vec3 Mat4x3::getRow0(tlint i) {
	vec3 v;
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

vec4 Mat4x3::getColumn0(tlint i) {
	vec4 v;
	switch (i) {
	case 0:
		v.x = mValue.r0.x;
		v.y = mValue.r1.x;
		v.z = mValue.r2.x;
		v.w = mValue.r3.x;
		break;
	case 1:
		v.x = mValue.r0.y;
		v.y = mValue.r1.y;
		v.z = mValue.r2.y;
		v.w = mValue.r3.y;
		break;
	case 2:
		v.x = mValue.r0.z;
		v.y = mValue.r1.z;
		v.z = mValue.r2.z;
		v.w = mValue.r3.z;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	return v;
}

mat3x4 Mat4x3::transpose0() {
	mat3x4 m;
	m.r0 = getColumn0(0);
	m.r1 = getColumn0(1);
	m.r2 = getColumn0(2);
	return m;
}

void Mat4x3::update() {
	mTranspose = transpose0();
}

mat4x3 Mat4x3::values() {
	return mValue;
}

tlint Mat4x3::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat4x3::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat4x3::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat4x3::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MatrixType Mat4x3::matrixType() {
	return MATRIX_ARRANGEMENT;
}

Reference Mat4x3::getRow(tlint i) {
	vec3 v = getRow0(i);
	return Reference(new Vec3(v));
}

Reference Mat4x3::getColumn(tlint i) {
	vec4 v = getColumn0(i);
	return Reference(new Vec4(v));
}

void Mat4x3::set(tlint i, tlint j, float value) {
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

void Mat4x3::setRow(tlint i, vec3 v) {
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

void Mat4x3::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec3::type());

	Vec3 *v = dynamic_cast<Vec3*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat4x3::setColumn(tlint i, vec4 v) {
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
	case 2:
		mValue.r0.z = v.x;
		mValue.r1.z = v.y;
		mValue.r2.z = v.z;
		mValue.r3.z = v.w;
		break;
	default:
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	update();
}

void Mat4x3::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec4::type());

	Vec4 *v = dynamic_cast<Vec4*>(ref.getEntity());
	setColumn(i, v->values());
}

float Mat4x3::get(tlint i, tlint j) {
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

Reference Mat4x3::toString() {
	char str[200];
	sprintf(str, "[%f, %f, %f\n", mValue.r0.x, mValue.r0.y, mValue.r0.z);
	sprintf(str + strlen(str), " %f, %f, %f\n", mValue.r1.x, mValue.r1.y,
		mValue.r1.z);
	sprintf(str + strlen(str), " %f, %f, %f]", mValue.r2.x, mValue.r2.y,
		mValue.r2.z);
	return Reference(new String(str));
}

Reference Mat4x3::transpose() {
	return Reference(new Mat3x4(mTranspose));
}

type_t Mat4x3::type() {
	return CLASS_SERIAL;
}

bool Mat4x3::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Matrix::instanceof(type);
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
