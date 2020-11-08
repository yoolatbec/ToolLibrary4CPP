/*
 * ConstIterator.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_CONSTITERATOR_H_
#define SRC_UTILS_CONSTITERATOR_H_

#include "../lang/Reference.h"

namespace tl {
namespace utils {

class ConstIterator : public virtual lang::Object {
	using lang::Reference;
public:
	ConstIterator();
	virtual ~ConstIterator();
	ConstIterator(const ConstIterator &other) = delete;
	ConstIterator& operator=(const ConstIterator&) = delete;
	virtual Reference next() = 0;
	virtual bool hasNext() = 0;

};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_CONSTITERATOR_H_ */
