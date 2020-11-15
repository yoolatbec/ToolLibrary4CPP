/*
 * Number.h
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_NUMBER_H_
#define SRC_LANG_NUMBER_H_

#include "Comparable.h"

namespace tl {
namespace lang {

class Number: virtual public Comparable {
private:
	static const hash_t CLASS_HASH = 2L << 32;
public:
	Number();
	virtual ~Number();
	virtual byte byteValue() const = 0;
	virtual word shortValue() const = 0;
	virtual tlint intValue() const = 0;
	virtual tlint64 longValue() const = 0;
	virtual double doubleValue() const = 0;
	virtual float floatValue() const = 0;
	virtual bool instanceof(hash_t type) const;
	static hash_t getType();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_NUMBER_H_ */
