/*
 * ShortArray.h
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_SHORTARRAY_H_
#define TL_LANG_SHORTARRAY_H_

#include <tl/lang/NOArray.h>

namespace tl {
namespace lang {

class ShortArray: public virtual NOArray {
private:
	const static type_t CLASS_SERIAL = 70;
	const static short DEFAULT_VALUE = 0;
	const static tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 5;

	short* mElements;

	ShortArray(tlint, short);
	ShortArray(tlint, short*);

	static void initParameterCheck(tlint);

public:
	virtual ~ShortArray();
	ShortArray(const ShortArray &other) = delete;
	ShortArray& operator=(const ShortArray &other) = delete;
	Reference newInstance(tlint = DEFAULT_SIZE, short = DEFAULT_VALUE);
	Reference newInstance(tlint, short*);
	void set(tlint, short);
	short get(tlint);
	Reference toString();
	Reference clone();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_SHORTARRAY_H_ */
