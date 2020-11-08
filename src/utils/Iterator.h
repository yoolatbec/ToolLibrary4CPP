/*
 * Iterator.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_ITERATOR_H_
#define SRC_UTILS_ITERATOR_H_

#include "../lang/Reference.h"

namespace tl {
namespace utils {

class Iterator : public virtual tl::lang::Object{
	using lang::Reference;
public:
	Iterator();
	virtual ~Iterator();
	Iterator(const Iterator &other) = delete;
	Iterator& operator=(const Iterator&) = delete;
	virtual Reference next() = 0;
	virtual bool hasNext() const = 0;
	virtual bool remove(Object*) = 0;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ITERATOR_H_ */
