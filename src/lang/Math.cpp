/*
 * Math.cpp
 *
 *  Created on: Dec 24, 2020
 *      Author: yoolatbec
 */

#include <math.h>
#include <tl/lang/Math.h>

namespace tl {
namespace lang {

Math::Math() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

type_t Math::type() {
	return CLASS_SERIAL;
}

bool Math::instanceof(type_t type) {
	return CLASS_SERIAL == type || Object::instanceof(type);
}

double Math::abs(double i) {
	return i > 0 ? i : -i;
}

double Math::pow(double base, double exp) {
	return std::pow(base, exp);
}

double Math::sqrt(double input) {
	return std::sqrt(input);
}

double Math::cos(double input) {
	return std::cos(input);
}

double Math::sin(double input) {
	return std::sin(input);
}

double Math::tan(double input) {
	return std::tan(input);
}

double Math::acos(double input) {
	return std::acos(input);
}

double Math::asin(double input) {
	return std::asin(input);
}

double Math::atan(double input) {
	return std::atan(input);
}

double Math::log(double input) {
	return std::log(input);
}

double Math::log2(double input) {
	return std::log2(input);
}

double Math::log10(double input) {
	return std::log10(input);
}

double Math::floor(double input) {
	return std::floor(input);
}

double Math::ceil(double input) {
	return std::ceil(input);
}

double Math::greater(double a, double b) {
	return a > b ? a : b;
}

double Math::less(double a, double b) {
	return a > b ? b : a;
}

double Math::exp(double input) {
	return std::exp(input);
}

} /* namespace lang */
} /* namespace tl */
