/*
 * Complex.cpp
 *
 *  Created on: Mar 22, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Math.h>
#include <tl/math/Complex.h>

namespace tl {
namespace math {

using lang::Reference;
using lang::Math;

Complex::Complex(double real, double imaginary) {
	// TODO Auto-generated constructor stub
	mReal = real;
	mImaginary = imaginary;
	mModulus = Math::sqrt(mReal * mReal + mImaginary * mImaginary);

	mHashCode = genHashCode(CLASS_SERIAL);
}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

double Complex::real() {
	return mReal;
}

double Complex::imaginary() {
	return mImaginary;
}

Reference Complex::conjugate() {
	return Reference(new Complex(mReal, -mImaginary));
}

double Complex::modulus() {
	return mModulus;
}

Reference Complex::add(Reference u, Reference v) {
	dismissNull(u);
	dismissNull(v);
	argumentTypeCheck(u, Complex::type());
	argumentTypeCheck(v, Complex::type());

	Complex *c1 = dynamic_cast<Complex*>(u.getEntity());
	Complex *c2 = dynamic_cast<Complex*>(v.getEntity());

	return Reference(
		new Complex(c1->real() + c2->real(), c1->imaginary() + c2->imaginary()));
}

Reference Complex::multiply(Reference u, Reference v) {
	dismissNull(u);
	dismissNull(v);
	argumentTypeCheck(u, Complex::type());
	argumentTypeCheck(v, Complex::type());

	Complex *c1 = dynamic_cast<Complex*>(u.getEntity());
	Complex *c2 = dynamic_cast<Complex*>(v.getEntity());

	double real = c1->real() * c2->real() - c1->imaginary() * c2->imaginary();
	double imag = c1->real() * c2->imaginary() + c1->imaginary() * c2->real();

	return Reference(new Complex(real, imag));
}

type_t Complex::type() {
	return CLASS_SERIAL;
}

bool Complex::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace math */
} /* namespace tl */
