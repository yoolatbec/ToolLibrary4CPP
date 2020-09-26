/*
 * Pointer.h
 *
 *  Created on: Sep 10, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_MEMORY_POINTER_H_
#define SRC_UTILS_MEMORY_POINTER_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class Pointer: public lang::Object {
public:
	Pointer();
	virtual ~Pointer();
	Pointer(const Pointer &other);
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_MEMORY_POINTER_H_ */
