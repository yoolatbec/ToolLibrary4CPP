/*
 * LongArray.h
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_LONGARRAY_H_
#define TL_LANG_LONGARRAY_H_

#include <tl/lang/NOArray.h>

namespace tl {
namespace lang {

class LongArray: public virtual NOArray {
private:
	const static type_t CLASS_SERIAL = 122;
	const static tlint64 DEFAULT_VALUE = 0;
	const static tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 30;

	tlint64 *mElements;

	LongArray(tlint, tlint64);
	LongArray(tlint, tlint64*, bool);

	static void initParameterCheck(tlint);
public:
	virtual ~LongArray();
	LongArray(const LongArray &other) = delete;
	LongArray& operator=(const LongArray &other) = delete;
	static Reference newInstance(tlint = DEFAULT_SIZE, tlint64 = DEFAULT_VALUE);
	static Reference newInstance(tlint, tlint64*, bool);
	Reference toString();
	Reference clone();
	void set(tlint, tlint64);
	tlint64 get(tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_LONGARRAY_H_ */
