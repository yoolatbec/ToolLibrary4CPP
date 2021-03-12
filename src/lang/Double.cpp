/*
 * Double.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/Double.h>
#include <tl/lang/IllegalArgumentTypeException.h>
#include <tl/lang/String.h>
#include <cstdio>

namespace tl {
namespace lang {

Double::Double(tlint64 value)
	: mValue(value) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Double::~Double() {
	// TODO Auto-generated destructor stub
}

hash_t Double::genHashCode(type_t type) {
	double *tmp = new double;
	*tmp = mValue;

	tlint64 i = *(tlint64*)tmp;
	delete tmp;

	return ((i >> 32) ^ i) | (type << 32);
}

double Double::parseDouble(Reference ref) {
	if(ref.isNull()){
		return 0;
	}

	if (ref.getEntity()->instanceof(String::type())) {
		String *str = dynamic_cast<String*>(ref.getEntity());
		const char *s = str->toCharArray();

		double d;
		if (sscanf(s, "%lf", &d) == 0) {
			//cast an exception
		}

		return d;
	}

	if (ref.getEntity()->instanceof(Number::type())) {
		Number *num = dynamic_cast<Number*>(ref.getEntity());
		return num->doubleValue();
	}

	throw IllegalArgumentTypeException();
}

byte Double::byteValue() {
	return (byte)mValue;
}

short Double::shortValue() {
	return (short)mValue;
}

tlint Double::intValue() {
	return (tlint)mValue;
}

tlint64 Double::longValue() {
	return (tlint64)mValue;
}

float Double::floatValue() {
	return (float)mValue;
}

double Double::doubleValue() {
	return mValue;
}

tlint Double::compareTo(Reference ref){
	dismissNull(ref);
	argumentTypeCheck(ref, Double::type());

	Double* d = dynamic_cast<Double*>(ref.getEntity());
	if(mValue - d->doubleValue() != 0){
		return mValue > d->doubleValue() ? 1 : -1;
	} else {
		return 0;
	}
}

Reference Double::toString() {
	char str[20];
	sprintf(str, "%g", mValue);

	return Reference(new String(str));
}

Reference Double::toString(double d){
	char str[20];
	sprintf(str, "%lf", d);

	return Reference(new String(str));
}

Reference Double::valueOf(tlint64 value) {
	return Reference(new Double(value));
}

Reference Double::valueOf(Reference ref) {
	return Reference(new Double(parseDouble(ref)));
}

type_t Double::type() {
	return CLASS_SERIAL;
}

bool Double::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Number::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
