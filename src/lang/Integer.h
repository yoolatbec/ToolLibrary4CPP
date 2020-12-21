/*
 * Integer.h
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_INTEGER_H_
#define SRC_LANG_INTEGER_H_

#include "Number.h"
#include "String.h"

namespace tl {
namespace lang {

class Integer: virtual public Number {
private:
	static const type_t CLASS_SERIAL = 3;
	tlint mValue;
	hash_t genHashCode();
public:
	static const tlint MAX_INTEGER = 0xFFFFFFFF - 1;
	static const tlint MIN_INTEGER = 0xFFFFFFFF;
	explicit Integer(tlint);
	explicit Integer(Reference);
	byte byteValue();
	word shortValue();
	tlint intValue();
	tlint64 longValue();
	double doubleValue();
	float floatValue();
	tlint compareTo(Reference);
	tlint getBitAt(tlint);
	String* toString();
	static tlint larger(tlint, tlint);
	static tlint smaller(tlint, tlint);
	static type_t type();
	virtual bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_INTEGER_H_ */
