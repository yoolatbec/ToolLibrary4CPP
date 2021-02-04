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

using lang::Reference;
class Iterator: public virtual tl::lang::Object {
private:
	const static type_t CLASS_SERIAL = 156;
public:
	Iterator();
	virtual ~Iterator();
	Iterator(const Iterator &other) = delete;
	Iterator& operator=(const Iterator&) = delete;
	virtual Reference next() = 0;
	virtual bool hasNext() = 0;
	virtual void remove() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ITERATOR_H_ */
