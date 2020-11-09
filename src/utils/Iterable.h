/*
 * Iterable.h
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_ITERABLE_H_
#define SRC_UTILS_ITERABLE_H_

#include "../lang/Object.h"
#include "Iterator.h"

namespace tl {
namespace utils {

class Iterable: public virtual lang::Object {
private:
	const static hash_t CLASS_HASH = 9L << 32;
public:
	Iterable();
	virtual ~Iterable();
	Iterable(const Iterable &other) = delete;
	virtual Iterator iterator() = 0;
	virtual bool instanceof(hash_t) const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ITERABLE_H_ */
