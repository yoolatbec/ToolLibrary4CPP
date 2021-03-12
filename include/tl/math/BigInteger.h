/*
 * BigInteger.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_MATH_BIGINTEGER_H_
#define TL_MATH_BIGINTEGER_H_

#include <tl/lang/Number.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace math {

class BigInteger: public virtual lang::Number {
public:
	BigInteger();
	virtual ~BigInteger();
	BigInteger(const BigInteger &other) = delete;
	BigInteger& operator=(const BigInteger &other) = delete;
};

} /* namespace math */
} /* namespace tl */

#endif /* TL_MATH_BIGINTEGER_H_ */
