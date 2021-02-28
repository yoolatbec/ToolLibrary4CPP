/*
 * Math.h
 *
 *  Created on: Dec 24, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_MATH_H_
#define SRC_LANG_MATH_H_

#include "Object.h"

namespace tl {
namespace lang {

class Math:public Object {
private:
	const static type_t CLASS_SERIAL = 556;
	Math();
	Math(const Math &other) = delete;
	Math& operator=(const Math &other) = delete;
	bool instanceof(type_t);
public:
	static double power(double, double);
	static double abs(double);
	static double cos(double);
	static double sin(double);
	static double tan(double);
	static double acos(double);
	static double asin(double);
	static double atan(double);
	static double log(double);
	static double log2(double);
	static type_t type();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_MATH_H_ */
