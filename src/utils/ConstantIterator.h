/*
 * ConstIterator.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_CONSTANTITERATOR_H_
#define SRC_UTILS_CONSTANTITERATOR_H_

#include "../lang/Reference.h"

namespace tl {
namespace utils {

class ConstantIterator : public virtual lang::Object {
	using lang::Reference;
public:
	ConstantIterator();
	virtual ~ConstantIterator();
	ConstantIterator(const ConstantIterator &other) = delete;
	ConstantIterator& operator=(const ConstantIterator&) = delete;
	virtual Reference next() = 0;
	virtual bool hasNext() = 0;

};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_CONSTANTITERATOR_H_ */
