/*
 * Byte.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_BYTE_H_
#define SRC_LANG_BYTE_H_

#include "Number.h"

namespace tl {
namespace lang {

class Byte: public Number {
public:
	Byte();
	virtual ~Byte();
	Byte(const Byte &other) = delete;
	Byte& operator=(const Byte &other) = delete;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_BYTE_H_ */
