/*
 * Iterator.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_ITERATOR_H_
#define INCLUDE_UTILS_ITERATOR_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;
class Iterator: public virtual tl::lang::Object {
private:
	const static type_t CLASS_SERIAL = 156;
	bool mValid;
protected:
	virtual void checkValidation();
	Iterator();
public:
	virtual ~Iterator();
	Iterator(const Iterator &other) = delete;
	Iterator& operator=(const Iterator&) = delete;
	virtual Reference next() = 0;
	virtual bool hasNext() = 0;
	virtual void remove() = 0;
	bool valid();
	void invalidate();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_ITERATOR_H_ */
