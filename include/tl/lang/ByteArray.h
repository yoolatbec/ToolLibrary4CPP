/*
 * ByteArray.h
 *
 *  Created on: Mar 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_BYTEARRAY_H_
#define TL_LANG_BYTEARRAY_H_

#include <tl/lang/NOArray.h>

namespace tl {
namespace lang {

class ByteArray: public virtual NOArray {
	const static type_t CLASS_SERIAL = 30;
	const static byte DEFAULT_VALUE = 0;
	const static tlint DEFAULT_WIDTH_FOR_EACH_ELEMENT = 4;

	byte *mElements;

	ByteArray(tlint, byte);
//	ByteArray(tlint, byte*);
	ByteArray(tlint, byte*, bool);

	static void initParameterCheck(tlint);
public:
	virtual ~ByteArray();
	ByteArray(const ByteArray &other) = delete;
	ByteArray& operator=(const ByteArray &other) = delete;
	static Reference newInstance(tlint = DEFAULT_SIZE, byte = DEFAULT_VALUE);
//	static Reference newInstance(tlint, byte*);
	static Reference newInstance(tlint, byte*, bool);
	Reference toString();
	Reference clone();
	void set(tlint, byte);
	byte get(tlint);
	const byte* rawData();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_BYTEARRAY_H_ */
