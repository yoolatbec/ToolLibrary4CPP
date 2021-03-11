/*
 * StringBuilder.cpp
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#include <lang/StringBuilder.h>
#include <lang/String.h>
#include <cstdio>
#include <cstring>
#include <lang/Boolean.h>
#include <lang/Integer.h>
#include <lang/Long.h>
#include <lang/Double.h>
#include <lang/UnacceptableArgumentException.h>

namespace tl {
namespace lang {

StringBuilder::StringBuilder()
	: CharSequence(0) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

StringBuilder::~StringBuilder() {
	// TODO Auto-generated destructor stub
}

void StringBuilder::append(Reference ref) {
	if (ref.isNull()) {
		return;
	}

	Object *obj = dynamic_cast<Object*>(ref.getEntity());
	Reference stringRef = obj->toString();
	String *str = dynamic_cast<String*>(stringRef.getEntity());

	char *newSequence = new char[mLength + str->length() + 1];
	strncpy(newSequence, mSequence, mLength);
	strncpy(newSequence + mLength, str->toCharArray(), str->length());
	newSequence[mLength + str->length()] = '\0';

	mLength = mLength + str->length();

	delete[] mSequence;
	mSequence = newSequence;
}

void StringBuilder::append(bool value) {
	append(Boolean::toString(value));
}

void StringBuilder::append(double value) {
	append(Double::toString(value));
}

void StringBuilder::append(tlint value) {
	append(Integer::toString(value));
}

void StringBuilder::append(tlint64 value) {
	append(Long::toString(value));
}

void StringBuilder::append(char value) {
	char *newSequence = new char[mLength + 2];

	strncpy(newSequence, mSequence, mLength);
	newSequence[mLength] = value;
	mLength++;
	newSequence[mLength] = '\0';

	delete[] mSequence;
	mSequence = newSequence;
}

void StringBuilder::append(const char *str, tlint length) {
	char *newSequence = new char[mLength + length + 1];

	strncpy(newSequence, mSequence, mLength);
	strncpy(newSequence + mLength, str, length);
	newSequence[mLength + length] = '\0';

	delete[] mSequence;
	mSequence = newSequence;
}

void StringBuilder::insert(tlint index, Reference ref) {
	if (index == mLength) {
		append(ref);
		return;
	}

	indexBoundCheck(index);

	Object *obj = dynamic_cast<Object*>(ref.getEntity());
	Reference stringRef = obj->toString();
	String *str = dynamic_cast<String*>(stringRef.getEntity());

	char *newSequence = new char[mLength + str->length() + 1];
	strncpy(newSequence, mSequence, index);
	strncpy(newSequence + index, str->toCharArray(), str->length());
	strncpy(newSequence + index + str->length(), mSequence + index,
		mLength - index);
	newSequence[mLength + str->length()] = '\0';

	delete[] mSequence;
	mLength += str->length();
	mSequence = newSequence;
}

void StringBuilder::insert(tlint index, char value) {
	if (index == mLength) {
		append(value);
		return;
	}

	char *newSequence = new char[mLength + 2];
	strncpy(newSequence, mSequence, index);
	newSequence[index] = value;
	strncpy(newSequence + index + 1, mSequence + index, mLength - index);

	mLength++;
	delete[] mSequence;
	mSequence = newSequence;
}

void StringBuilder::insert(tlint index, tlint value) {
	insert(index, Integer::toString(value));
}

void StringBuilder::insert(tlint index, tlint64 value) {
	insert(index, Long::toString(value));
}

void StringBuilder::insert(tlint index, double value) {
	insert(index, Double::toString(value));
}

void StringBuilder::insert(tlint index, bool value) {
	insert(index, Boolean::toString(value));
}

void StringBuilder::insert(tlint index, const char *str, tlint length) {
	char *newSequence = new char[mLength + length + 1];

	strncpy(newSequence, mSequence, index);
	strncpy(newSequence + index, str, length);
	strncpy(newSequence + index + length, mSequence + index, mLength - index);

	delete[] mSequence;
	mLength += length;
	mSequence = newSequence;
}

void StringBuilder::replace(char src, char dst) {
	for (tlint index = 0; index < mLength; index++) {
		if (mSequence[index] == src) {
			mSequence[index] = dst;
		}
	}
}

void StringBuilder::reverse() {
	char *newSequence = new char[mLength + 1];
	newSequence[mLength] = '\0';

	for (tlint index = 0; index < mLength; index++) {
		newSequence[index] = mSequence[mLength - index - 1];
	}

	delete[] mSequence;
	mSequence = newSequence;
}

void StringBuilder::setCharAt(tlint index, char value) {
	indexBoundCheck(index);
}

Reference StringBuilder::substring(tlint begin, tlint end) {
	indexBoundCheck(begin);
	indexBoundCheck(end - 1);

	if (begin > end) {
		throw UnacceptableArgumentException();
	}

	char *str = new char[end - begin + 1];
	for (tlint index = begin; index < end; index++) {
		str[index - begin] = mSequence[index];
	}

	str[end] = '\0';

	return Reference(new String(str));
}

type_t StringBuilder::type() {
	return CLASS_SERIAL;
}

bool StringBuilder::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || (CharSequence::instanceof(type));
}

} /* namespace lang */
} /* namespace tl */
