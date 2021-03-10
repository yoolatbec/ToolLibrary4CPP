/*
 * ByteArray.h
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#ifndef LANG_BYTEARRAY_H_
#define LANG_BYTEARRAY_H_

#include <lang/NOArray.h>

namespace tl {
namespace lang {

class ByteArray: public virtual NOArray {
	const static type_t CLASS_SERIAL = 30;
	const static byte DEFAULT_VALUE = 0;
	const static tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 4;

	byte *mElements;

	ByteArray(tlint, byte);
	ByteArray(tlint, byte*);

	static void initParameterCheck(tlint);
public:
	virtual ~ByteArray();
	ByteArray(const ByteArray &other) = delete;
	ByteArray& operator=(const ByteArray &other) = delete;
	Reference newInstance(tlint = DEFAULT_SIZE, byte = DEFAULT_VALUE);
	Reference newInstance(tlint, byte*);
	Reference toString();
	Reference clone();
	void set(tlint, byte);
	byte get(tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* LANG_BYTEARRAY_H_ */
