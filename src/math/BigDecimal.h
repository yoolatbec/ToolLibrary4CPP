/*
 * BigDecimal.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef MATH_BIGDECIMAL_H_
#define MATH_BIGDECIMAL_H_

#include "../lang/Reference.h"
#include "../lang/Number.h"

namespace tl {
namespace math {

class BigDecimal: public virtual lang::Number {
public:
	BigDecimal();
	virtual ~BigDecimal();
	BigDecimal(const BigDecimal &other) = delete;
	BigDecimal& operator=(const BigDecimal &other) = delete;
};

} /* namespace math */
} /* namespace tl */

#endif /* MATH_BIGDECIMAL_H_ */
