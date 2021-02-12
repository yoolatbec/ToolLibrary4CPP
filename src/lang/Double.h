/*
 * Double.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_DOUBLE_H_
#define SRC_LANG_DOUBLE_H_

#include "Number.h"

namespace tl {
namespace lang {

class Double: public Number {
public:
	Double();
	virtual ~Double();
	Double(const Double &other) = delete;
	Double& operator=(const Double &other) = delete;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_DOUBLE_H_ */
