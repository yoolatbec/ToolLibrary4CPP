/*
 * Long.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_LONG_H_
#define SRC_LANG_LONG_H_

#include "Number.h"

namespace tl {
namespace lang {

class Long: public Number {
public:
	Long();
	virtual ~Long();
	Long(const Long &other) = delete;
	Long& operator=(const Long &other) = delete;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_LONG_H_ */
