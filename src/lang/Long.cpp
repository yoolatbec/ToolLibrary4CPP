/*
 * Long.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/IllegalArgumentTypeException.h>
#include <tl/lang/Long.h>
#include <tl/lang/String.h>
#include <cstdio>

namespace tl {
namespace lang {

Long::Long(tlint64 value)
	: mValue(value) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Long::~Long() {
	// TODO Auto-generated destructor stub
}

hash_t Long::genHashCode(type_t type){
	return ((mValue >> 32) ^ mValue) | (type << 32);
}

tlint Long::intValue() {
	return (tlint)mValue;
}

tlint64 Long::longValue() {
	return mValue;
}

short Long::shortValue() {
	return (short)mValue;
}

byte Long::byteValue() {
	return (byte)mValue;
}

float Long::floatValue() {
	return (float)mValue;
}

double Long::doubleValue() {
	return (double)mValue;
}

tlint Long::compareTo(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Long::type());

	Long *l = dynamic_cast<Long*>(ref.getEntity());

	if (mValue - l->longValue() != 0) {
		return mValue > l->longValue() ? 1 : -1;
	} else {
		return 0;
	}
}

Reference Long::toString() {
	char str[50];
	sprintf(str, "%lld", mValue);

	return Reference(new String(str));
}

Reference Long::toString(tlint64 v) {
	char str[50];
	sprintf(str, "%lld", v);

	return Reference(new String(str));
}

Reference Long::valueOf(tlint64 v) {
	return Reference(new Long(v));
}

Reference Long::valueOf(Reference ref) {
	return valueOf(parseLong(ref));
}

tlint64 Long::parseLong(Reference ref) {
	if(ref.isNull()){
		return 0;
	}

	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		const char *s = str->toCharArray();

		tlint64 i;
		if (sscanf(s, "%lld", &i) == 0) {
			//cast an exception
		}

		return i;
	}

	if (ref.getEntity()->instanceof(Number::type())) {
		Number *num = dynamic_cast<Number*>(ref.getEntity());
		tlint64 i = num->longValue();
		return i;
	}

	throw IllegalArgumentTypeException();
}

type_t Long::type() {
	return CLASS_SERIAL;
}

bool Long::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
