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
	static const type_t CLASS_SERIAL = 2;
public:
	Number();
	virtual ~Number();
	virtual byte byteValue() = 0;
	virtual word shortValue() = 0;
	virtual tlint intValue() = 0;
	virtual tlint64 longValue() = 0;
	virtual double doubleValue() = 0;
	virtual float floatValue() = 0;
	virtual Reference toString() = 0;
	virtual bool instanceof(type_t type);
	static type_t type();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_NUMBER_H_ */
