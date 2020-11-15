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
	static const hash_t CLASS_HASH = 3L << 32;
	tlint mValue;
	hash_t genHash();
public:
	static const tlint MAX_INTEGER = 0xFFFFFFFF - 1;
	static const tlint MIN_INTEGER = 0xFFFFFFFF;
	explicit Integer(tlint);
	explicit Integer(const Reference&);
	byte byteValue() const;
	word shortValue() const;
	tlint intValue() const;
	tlint64 longValue() const;
	double doubleValue() const;
	float floatValue() const;
	tlint compareTo(const Reference&) const;
	tlint getBitAt(tlint) const;
	String* toString() const;
	static tlint larger(tlint, tlint);
	static tlint smaller(tlint, tlint);
	static hash_t getType();
	virtual bool instanceof(hash_t) const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_INTEGER_H_ */
