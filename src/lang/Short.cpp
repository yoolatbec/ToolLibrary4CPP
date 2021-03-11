/*
 * Short.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include <lang/IllegalArgumentTypeException.h>
#include <lang/IndexOutOfBoundsException.h>
#include <lang/Short.h>
#include <lang/String.h>
#include <lang/UnacceptableArgumentException.h>
#include <cstdio>

namespace tl {
namespace lang {

Short::Short(short value)
	: mValue(value) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Short::~Short() {
	// TODO Auto-generated destructor stub
}

tlint Short::intValue() {
	return (tlint)mValue;
}

short Short::shortValue() {
	return mValue;
}

byte Short::byteValue() {
	return (byte)mValue;
}

tlint64 Short::longValue() {
	return (tlint64)mValue;
}

float Short::floatValue() {
	return (float)mValue;
}

double Short::doubleValue() {
	return (double)mValue;
}

Reference Short::valueOf(Reference ref) {
	return valueOf(parseShort(ref));
}

Reference Short::valueOf(short s) {
	return Reference(new Short(s));
}

tlint Short::compareTo(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Short::type());

	Short *s = dynamic_cast<Short*>(ref.getEntity());
	return mValue - s->shortValue();
}

Reference Short::toString(short value) {
	char str[6];
	sprintf(str, "%d", value);
	return Reference(new String(str));
}

Reference Short::toString() {
	char str[6];
	sprintf(str, "%d", mValue);
	return Reference(new String(str));
}

short Short::parseShort(Reference ref) {
	if (ref.isNull()) {
		return 0;
	}

	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		const char *s = str->toCharArray();

		tlint i;
		if (sscanf(s, "%d", &i) == 0) {
			//cast an exception
		}

		return (short)i;
	}

	if (ref.getEntity()->instanceof(Number::type())) {
		Number *num = dynamic_cast<Number*>(ref.getEntity());
		return num->shortValue();
	}

	throw IllegalArgumentTypeException();
}

hash_t Short::genHashCode(type_t type) {
	return (type << 32) | mValue;
}

type_t Short::type() {
	return CLASS_SERIAL;
}

bool Short::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
