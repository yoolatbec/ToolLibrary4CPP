/*
 * Double.h
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_DOUBLE_H_
#define INCLUDE_LANG_DOUBLE_H_

#include <float.h>
#include <tl/lang/Number.h>

namespace tl {
namespace lang {

class Double: public virtual Number {
private:
	const static type_t CLASS_SERIAL = 33;

	const double mValue;

	Double(tlint64);

	hash_t genHashCode(type_t);
public:
	const static tlint SIZE_IN_BYTES = sizeof(double);
	const static tlint SIZE_IN_BITS = sizeof(double) * 8;
	constexpr const static double MAX_VALUE = (DBL_MAX);
	constexpr const static double MIN_VALUE = (DBL_MIN);

	virtual ~Double();
	Double(const Double &other) = delete;
	Double& operator=(const Double &other) = delete;
	byte byteValue();
	short shortValue();
	tlint intValue();
	tlint64 longValue();
	float floatValue();
	double doubleValue();
	Reference toString();
	tlint compareTo(Reference);
	static Reference toString(double);
	static double parseDouble(Reference);
	static Reference valueOf(tlint64);
	static Reference valueOf(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_DOUBLE_H_ */
