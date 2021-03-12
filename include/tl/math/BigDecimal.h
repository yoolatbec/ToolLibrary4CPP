/*
 * BigDecimal.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_MATH_BIGDECIMAL_H_
#define TL_MATH_BIGDECIMAL_H_

#include <tl/lang/Number.h>
#include <tl/lang/Reference.h>

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

#endif /* TL_MATH_BIGDECIMAL_H_ */
