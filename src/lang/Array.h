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
	const static hash_t CLASS_HASH = 8L << 32;
protected:
	const size_t mSize;
	const hash_t mElementType;
	Reference* mElements;
public:
	Array(size_t, hash_t);
	virtual ~Array();
	Array(const Array &other) = delete;
	Array& operator=(const Array &other) = delete;
	Reference get(size_t) const;
	bool set(const Reference&, size_t);
	size_t size() const;
	static hash_t getType();
	bool instanceof(hash_t) const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_ARRAY_H_ */
