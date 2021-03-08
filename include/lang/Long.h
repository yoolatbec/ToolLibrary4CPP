/*
 * Long.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_LONG_H_
#define INCLUDE_LANG_LONG_H_

#include <lang/Number.h>

namespace tl {
namespace lang {

class Long: public Number {
private:
	const static type_t CLASS_SERIAL = 32;

	const tlint64 mValue;

	hash_t genHashCode(type_t);
	Long(tlint64);
public:
	const static tlint64 MAX_VALUE = 0x7FFFFFFFFFFFFFFF;
	const static tlint64 MIN_VALUE = 0x8000000000000000;
	const static tlint SIZE_IN_BYTES = sizeof(tlint64);
	const static tlint SIZE_IN_BITS = sizeof(tlint64) * 8;

	virtual ~Long();
	Long(const Long &other) = delete;
	Long& operator=(const Long &other) = delete;
	tlint intValue();
	byte byteValue();
	short shortValue();
	tlint64 longValue();
	float floatValue();
	double doubleValue();
	tlint compareTo(Reference);
	Reference toString();
	static Reference toString(tlint64);
	static Reference valueOf(tlint64);
	static Reference valueOf(Reference);
	static tlint64 parseLong(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_LONG_H_ */
