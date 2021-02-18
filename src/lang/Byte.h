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

class Byte: public Number {
private:
	const static type_t CLASS_SERIAL = 9;

	byte mValue;

	hash_t genHashCode(type_t);
	Byte(byte);
	Byte(Reference);
public:
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
	static type_t type();
	bool instanceof(type_t type);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_BYTE_H_ */
