/*
 * Float.cpp
 *
 *  Created on: 3 Feb 2021
 *      Author: yoolatbec
 */

#include <lang/Float.h>
#include <lang/IllegalArgumentTypeException.h>
#include <lang/String.h>
#include <cstdio>

namespace tl {
namespace lang {

Float::Float(float value)
	: mValue(value) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode();
}

Float::~Float() {
	// TODO Auto-generated destructor stub
}

tlint Float::compareTo(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Float::type());

	Float *f = dynamic_cast<Float*>(ref.getEntity());
	if (mValue - f->floatValue() != 0) {
		return mValue > f->floatValue() ? 1 : -1;
	} else {
		return 0;
	}
}

hash_t Float::genHashCode() {
	float *f = new float;
	*f = mValue;
	hash_t h = *((tlint*)f);
	delete f;

	return (CLASS_SERIAL << 32) | h;
}

byte Float::byteValue() {
	return (byte)mValue;
}

short Float::shortValue() {
	return (short)mValue;
}

tlint Float::intValue() {
	return (tlint)mValue;
}

tlint64 Float::longValue() {
	return (tlint64)mValue;
}

float Float::floatValue() {
	return mValue;
}

double Float::doubleValue() {
	return (double)mValue;
}

float Float::parseFloat(Reference ref) {
	if(ref.isNull()){
		return 0;
	}

	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		const char *s = str->toCharArray();

		float f;
		if (sscanf(s, "%f", &f) == 0) {
			//cast an exception
		}

		return f;
	}

	if (ref.getEntity()->instanceof(Number::type())) {
		Number *num = dynamic_cast<Number*>(ref.getEntity());
		return num->floatValue();
	}

	throw IllegalArgumentTypeException();
}

Reference Float::valueOf(float f) {
	return Reference(new Float(f));
}

Reference Float::valueOf(Reference ref) {
	return Reference(new Float(parseFloat(ref)));
}

Reference Float::toString() {
	char str[20];
	sprintf(str, "%g", mValue);

	return Reference(new String(str));
}

Reference Float::toString(float f) {
	char str[20];
	sprintf(str, "%g", f);

	return Reference(new String(str));
}

type_t Float::type() {
	return CLASS_SERIAL;
}

bool Float::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
