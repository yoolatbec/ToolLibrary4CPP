/*
 * IntArray.h
 *
 *  Created on: Jan 15, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_INTARRAY_H_
#define INCLUDE_LANG_INTARRAY_H_

#include <tl/lang/NOArray.h>

namespace tl {
namespace lang {

class IntArray: public virtual NOArray {
private:
	static const type_t CLASS_SERIAL = 7;
	static const tlint DEFAULT_VALUE = 0;
	static const tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 12;

	tlint* mElements;

	static void initParameterCheck(tlint);

	IntArray(tlint, tlint*);
	IntArray(tlint, tlint);
public:
	virtual ~IntArray();
	IntArray(const IntArray &other) = delete;
	IntArray& operator=(const IntArray &other) = delete;
	static Reference newInstance(tlint, tlint*);
	static Reference newInstance(tlint = NOArray::DEFAULT_SIZE, tlint = DEFAULT_VALUE);
	tlint get(tlint);
	void set(tlint, tlint);
	Reference clone();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_INTARRAY_H_ */
