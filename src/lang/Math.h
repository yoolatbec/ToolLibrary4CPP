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
	static type_t type();
	bool instanceof(type_t);
public:
	static tlint min(tlint, tlint);
	static tlint max(tlint, tlint);
	static double power(double, double);
	static double abs(double);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_MATH_H_ */
