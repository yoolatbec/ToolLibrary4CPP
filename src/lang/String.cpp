/*
 * String.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <utils/ArrayList.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/NullPointerException.h>
#include <tl/lang/String.h>
#include <tl/lang/IllegalArgumentException.h>
#include <tl/utils/ArrayList.h>
#include <tl/utils/KMPMachine.h>

namespace tl {
namespace lang {

using utils::ArrayList;
using utils::KMPMachine;

Reference String::sBlankString = Reference(new String());

String::String()
	: CharSequence(0) {
	// TODO Auto-generated ructor stub
	mSequence = nullptr;
	mHashCode = genHashCode(CLASS_SERIAL);
}

String::String(const char *str)
	: CharSequence(strlen(str)) {
	mSequence = new char[mLength + 1];
	mSequence[mLength] = '\0';
	strncpy(mSequence, str, mLength);
	mHashCode = genHashCode(CLASS_SERIAL);
}

String::String(tlint length, char c)
	: CharSequence(length) {
	mSequence = new char[mLength + 1];
	mSequence[mLength] = '\0';
	memset(mSequence, c, mLength);
	mHashCode = genHashCode(CLASS_SERIAL);
}

String::String(Reference ref)
	: CharSequence(0) {
	// TODO Auto-generated ructor stub
	if (ref.isNull()) {
		mLength = 0;
		mSequence = nullptr;
	} else {
		argumentTypeCheck(ref, Object::type());

		ref = ref.getEntity()->toString();
		String *str = dynamic_cast<String*>(ref.getEntity());
		mLength = str->length();
		mSequence = new char[mLength + 1];
		strncpy(mSequence, str->toCharArray(), mLength + 1);
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

String::~String() {
	// TODO Auto-generated destructor stub
}

Reference String::append(char c) {
	char *str = new char[mLength + 2];
	strncpy(str, mSequence, mLength);
	str[mLength] = c;
	str[mLength + 1] = '\0';
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::append(Reference ref) {
	if (ref.isNull()) {
		return Reference(new String(mSequence));
	}

	String *r_value;
	String *ref_str =
		dynamic_cast<String*>(ref.getEntity()->toString().getEntity());
	char *str = new char[mLength + ref_str->mLength + 1];
	strncpy(str, mSequence, mLength);
	strncpy(str + mLength, ref_str->toCharArray(), ref_str->mLength);
	str[mLength + ref_str->mLength] = '\0';
	r_value = new String(str);

//	if (ref.instanceof(String::type())) {
//		String *other = dynamic_cast<String*>(ref.getEntity());
//		char *str = new char[mLength + other->mLength + 1];
//		strncpy(str, mSequence, mLength);
//		strncpy(str + mLength, other->mSequence, other->mLength);
//		str[mLength + other->mLength] = '\0';
//		r_value = new String(str);
//		delete[] str;
//	} else {
//		Object *obj = ref.getEntity();
//		Reference str = Reference(obj->toString());
//		r_value = append(str);
//	}

	delete[] str;

	return Reference(r_value);
}

Reference String::append(tlint i) {
//	char ivalue[32];
//	ivalue[31] = '\0';
//	sprintf(ivalue, "%d", i);
//	byte *str = new byte[mLength + strlen(ivalue) + 1];
//	strncpy(str, mSequence, mLength);
//	strncpy(str + mLength, ivalue, strlen(ivalue));
//	str[mLength + strlen(ivalue)] = '\0';
//	String *r_value = new String(str);
//	delete[] str;
//	return Reference(r_value);

	char *str = new char[mLength + 32];
	strncpy(str, mSequence, mLength);
	sprintf(str + mLength, "%d", i);
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);

}

Reference String::append(tlint64 i) {
	char *str = new char[mLength + 32];
	strncpy(str, mSequence, mLength);
	sprintf(str + mLength, "%lld", i);
	String *rtval = new String(str);
	delete[] str;

	return Reference(rtval);
}

Reference String::append(double d) {
//	byte doubleValue[64];
//	doubleValue[63] = '\0';
//	sprintf(doubleValue, "%lf", d);
//	byte *str = new byte[mLength + strlen(doubleValue) + 1];
//	strncpy(str, mSequence, mLength);
//	strncpy(str + mLength, doubleValue, strlen(doubleValue));
//	str[mLength + strlen(doubleValue)] = '\0';
//	String *r_value = new String(str);
//	delete[] str;
//	return Reference(r_value);

	char *str = new char[mLength + 32];
	strncpy(str, mSequence, mLength);
	sprintf(str + mLength, "%g", d);
	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::blank() {
	return sBlankString;
}

tlint String::compareTo(Reference ref) {
	dismissNull(ref);

	argumentTypeCheck(ref, String::type());

	String *str = dynamic_cast<String*>(ref.getEntity());
	return strcmp(mSequence, str->toCharArray());
}

bool String::contains(Reference ref) {
	Reference machine = KMPMachine::newInstance(ref);
	KMPMachine *m = dynamic_cast<KMPMachine*>(machine.getEntity());

	return m->match(Reference(this, false)) != -1;
}

tlint String::indexOf(Reference ref, tlint offset) {
	Reference machine = KMPMachine::newInstance(ref);
	KMPMachine *m = dynamic_cast<KMPMachine*>(machine.getEntity());

	return m->match(Reference(this, false), offset);
}

tlint String::lastIndexOf(Reference ref, tlint offset) {
	Reference machine = KMPMachine::newInstance(ref);
	KMPMachine *m = dynamic_cast<KMPMachine*>(machine.getEntity());

	return m->matchLast(Reference(this, false), offset);
}
//
//Reference String::replace(Reference src, Reference target) {
//
//}

Reference String::replace(char src, char target) {
	char *str = new char[mLength + 1];
	for (tlint index = 0; index < mLength; index++) {
		str[index] = mSequence[index];
		if (str[index] == src) {
			str[index] = target;
		}
	}

	str[mLength] = '\0';

	String *rtval = new String(str);
	delete[] str;

	return Reference(rtval);
}

Reference String::substring(tlint length) {
	if (length <= 0 || length > mLength) {
		throw IllegalArgumentException();
	}

	char *str = new char[length + 1];
	strncpy(str, mSequence, length);
	str[length] = '\0';

	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::substring(tlint start, tlint length) {
	if (start < 0 || start + length >= mLength) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	if (length <= 0) {
		throw IllegalArgumentException();
	}

	char *str = new char[length + 1];
	strncpy(str, mSequence + start, length);
	str[length] = '\0';

	String *r_value = new String(str);
	delete[] str;
	return Reference(r_value);
}

Reference String::split(char b) {
	Reference ref = Reference(new ArrayList(String::type()));
	ArrayList *list = dynamic_cast<ArrayList*>(ref.getEntity());

	char token[2]
		{ 0 };
	token[0] = b;
	char *str = strtok(mSequence, token);
	while (str != nullptr) {
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list->toArray();
}

Reference String::split(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, String::type());

	Reference listRef = Reference(new ArrayList(String::type()));
	ArrayList *list = dynamic_cast<ArrayList*>(listRef.getEntity());

	char *token = dynamic_cast<String*>(ref.getEntity())->mSequence;
	char *str = strtok(mSequence, token);
	while (str != nullptr) {
		list->add(Reference(new String(str)));
		str = strtok(nullptr, token);
	}

	return list->toArray();
}

Reference String::toLowerCase() {
	char *str = new char[mLength + 1];
	for (tlint index = 0; index < mLength; index++) {
		str[index] = tolower(mSequence[index]);
	}

	str[mLength] = '\0';

	String *rtval = new String(str);
	delete[] str;
	return Reference(rtval);
}

Reference String::toUpperCase() {
	char *str = new char[mLength + 1];
	for (tlint index = 0; index < mLength; index++) {
		str[index] = toupper(mSequence[index]);
	}

	str[mLength] = '\0';

	String *rtval = new String(str);
	delete[] str;

	return Reference(rtval);
}

Reference String::toString() {
	return Reference(this, false);
}

bool String::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Comparable::instanceof(type)
		|| CharSequence::instanceof(type);
}

type_t String::type() {
	return CLASS_SERIAL;
}

} /* namespace lang */
} /* namespace tl */
