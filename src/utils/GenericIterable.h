/*
 * GenericIterable.h
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_GENERICITERABLE_H_
#define SRC_UTILS_GENERICITERABLE_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class GenericIterable: public virtual lang::Object {
public:
	GenericIterable();
	virtual ~GenericIterable();
	GenericIterable(const GenericIterable &other) = delete;
	GenericIterable& operator=(const GenericIterable &other) = delete;

};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_GENERICITERABLE_H_ */
