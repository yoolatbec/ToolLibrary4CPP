/*
 * Array.h
 *
 *  Created on: Nov 10, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_ARRAY_H_
#define SRC_LANG_ARRAY_H_

#include "Reference.h"
#include "Integer.h"

namespace tl {
namespace lang {

/*
 *
 */
class Array: public Object {
private:
	const static type_t CLASS_SERIAL = 8;
protected:
	const tlint mSize;
	const type_t mElementType;
	Reference* mElements;
public:
	const static tlint MAX_SIZE = Integer::MAX_VALUE;
	Array(type_t, tlint);
	virtual ~Array();
	Array(const Array &other) = delete;
	Array& operator=(const Array &other) = delete;
	Reference get(tlint);
	bool set(tlint, Reference);
	Reference toString();
	tlint size();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_ARRAY_H_ */
