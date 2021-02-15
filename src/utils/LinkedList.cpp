/*
 * LinkedList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "LinkedList.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {

using lang::Array;

LinkedList::LinkedList(type_t type)
	: Collection(type), List(type) {
	// TODO Auto-generated constructor stub
	mHead = Reference(new LinkedListNode(Reference()));
	mTail = Reference(new LinkedListNode(Reference()));
	((LinkedListNode*) mHead.getEntity())->setNext(mTail);
	((LinkedListNode*) mTail.getEntity())->setPrevious(mHead);
	mSize = 0;
	mCapacity = mSize;

	mCurrentNode = mHead;
	mCurrentIndex = -1;

	mHashCode = genHashCode(CLASS_SERIAL);
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

tlint LinkedList::typeCheck(Reference ref, type_t type) {
	if (ref.isNull()) {
		return 0;
	}

	if (!ref.getEntity()->instanceof(type)) {
		return -1;
	}

	return 1;
}

void LinkedList::boundCheck(tlint position) {
	if (position < 0 || position >= mSize) {
		//cast BoundOutOfLimitException
	}
}

void LinkedList::add0(Reference ref) {
	LinkedListNode *tail = dynamic_cast<LinkedListNode*>(mTail.getEntity());
	Reference oldLast = tail->previous();

	LinkedListNode *newLast = new LinkedListNode(ref);
	Reference newLastRef = Reference(newLast);
	newLast->setPrevious(oldLast);
	newLast->setNext(mTail);
	tail->setPrevious(newLastRef);
	dynamic_cast<LinkedListNode*>(oldLast.getEntity())->setNext(newLastRef);

	mSize++;
	mModified = true;
}

void LinkedList::addFirst0(Reference ref) {
	LinkedListNode *head = dynamic_cast<LinkedListNode*>(mHead.getEntity());
	Reference oldFirst = head->next();

	LinkedListNode *newFirst = new LinkedListNode(ref);
	Reference newFirstRef = Reference(newFirst);
	newFirst->setNext(oldFirst);
	newFirst->setPrevious(mHead);
	head->setNext(newFirstRef);
	dynamic_cast<LinkedListNode*>(oldFirst.getEntity())->setPrevious(
		newFirstRef);

	mSize++;
	mCurrentIndex++;
	mModified = true;
}

void LinkedList::seek0(tlint position) {
	if (mCurrentIndex < position) {
		if (mCurrentIndex < position / 2) {
			mCurrentNode = mHead;
			mCurrentIndex = -1;
		}
	} else if (mCurrentIndex > position) {
		if (mCurrentIndex > (position + mSize - 1) / 2) {
			mCurrentNode = mTail;
			mCurrentIndex = mSize;
		}
	}

	while (mCurrentIndex - position != 0) {
		LinkedListNode *node =
			dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
		if (mCurrentIndex < position) {
			moveForward();
		} else {
			moveBackward();
		}
	}
}

Reference LinkedList::seekNode0(tlint position) {
	Reference currentNode;
	tlint currentPosition;

	if (position < (mSize / 2)) {
		currentNode = mHead;
		currentPosition = -1;
	} else {
		currentNode = mTail;
		currentPosition = mSize;
	}

	while (currentPosition < position) {
		LinkedListNode *node =
			dynamic_cast<LinkedListNode*>(currentNode.getEntity());
		currentNode = node->next();
	}

	while (currentPosition > position) {
		LinkedListNode *node =
			dynamic_cast<LinkedListNode*>(currentNode.getEntity());
		currentNode = node->previous();
	}

	return currentNode;
}

void LinkedList::remove0() {
	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference previousNodeRef = currentNode->previous();
	Reference nextNodeRef = currentNode->next();

	LinkedListNode *previousNode =
		dynamic_cast<LinkedListNode*>(previousNodeRef.getEntity());
	LinkedListNode *nextNode =
		dynamic_cast<LinkedListNode*>(nextNodeRef.getEntity());
	previousNode->setNext(nextNodeRef);
	nextNode->setPrevious(previousNodeRef);

	mCurrentNode = nextNodeRef;
	mSize--;
	mModified = true;
}

void LinkedList::insert0(Reference ref) {
	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference previousNodeRef = currentNode->previous();

	LinkedListNode *newNode = new LinkedListNode(ref);
	Reference newNodeRef = Reference(newNode);

	newNode->setNext(mCurrentNode);
	newNode->setPrevious(previousNodeRef);

	currentNode->setPrevious(newNodeRef);
	dynamic_cast<LinkedListNode*>(previousNodeRef.getEntity())->setNext(
		newNodeRef);

	mCurrentNode = newNodeRef;
	mModified = true;
	mSize++;
}

tlint LinkedList::indexOf0(Reference ref) {
	mCurrentNode = dynamic_cast<LinkedListNode*>(mHead.getEntity())->next();
	mCurrentIndex = 0;

	while (!mCurrentNode.equals(mTail)) {
		LinkedListNode *currentNode =
			dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
		Reference value = currentNode->value();
		if (value.equals(ref)) {
			return mCurrentIndex;
		}

		moveForward();
	}

	return -1;
}

tlint LinkedList::lastIndexOf0(Reference ref) {
	mCurrentNode = dynamic_cast<LinkedListNode*>(mTail.getEntity())->previous();
	mCurrentIndex = mSize - 1;

	while (!mCurrentNode.equals(mHead)) {
		LinkedListNode *currentNode =
			dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
		Reference value = currentNode->value();
		if (value.equals(ref)) {
			return mCurrentIndex;
		}

		moveBackward();
	}

	return -1;
}

void LinkedList::moveForward() {
	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	mCurrentNode = currentNode->next();
	mCurrentIndex++;
}

void LinkedList::moveBackward() {
	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	mCurrentNode = currentNode->previous();
	mCurrentIndex--;
}

Reference LinkedList::get0() {
	return dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity())->value();
}

Reference LinkedList::set0(Reference ref) {
	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference oldValue = currentNode->value();
	if (oldValue.equals(ref)) {
		return ref;
	}

	currentNode->setValue(ref);
	return oldValue;
}

bool LinkedList::add(Reference ref) {
	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	add0(ref);
	return true;
}

bool LinkedList::addFirst(Reference ref) {
	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	addFirst0(ref);
	return true;
}

bool LinkedList::addLast(Reference ref) {
	return add(ref);
}

bool LinkedList::addAll(Reference ref) {
	switch (typeCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		return false;
	}

	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add0(ref);
	}

	return true;
}

bool LinkedList::addAllLast(Reference ref) {
	return addAll(ref);
}

bool LinkedList::addAllFirst(Reference ref) {
	switch (typeCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		return false;
	}

	Reference current = mHead;
	Iterator *iterator = collection->iterator();
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		seek0(index);
		insert0(value);

		index++;
	}
	return true;
}

bool LinkedList::contains(Reference ref) {
	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	return indexOf0(ref) >= 0;
}

bool LinkedList::insert(tlint position, Reference ref) {
	if (position == mSize) {
		return add(ref);
	}

	boundCheck(position);
	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception here
	default:
		//do nothing
	}

	seek0(position);
	insert0(ref);
	return true;
}

bool LinkedList::insertAll(tlint position, Reference ref) {
	if (position == mSize) {
		return addAll(ref);
	}

	switch (typeCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	boundCheck(position);

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		//cast an exception
		return false;
	}

	if (collection->size() == 0) {
		return false;
	}

	tlint index = 0;
	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		seek0(position + index);
		Reference value = iterator->next();
		insert0(value);
	}

	return true;
}

bool LinkedList::remove(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	switch (typeCheck(ref, mElementType)) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	tlint index = indexOf0(ref);
	if (index >= 0) {
		seek0(index);
		remove0();
	}

	return index >= 0;
}

bool LinkedList::remove(tlint position) {
	if (isEmpty()) {
		return false;
	}

	boundCheck(position);

	seek0(position);
	remove0();

	return true;
}

bool LinkedList::removeFirst() {
	return remove(0);
}

bool LinkedList::removeLast() {
	if (isEmpty()) {
		return false;
	}

	seek0(mSize);
	moveBackward();
	remove0();

	return true;
}

bool LinkedList::removeAll(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	switch (typeCheck(ref, Collection::type())) {
	case 0:
		return false;
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->elementType() != mElementType) {
		//cast an exception here
		return false;
	}

	bool modified = false;
	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		tlint index = indexOf0(value);
		if (index >= 0) {
			seek0(index);
			remove0();
			modified = true;
		}
	}

	return modified;
}

void LinkedList::clear() {
	Reference current = ((LinkedListNode*) mHead.getEntity())->mNext;
	while (!current.equals(mTail)) {
		remove0();
	}

	mSize = 0;
	mModified = true;
}

Reference LinkedList::get(tlint position) {
	boundCheck(position);

	seek0(position);
	return dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity())->value();
}

Reference LinkedList::set(tlint position, Reference ref) {
	switch (typeCheck(ref, mElementType)) {
	case -1:
		//cast an exception
	default:
		//do nothing
	}

	boundCheck(position);

	seek0(position);
	return set0(ref);
}

Reference LinkedList::sublist(tlint fromIndex, tlint toIndex) {
	boundCheck(fromIndex);
	boundCheck(toIndex);
	if (fromIndex > toIndex) {
		//cast an exception
	}

	Reference rtval = Reference(new LinkedList(mElementType));
	List *list = dynamic_cast<List*>(rtval.getEntity());

	for (tlint index = fromIndex; index < toIndex; index++) {
		seek0(index);
		list->add(get0());
	}

	return rtval;
}

Reference LinkedList::toArray() {
	Array *arr = new Array(mElementType, mSize);
	Reference current = ((LinkedListNode*) mHead.getEntity())->mNext;
	for (tlint index = 0; index < mSize; index++) {
		arr->set(index,
			dynamic_cast<LinkedListNode*>(current.getEntity())->mValue);
	}

	return Reference(arr);
}

void LinkedList::trim() {

}

bool LinkedList::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
		//cast an exception
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	bool result = true;
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		result = result && contains(e);
		if (!result) {
			break;
		}
	}

	return result;
}

tlint LinkedList::indexOf(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	if (!ref.getEntity()->instanceof(mElementType)) {
		//cast an exception
	}

	LinkedListNode *head = dynamic_cast<LinkedListNode*>(mHead.getEntity());
	tlint index = 0;
	Reference current = head->next();
	while (!current.equals(mTail)) {
		LinkedListNode *n = dynamic_cast<LinkedListNode*>(current.getEntity());
		if (n->value().equals(ref)) {
			return index;
		}

		index++;
		current = n->next();
	}

	return -1;
}

tlint LinkedList::lastIndexOf(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	if (!ref.getEntity()->instanceof(mElementType)) {
		//cast an exception
	}

	LinkedListNode *tail = dynamic_cast<LinkedListNode*>(mTail.getEntity());
	tlint index = mSize - 1;
	Reference current = tail->previous();
	while (!current.equals(mHead)) {
		LinkedListNode *n = dynamic_cast<LinkedListNode*>(current.getEntity());
		if (n->value().equals(ref)) {
			return index;
		}

		index++;
		current = n->previous();
	}

	return -1;
}

Reference LinkedList::iterator() {
	return Reference(new LinkedListIterator(Reference(this, false), 0));
}

bool LinkedList::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || List::instanceof(type);
}

type_t LinkedList::type() {
	return CLASS_SERIAL;
}

LinkedList::LinkedListNode::LinkedListNode(Reference ref) {
	mValue = ref;
	mNext = Reference();
	mPrevious = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

void LinkedList::LinkedListNode::setNext(Reference ref) {
	mNext = ref;
}

void LinkedList::LinkedListNode::setPrevious(Reference ref) {
	mPrevious = ref;
}

Reference LinkedList::LinkedListNode::next() {
	return mNext;
}

Reference LinkedList::LinkedListNode::previous() {
	return mPrevious;
}

type_t LinkedList::LinkedListNode::type() {
	return CLASS_SERIAL;
}

bool LinkedList::LinkedListNode::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

LinkedList::LinkedListIterator::LinkedListIterator(Reference list,
	tlint initCursor)
	: ListIterator(list, initCursor) {

	mLastNode = Reference();
	LinkedList *l = dynamic_cast<LinkedList*>(mList.getEntity());
	mCurrentNode = l->seekNode0(initCursor);

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool LinkedList::LinkedListIterator::hasNext() {
	return !(mCurrentNode.isNull());
}

Reference LinkedList::LinkedListIterator::next() {
	if (mCurrentNode.isNull()) {
		//cast an exception
	}

	Reference current = mCurrentNode;
	LinkedList *list = dynamic_cast<LinkedList*>(mList.getEntity());
	LinkedListNode *node = dynamic_cast<LinkedListNode*>(current.getEntity());
	mLastNode = mCurrentNode;
	if (node->next().equals(list->mTail)) {
		mCurrentNode = Reference();
	} else {
		mCurrentNode = node->next();
	}

	mLastCursor = mCursor;
	mCursor++;
	return node->value();
}

bool LinkedList::LinkedListIterator::hasPrevious() {
	return !(mCurrentNode.isNull());
}

Reference LinkedList::LinkedListIterator::previous() {
	if (mCurrentNode.isNull()) {
		//cast an exception
	}

	LinkedListNode *node =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	LinkedList *list = dynamic_cast<LinkedList*>(mList.getEntity());
	mLastNode = mCurrentNode;
	if (node->previous().equals(list->mHead)) {
		mCurrentNode = Reference();
	} else {
		mCurrentNode = node->previous();
	}

	mLastCursor = mCursor;
	mCursor--;

	return node->value();
}

void LinkedList::LinkedListIterator::remove() {
	if (mLastNode.isNull()) {
		//cast an exception
	}

	List *list = dynamic_cast<List*>(mList.getEntity());
	LinkedListNode *node = dynamic_cast<LinkedListNode*>(mLastNode.getEntity());

	Reference pre = node->previous();
	Reference nxt = node->next();
	LinkedListNode *preNode = dynamic_cast<LinkedListNode*>(pre.getEntity());
	LinkedListNode *nxtNode = dynamic_cast<LinkedListNode*>(nxt.getEntity());
	preNode->setNext(nxt);
	nxtNode->setPrevious(pre);

	mCursor = mLastCursor;
	mLastCursor = -1;
	mLastNode = Reference();
}

type_t LinkedList::LinkedListIterator::type() {
	return CLASS_SERIAL;
}

bool LinkedList::LinkedListIterator::instanceof(type_t type) {
	return CLASS_SERIAL == type || Iterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
