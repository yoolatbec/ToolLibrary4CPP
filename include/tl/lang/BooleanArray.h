/*
 * BooleanArray.h
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_BOOLEANARRAY_H_
#define TL_LANG_BOOLEANARRAY_H_

#include <tl/lang/NOArray.h>

namespace tl {
namespace lang {

class BooleanArray: public virtual NOArray {
private:
	const static type_t CLASS_SERIAL = 56;
	constexpr const static bool DEFAULT_VALUE = false;
	const static tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 6;

	bool *mElements;
	BooleanArray(tlint, bool);
	BooleanArray(tlint, bool*);

	static void initParameterCheck(tlint);
public:
	virtual ~BooleanArray();
	BooleanArray(const BooleanArray &other) = delete;
	BooleanArray& operator=(const BooleanArray &other) = delete;
	static Reference newInstance(tlint, bool*);
	static Reference newInstance(tlint = NOArray::DEFAULT_SIZE, bool = false);
	bool get(tlint);
	void set(tlint, bool);
	Reference toString();
	Reference clone();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_BOOLEANARRAY_H_ */
