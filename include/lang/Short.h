/*
 * Short.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_SHORT_H_
#define INCLUDE_LANG_SHORT_H_

#include <lang/Number.h>

namespace tl {
namespace lang {

class Short: public Number {
private:
	const static type_t CLASS_SERIAL = 7;
	const short mValue;

	hash_t genHashCode(type_t);
	explicit Short(short);
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
//	tlint getBitAt(tlint);
	tlint compareTo(Reference);
	static short parseShort(Reference);
	static Reference valueOf(Reference);
	static Reference valueOf(short);
	Reference toString();
	static Reference toString(short);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_SHORT_H_ */
