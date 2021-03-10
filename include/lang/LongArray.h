/*
 * LongArray.h
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#ifndef LANG_LONGARRAY_H_
#define LANG_LONGARRAY_H_

#include <lang/NOArray.h>

namespace tl {
namespace lang {

class LongArray: public virtual NOArray {
private:
	const static type_t CLASS_SERIAL = 122;
	const static tlint64 DEFAULT_VALUE = 0;
	const static tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 30;

	tlint64* mElements;

	LongArray(tlint, tlint64);
	LongArray(tlint, tlint64*);

	static void initParameterCheck(tlint);
public:
	virtual ~LongArray();
	LongArray(const LongArray &other) = delete;
	LongArray& operator=(const LongArray &other) = delete;
	Reference newInstance(tlint = DEFAULT_SIZE, tlint64 = DEFAULT_VALUE);
	Reference newInstance(tlint, tlint64*);
	Reference toString();
	Reference clone();
	void set(tlint, tlint64);
	tlint64 get(tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* LANG_LONGARRAY_H_ */
