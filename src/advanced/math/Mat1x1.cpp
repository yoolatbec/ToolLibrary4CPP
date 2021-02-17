/*
 * Mat1x1.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#include "Mat1x1.h"
#include "../../lang/Math.h"
#include "../../lang/String.h"
#include <stdio.h>
#include "Vec.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::Math;
using lang::String;

Mat1x1::Mat1x1() {
	// TODO Auto-generated constructor stub
	mValue = identity_initialiser_mat1x1();
	mDeterminant = 1.0;
	mInverse = Reference(new Mat1x1(mValue));

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

double Mat1x1::computeDeterminant() {
	return mValue.r0.x;
}

Reference Mat1x1::inverse0() {
	mat1x1 m;
	m.r0.x = 1.0 / mValue.r0.x;

	return Reference(new Mat1x1(m));
}

void Mat1x1::update() {
	mDeterminant = computeDeterminant();
	if (invertible()) {
		mInverse = inverse0();
	} else {
		mInverse = Reference();
	}
}

bool Mat1x1::invertible() {
	return Math::abs(mDeterminant) < SquareMatrix::CRITICAL_DETERMINANT;
}

Reference Mat1x1::inverse() {
	return mInverse;
}

Reference Mat1x1::transpose() {
	return Reference(new Mat1x1(mValue));
}

void Mat1x1::set(tlint i, tlint j, float value) {
	if (i != MAX_ROW_INDEX || j != MAX_COLUMN_INDEX) {
		//cast an exception
	}

	mValue.r0.x = value;
	update();
}

void Mat1x1::setRow(tlint i, vec v) {
	if (i != MAX_ROW_INDEX) {
		//cast an exception
	}

	mValue.r0 = v;
	update();
}

void Mat1x1::setColumn(tlint j, vec v) {
	if (j != MAX_COLUMN_INDEX) {
		//cast an exception
	}

	mValue.r0 = v;
	update();
}

float Mat1x1::get(tlint i, tlint j) {
	if (i != MAX_ROW_INDEX || j != MAX_COLUMN_INDEX) {
		//cast an exception
	}

	return mValue.r0.x;
}

Reference Mat1x1::getRow(tlint i) {
	if (i != MAX_ROW_INDEX) {
		//cast an exception
	}

	vec v = mValue.r0;
	return Reference(new Vec(v));
}

Reference Mat1x1::getColumn(tlint j) {
	if (j != MAX_COLUMN_INDEX) {
		//cast an exception
	}

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

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
