/*
 * IntArray.h
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_INTARRAY_H_
#define SRC_LANG_INTARRAY_H_

#include "NOArray.h"

namespace tl {
namespace lang {

class IntArray: public NOArray {
private:
	static const type_t CLASS_SERIAL = 7;

	tlint* mElements;
public:
	IntArray(tlint, tlint* = nullptr);
	virtual ~IntArray();
	IntArray(const IntArray &other) = delete;
	IntArray& operator=(const IntArray &other) = delete;
	static Reference newIntArray(tlint, tlint* = nullptr);
	tlint get(tlint);
	void set(tlint, tlint);
	Reference clone();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_INTARRAY_H_ */
