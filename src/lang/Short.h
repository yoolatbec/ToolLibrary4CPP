/*
 * Short.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_SHORT_H_
#define SRC_LANG_SHORT_H_

#include "Number.h"

namespace tl {
namespace lang {

class Short: public Number {
private:
	const static type_t CLASS_SERIAL = 7;
	short mValue;

	hash_t genHashCode();
	explicit Short(short);
	explicit Short(Reference);

public:
	const static short MAX_VALUE = 0x7FFF;
	const static short MIN_VALUE = 0x8000;
	const static tlint SIZE_IN_BITS = sizeof(short) * 8;
	const static tlint SIZE_IN_BYTES = sizeof(short);

	virtual ~Short();
	Short(const Short &other) = delete;
	Short& operator=(const Short &other) = delete;
	tlint intValue();
	short shortValue();
	byte byteValue();
	tlint64 longValue();
	float floatValue();
	double doubleValue();
	tlint getBitAt(tlint);
	tlint compareTo(Reference);
	static Reference valueOf(Reference);
	static Reference valueOf(short);
	static tluint toUnsignedInt(short);
	static tluint64 toUnsignedLong(short);
	Reference toString();
	static Reference toString(short);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_SHORT_H_ */
