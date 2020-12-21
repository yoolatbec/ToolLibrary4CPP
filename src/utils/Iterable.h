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
	const static type_t CLASS_SERIAL = 9;
public:
	Iterable();
	virtual ~Iterable();
	Iterable(const Iterable &other) = delete;
	Iterable& operator=(const Iterator&) = delete;
	virtual Iterator* iterator() = 0;
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ITERABLE_H_ */
