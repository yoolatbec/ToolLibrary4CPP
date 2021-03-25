/*
 * Quaternion.cpp
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#include "Quaternion.h"
#include <tl/lang/Math.h>
#include <tl/lang/UnacceptableArgumentException.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::Math;
using lang::IllegalArgumentException;

Quaternion::Quaternion(float x, float y, float z, float w) {
	// TODO Auto-generated constructor stub
	mValue =
		{ x, y, z, w };
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Quaternion::Quaternion(quaternion q) {
	mValue = q;
	update();

	mHashCode = genHashCode(CLASS_SERIAL);
}

void Quaternion::update() {
	mModulus = computeModulus();
	if (invertible()) {
		mInverse = inverse0();
	} else {
		mInverse =
			{ DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE };
	}

	mConjugate = conjugate0();
}

quaternion Quaternion::conjugate0() {
	quaternion result =
		{ mValue.x, -mValue.y, -mValue.z, -mValue.w };

	return result;
}

float Quaternion::computeModulus() {
	return Math::sqrt(
		mValue.x * mValue.x + mValue.y * mValue.y + mValue.z * mValue.z
			+ mValue.w * mValue.w);
}

Quaternion::~Quaternion() {
	// TODO Auto-generated destructor stub
}

bool Quaternion::invertible() {
	return mModulus > INVERSE_CRITICAL_VALUE;
}

float Quaternion::modulus() {
	return mModulus;
}

float Quaternion::value(tlint index) {
	float result;
	switch (index) {
	case 0:
		result = mValue.x;
		break;
	case 1:
		result = mValue.y;
		break;
	case 2:
		result = mValue.z;
		break;
	case 3:
		result = mValue.w;
		break;
	default:
		throw IllegalArgumentException();
	}

	return result;
}

quaternion Quaternion::values() {
	return mValue;
}

Reference Quaternion::inverse() {
	return Reference(new Quaternion(mInverse));
}

Reference Quaternion::conjugate() {
	return Reference(new Quaternion(mConjugate));
}

float Quaternion::dot(Reference p, Reference q) {
	dismissNull(p);
	dismissNull(q);
	argumentTypeCheck(p, Quaternion::type());
	argumentTypeCheck(q, Quaternion::type());

	Quaternion *p1 = dynamic_cast<Quaternion*>(p.getEntity());
	Quaternion *q1 = dynamic_cast<Quaternion*>(q.getEntity());

	float value = 0;
	for (tlint i = MIN_COMPONENT_INDEX; i < MAX_COMPONENT_INDEX; i++) {
		value += p1->value(i) * q1->value(i);
	}

	return value;
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
