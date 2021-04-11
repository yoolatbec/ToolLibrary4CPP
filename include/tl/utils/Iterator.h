/*
 * Iterator.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_ITERATOR_H_
#define TL_UTILS_ITERATOR_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class Iterator: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 1027;

protected:
	Reference mLast;
	Reference mNext;
	bool mValid;

	Iterator();
	void checkValidation();
public:
	virtual ~Iterator();
	Iterator(const Iterator &other) = delete;
	Iterator& operator=(const Iterator &other) = delete;
	virtual bool hasNext();
	virtual Reference next() = 0;
	virtual void remove() = 0;
	bool isValid();
	void invalidate();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_ITERATOR_H_ */
