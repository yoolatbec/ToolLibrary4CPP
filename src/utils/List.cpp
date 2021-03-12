/*
 * List.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/utils/List.h>

namespace tl {
namespace utils {

using lang::IndexOutOfBoundsException;

List::List(type_t element_type)
		:Collection(element_type) {
	mCapacity = DEFAULT_CAPACITY;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::List(type_t element_type, tlint reserved)
		:Collection(element_type) {
	mCapacity = reserved > 0 ? reserved : DEFAULT_CAPACITY;

	mHashCode = genHashCode(CLASS_SERIAL);
}

List::~List() {

}

type_t List::elementType() {
	return mElementType;
}

void List::indexBoundCheck(tlint index){
	if(index < 0 || index >= mSize){
		throw IndexOutOfBoundsException();
	}
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
