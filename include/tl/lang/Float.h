/*
 * Float.h
 *
 *  Created on: 3 Feb 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_FLOAT_H_
#define INCLUDE_LANG_FLOAT_H_

#include <float.h>
#include <tl/lang/Number.h>

namespace tl {
namespace lang {

class Float: public virtual Number {
private:
	const static type_t CLASS_SERIAL = 5;
	const float mValue;
	hash_t genHashCode();

	explicit Float(float);
public:
	const static tlint SIZE_IN_BYTES = sizeof(float);
	const static tlint SIZE_IN_BITS = sizeof(float) * 8;
	constexpr const static float MAX_VALUE = (FLT_MAX);
	constexpr const static float MIN_VALUE = (FLT_MIN);

	virtual ~Float();
	Float(const Float &other) = delete;
	Float& operator=(const Float &other) = delete;
	tlint compareTo(Reference);
	static Reference valueOf(float);
	static Reference valueOf(Reference);
	tlint64 longValue();
	tlint intValue();
	short shortValue();
	byte byteValue();
	float floatValue();
	double doubleValue();
	Reference toString();
	static Reference toString(float);
	static float parseFloat(Reference);
	static type_t type();
	virtual bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_FLOAT_H_ */
