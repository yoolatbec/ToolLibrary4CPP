/*
 * Complex.h
 *
 *  Created on: Mar 22, 2021
 *      Author: yoolatbec
 */

#ifndef TL_MATH_COMPLEX_H_
#define TL_MATH_COMPLEX_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace math {

using lang::Reference;

class Complex: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 235;
	constexpr const static double DEFAULT_REAL = 0;
	constexpr const static double DEFAULT_IMAGINARY = 0;

	double mReal;
	double mImaginary;
	double mModulus;
public:
	Complex(double = DEFAULT_REAL, double = DEFAULT_IMAGINARY);
	virtual ~Complex();
	Complex(const Complex &other) = delete;
	Complex& operator=(const Complex &other) = delete;
	double real();
	double imaginary();
	Reference conjugate();
	double modulus();
	static Reference add(Reference, Reference);
	static Reference multiply(Reference, Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace tl */

#endif /* TL_MATH_COMPLEX_H_ */
