/*
 * Mat3x3.h
 *
 *  Created on: Feb 15, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT3X3_H_
#define SRC_ADVANCED_MATH_MAT3X3_H_

#include "SquareMatrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat3x3: public virtual SquareMatrix {
public:
	Mat3x3();
	virtual ~Mat3x3();
	Mat3x3(const Mat3x3 &other) = delete;
	Mat3x3& operator=(const Mat3x3 &other) = delete;
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT3X3_H_ */
