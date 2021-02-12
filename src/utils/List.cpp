/*
 * List.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include "List.h"

namespace tl {
namespace utils {

List::List(type_t element_type)
		:Collection(element_type) {
	mCapacity = DEFAULT_CAPACITY;
	mModified = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::List(type_t element_type, tlint reserved)
		:Collection(element_type) {
	mCapacity = reserved > 0 ? reserved : DEFAULT_CAPACITY;
	mModified = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::~List() {

}

type_t List::elementType() {
	return mElementType;
}

bool List::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

type_t List::type(){
	return CLASS_SERIAL;
}

List::ListIterator::ListIterator(Reference list, tlint initCursor){
	mList = list;
	mCursor = initCursor;
	mLastCursor = -1;
}

void List::ListIterator::indexRangeCheck(){
	List* list = dynamic_cast<List*>(mList.getEntity());
	if(mCursor < 0 || mCursor >= list->size()){
		//cast an exception
	}
}

bool List::ListIterator::instanceof(type_t type){
	return CLASS_SERIAL == type || Iterator::instanceof(type);
}

type_t List::ListIterator::type(){
	return CLASS_SERIAL;
}

} /* namespace utils */
} /* namespace tl */
