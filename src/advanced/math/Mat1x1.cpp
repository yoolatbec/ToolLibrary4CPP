/*
 * Mat1x1.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#include <stdio.h>
#include <tl/advanced/math/Mat1x1.h>
#include <tl/advanced/math/Vec.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/Math.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::Math;
using lang::String;
using lang::IndexOutOfBoundsException;

Mat1x1::Mat1x1() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat1x1();
	mDeterminant = 1.0;
	mInverse = mValue;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat1x1::Mat1x1(mat1x1 initValue) {
	mValue = initValue;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Mat1x1::~Mat1x1() {
	// TODO Auto-generated destructor stub
}

void Mat1x1::rowIndexCheck(tlint r) {
	if (r < MIN_ROW_INDEX || r > MAX_ROW_INDEX) {
		throw IndexOutOfBoundsException();
	}
}

void Mat1x1::columnIndexCheck(tlint c) {
	if (c < MIN_COLUMN_INDEX || c > MAX_ROW_INDEX) {
		throw IndexOutOfBoundsException();
	}
}

double Mat1x1::computeDeterminant() {
	return mValue.r0.x;
}

mat1x1 Mat1x1::inverse0() {
	mat1x1 m;
	m.r0.x = 1.0 / mValue.r0.x;

	return m;
}

void Mat1x1::update() {
	mDeterminant = computeDeterminant();
	if (invertible()) {
		mInverse = inverse0();
	} else {
		mInverse =
			{
				{ 0 } };
	}
}

bool Mat1x1::invertible() {
	return Math::abs(mDeterminant) < SquareMatrix::CRITICAL_DETERMINANT;
}

Reference Mat1x1::inverse() {
	return Reference(new Mat1x1(mInverse));
}

Reference Mat1x1::transpose() {
	return Reference(new Mat1x1(mValue));
}

void Mat1x1::set(tlint i, tlint j, float value) {
	rowIndexCheck(i);
	columnIndexCheck(j);

	mValue.r0.x = value;
	update();
}

void Mat1x1::setRow(tlint i, vec v) {
	rowIndexCheck(i);

	mValue.r0 = v;
	update();
}

void Mat1x1::setRow(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec::type());

	Vec *v = dynamic_cast<Vec*>(ref.getEntity());
	setRow(i, v->values());
}

void Mat1x1::setColumn(tlint j, vec v) {
	columnIndexCheck(j);

	mValue.r0 = v;
	update();
}

void Mat1x1::setColumn(tlint i, Reference ref) {
	argumentTypeCheck(ref, Vec::type());

	Vec *v = dynamic_cast<Vec*>(ref.getEntity());
	setColumn(i, v->values());
}

float Mat1x1::get(tlint i, tlint j) {
	rowIndexCheck(i);
	columnIndexCheck(j);

	return mValue.r0.x;
}

Reference Mat1x1::getRow(tlint i) {
	rowIndexCheck(i);

	vec v = mValue.r0;
	return Reference(new Vec(v));
}

Reference Mat1x1::getColumn(tlint j) {
	columnIndexCheck(j);

	vec v = mValue.r0;
	return Reference(new Vec(v));
}

mat1x1 Mat1x1::values() {
	return mValue;
}

Reference Mat1x1::toString() {
	char str[50];
	sprintf(str, "[%f]", mValue.r0.x);
	return Reference(new String(str));
}

type_t Mat1x1::type() {
	return CLASS_SERIAL;
}

bool Mat1x1::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SquareMatrix::instanceof(type);
}

tlint Mat1x1::maxRowIndex() {
	return MAX_ROW_INDEX;
}

tlint Mat1x1::minRowIndex() {
	return MIN_ROW_INDEX;
}

tlint Mat1x1::maxColumnIndex() {
	return MAX_COLUMN_INDEX;
}

tlint Mat1x1::minColumnIndex() {
	return MIN_COLUMN_INDEX;
}

MATRIX_TYPE Mat1x1::matrixType() {
	return MATRIX_ARRANGEMENT;
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
