/*
 * BigInteger.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef MATH_BIGINTEGER_H_
#define MATH_BIGINTEGER_H_

#include "../lang/Reference.h"
#include "../lang/Number.h"

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

#endif /* MATH_BIGINTEGER_H_ */
