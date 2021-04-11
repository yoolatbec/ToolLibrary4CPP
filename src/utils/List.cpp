/*
 * List.cpp
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#include "List.h"
#include <tl/lang/IndexOutOfBoundsException.h>

namespace tl {
namespace utils {

using lang::IndexOutOfBoundsException;

List::List(type_t elementType)
	: Collection(elementType) {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::~List() {
	// TODO Auto-generated destructor stub
}

void List::indexBoundsCheck(tlint index) {
	if (index < 0 || index >= mSize) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}
}

type_t List::type() {
	return CLASS_SERIAL;
}

bool List::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

List::ListIterator::ListIterator(type_t elementType, Reference list) {
	mElementType = elementType;
	mList = list;
	mCurrentIndex = 0;
	mLastIndex = -1;
	mForward = true;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::ListIterator::ListIterator(type_t elementType, Reference list,
	tlint index) {
	mElementType = elementType;
	mList = list;
	mCurrentIndex = 0;
	mLastIndex = -1;
	mForward = true;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool List::ListIterator::hasNext() {
	List *list = dynamic_cast<List*>(mList.getEntity());
	return mCurrentIndex < list->size() - 1;
}

bool List::ListIterator::hasPrevious() {
	return mCurrentIndex > 0;
}

tlint List::ListIterator::currentIndex() {
	return mCurrentIndex;
}

tlint List::ListIterator::previousIndex() {
	return mCurrentIndex - 1;
}

tlint List::ListIterator::nextIndex() {
	return mCurrentIndex + 1;
}

type_t List::ListIterator::type() {
	return CLASS_SERIAL;
}

bool List::ListIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
