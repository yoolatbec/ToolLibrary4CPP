/*
 * KMPMachine.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: yoolatbec
 */

#include <lang/IndexOutOfBoundsException.h>
#include <lang/String.h>
#include <lang/UnacceptableArgumentException.h>
#include <utils/KMPMachine.h>
#include <cstring>

namespace tl {
namespace utils {

using lang::String;
using lang::UnacceptableArgumentException;
using lang::IndexOutOfBoundsException;

KMPMachine::KMPMachine(Reference pattern) {
	// TODO Auto-generated constructor stub
	mPattern = pattern;
	String *str = dynamic_cast<String*>(mPattern.getEntity());
	mLength = str->length();

	generateTable();

	mHashCode = genHashCode(CLASS_SERIAL);
}

void KMPMachine::generateTable() {
	String *str = dynamic_cast<String*>(mPattern.getEntity());

	for (tlint i = 0; i < 256; i++) {
		mTable[i] = new tlint[mLength];
		memset(mTable[i], 0, mLength * sizeof(tlint));
	}

	tlint shadow = 0;

	for (tlint i = 0; i < mLength; i++) {
		for (tlint j = 0; j < 256; j++) {
			mTable[j][i] = mTable[j][shadow];
		}
		mTable[str->charAt(i)][i] = i + 1;

		shadow = mTable[str->charAt(i)][shadow];
	}
}

KMPMachine::~KMPMachine() {
	// TODO Auto-generated destructor stub
	for (tlint i = 0; i < 256; i++) {
		delete[] mTable[i];
	}
}

Reference KMPMachine::newInstance(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, String::type());

	String *str = dynamic_cast<String*>(ref.getEntity());
	if (str->length() == 0) {
		throw UnacceptableArgumentException();
	}

	return Reference(new KMPMachine(ref));
}

Reference KMPMachine::getPattern() {
	return mPattern;
}

tlint KMPMachine::match(Reference ref, tlint offset) {
	dismissNull(ref);
	argumentTypeCheck(ref, String::type());

	if (offset < 0) {
		throw IndexOutOfBoundsException();
	}

	return match0(ref, offset);
}

tlint KMPMachine::match0(Reference ref, tlint offset) {
	String *str = dynamic_cast<String*>(ref.getEntity());

	tlint textLength = str->length();
	if (offset >= mLength) {
		throw IndexOutOfBoundsException();
	}

	tlint current = 0;
	for (tlint i = offset; i < textLength; i++) {
		current = mTable[str->charAt(i)][current];
		if (current == mLength) {
			return i - mLength + 1;
		}
	}

	return -1;
}

tlint KMPMachine::matchLast(Reference ref, tlint offset) {
	dismissNull(ref);
	argumentTypeCheck(ref, String::type());

	if (offset < 0) {
		throw IndexOutOfBoundsException();
	}

	return matchLast0(ref, offset);
}

tlint KMPMachine::matchLast0(Reference ref, tlint offset) {
	String *str = dynamic_cast<String*>(ref.getEntity());
	String *pattern = dynamic_cast<String*>(mPattern.getEntity());

	tlint textLength = str->length();
	if (offset >= textLength) {
		throw IndexOutOfBoundsException();
	}
	tlint patternLength = pattern->length();

	if (patternLength + offset > textLength) {
		return -1;
	}

	tlint current = 0;
	for (tlint i = textLength - patternLength - offset; i >= 0; i--) {
		current = mTable[str->charAt(i)][current];
		if (current == mLength) {
			return i;
		}
	}

	return -1;
}

type_t KMPMachine::type() {
	return CLASS_SERIAL;
}

bool KMPMachine::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
