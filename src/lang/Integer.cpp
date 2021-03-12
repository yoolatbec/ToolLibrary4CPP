/*
 * Integer.cpp
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/IllegalArgumentTypeException.h>
#include <tl/lang/Integer.h>
#include <tl/lang/String.h>
#include <cstdio>

namespace tl {
namespace lang {

Integer::Integer(tlint value)
	: mValue(value) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

byte Integer::byteValue() {
	return (byte)mValue;
}

short Integer::shortValue() {
	return (short)mValue;
}

tlint Integer::intValue() {
	return mValue;
}

tlint64 Integer::longValue() {
	return (tlint64)mValue;
}

double Integer::doubleValue() {
	return (double)mValue;
}

float Integer::floatValue() {
	return (float)mValue;
}

tlint Integer::compareTo(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Integer::type());

	Integer* i = dynamic_cast<Integer*>(ref.getEntity());

	return mValue - i->intValue();
}

tlint Integer::getBitAt(tlint position) {
	position %= 32;

	tlint bits = mValue;
	bits = bits << position;
	bits = bits >> 31;

	return bits;
}

tlint Integer::larger(tlint a, tlint b) {
	return a > b ? a : b;
}

tlint Integer::smaller(tlint a, tlint b) {
	return a > b ? b : a;
}

Reference Integer::valueOf(tlint value){
	return Reference(new Integer(value));
}

Reference Integer::valueOf(Reference ref){
	return Reference(new Integer(parseInt(ref)));
}

tlint Integer::parseInt(Reference ref) {
	if(ref.isNull()){
		return 0;
	}

	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		const char *s = str->toCharArray();

		tlint i;
		if (sscanf(s, "%d", &i) == 0) {
			//cast an exception
		}

		return i;
	}

	if (ref.getEntity()->instanceof(Number::type())) {
		Number *num = dynamic_cast<Number*>(ref.getEntity());
		return num->intValue();
	}

	throw IllegalArgumentTypeException();
}

Reference Integer::toString() {
	char str[20];
	sprintf(str, "%d", mValue);
	return Reference(new String(str));
}

bool Integer::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

type_t Integer::type() {
	return CLASS_SERIAL;
}

hash_t Integer::genHashCode(type_t type) {
	return (type << 32) + mValue;
}

} /* namespace lang */
} /* namespace tl */
