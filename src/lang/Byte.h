/*
 * Byte.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_BYTE_H_
#define SRC_LANG_BYTE_H_

#include "Number.h"

namespace tl {
namespace lang {

class Byte: public virtual Number {
private:
	const static type_t CLASS_SERIAL = 9;

	byte mValue;

	hash_t genHashCode(type_t);
	Byte(byte);
	Byte(Reference);
public:
	const static byte MAX_VALUE = 0x7F;
	const static byte MIN_VALUE = 0x80;
	const static tlint SIZE_IN_BYTES = sizeof(byte);
	const static tlint SIZE_IN_BITS = sizeof(byte) * 8;

	virtual ~Byte();
	Byte(const Byte &other) = delete;
	Byte& operator=(const Byte &other) = delete;
	tlint compareTo(Reference);
	tlint intValue();
	short shortValue();
	byte byteValue();
	tlint64 longValue();
	float floatValue();
	double doubleValue();
	Reference toString();
	Reference valueOf(byte);
	Reference valueOf(Reference);
	static tlint compare(byte, byte);
	static byte parseByte(Reference);
	static type_t type();
	bool instanceof(type_t type);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_BYTE_H_ */
