/*
 * Math.h
 *
 *  Created on: Dec 24, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_MATH_H_
#define INCLUDE_LANG_MATH_H_

#include <tl/lang/Object.h>

namespace tl {
namespace lang {

class Math: public Object {
private:
	const static type_t CLASS_SERIAL = 556;
	Math();
	Math(const Math &other) = delete;
	Math& operator=(const Math &other) = delete;
	bool instanceof(type_t);
public:
	static double pow(double, double);
	static double abs(double);
	static double cos(double);
	static double sin(double);
	static double tan(double);
	static double acos(double);
	static double asin(double);
	static double atan(double);
	static double log(double);
	static double log2(double);
	static double log10(double);
	static double sqrt(double);
	static double floor(double);
	static double ceil(double);
	static double greater(double, double);
	static double exp(double);
	static double less(double, double);
	static type_t type();
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_MATH_H_ */
