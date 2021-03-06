/*
 * Integer.h
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_INTEGER_H_
#define INCLUDE_LANG_INTEGER_H_

#include <tl/lang/Number.h>

namespace tl {
namespace lang {

class Integer: virtual public Number {
private:
	static const type_t CLASS_SERIAL = 3;
	const tlint mValue;
	hash_t genHashCode(type_t);

	explicit Integer(tlint);
public:
	static const tlint MAX_VALUE = 0x7FFFFFFF;
	static const tlint MIN_VALUE = 0x80000000;
	static const tlint SIZE_IN_BYTES = sizeof(tlint);
	static const tlint SIZE_IN_BITS = sizeof(tlint) * 8;

	byte byteValue();
	short shortValue();
	tlint intValue();
	tlint64 longValue();
	double doubleValue();
	float floatValue();
	tlint compareTo(Reference);
	tlint getBitAt(tlint);
	Reference toString();
	static Reference toString(tlint);
	static Reference valueOf(tlint);
	static Reference valueOf(Reference);
	static tlint larger(tlint, tlint);
	static tlint smaller(tlint, tlint);
	static tlint parseInt(Reference);
	static type_t type();
	virtual bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_INTEGER_H_ */
