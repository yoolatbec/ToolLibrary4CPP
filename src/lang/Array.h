/*
 * Array.h
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_ARRAY_H_
#define SRC_LANG_ARRAY_H_

#include "Reference.h"

namespace tl {
namespace lang {

class Array: public Object {
private:
	const static type_t CLASS_SERIAL = 8;
protected:
	const size_t mSize;
	const type_t mElementType;
	Reference* mElements;
public:
	Array(type_t, size_t);
	virtual ~Array();
	Array(const Array &other) = delete;
	Array& operator=(const Array &other) = delete;
	Reference get(size_t);
	bool set(Reference, size_t);
	size_t size();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_ARRAY_H_ */
