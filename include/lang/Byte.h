/*
 * Byte.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_BYTE_H_
#define INCLUDE_LANG_BYTE_H_

#include <lang/Number.h>

namespace tl {
namespace lang {

class Byte: public virtual Number {
private:
	constexpr const static type_t CLASS_SERIAL = 9;

	const byte mValue;

	hash_t genHashCode(type_t);
	Byte(byte);
public:
	constexpr const static byte MAX_VALUE = 0x7F;
	constexpr const static byte MIN_VALUE = 0x80;
	constexpr const static tlint SIZE_IN_BYTES = sizeof(byte);
	constexpr const static tlint SIZE_IN_BITS = sizeof(byte) * 8;

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

#endif /* INCLUDE_LANG_BYTE_H_ */
