/*
 * Number.h
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_NUMBER_H_
#define SRC_LANG_NUMBER_H_

#include "Object.h"

namespace tl {
namespace lang {

class Number: public Object {
private:
	static const hash_t CLASS_HASH = 2L << 32;
public:
	Number();
	virtual ~Number();
	byte byteValue() const = 0;
	word shortValue() const = 0;
	tlint intValue() const = 0;
	tlint64 longValue() const = 0;
	double doubleValue() const = 0;
	float floatValue() const = 0;
	virtual bool instanceof(hash_t type) const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_NUMBER_H_ */
