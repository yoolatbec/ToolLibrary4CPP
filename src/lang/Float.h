/*
 * Float.h
 *
 *  Created on: 3 Feb 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_FLOAT_H_
#define SRC_LANG_FLOAT_H_

#include "Number.h"

namespace tl {
namespace lang {

class Float: public virtual Number {
private:
	const static type_t CLASS_SERIAL = 5;
	float mValue;
	hash_t genHashCode();

	explicit Float(float);
	explicit Float(Reference);
public:
	virtual ~Float();
	Float(const Float &other) = delete;
	Float& operator=(const Float &other) = delete;
	tlint compareTo(Reference);
	static Reference valueOf(float);
	static Reference valueOf(Reference);
	tlint64 longValue();
	tlint intValue()
	short shortValue();
	byte byteValue();
	float floatValue();
	Reference toString();
	double doubleValue();
	virtual bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_FLOAT_H_ */
