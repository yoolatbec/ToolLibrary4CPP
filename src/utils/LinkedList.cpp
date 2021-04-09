/*
 * LinkedList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include <tl/lang/Array.h>
#include <tl/utils/LinkedList.h>

namespace tl {
namespace utils {

using lang::Array;

LinkedList::LinkedList(type_t type)
	: Collection(type), List(type) {
	// TODO Auto-generated constructor stub
	mHead = Reference(new LinkedListNode(Reference()));
	mTail = Reference(new LinkedListNode(Reference()));
	(dynamic_cast<LinkedListNode*>(mHead.getEntity()))->setNext(mTail);
	(dynamic_cast<LinkedListNode*>(mTail.getEntity()))->setPrevious(mHead);
	mSize = 0;
	mCapacity = mSize;

	mCurrentNode = mHead;
	mCurrentIndex = -1;

	mHashCode = genHashCode(CLASS_SERIAL);
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

void LinkedList::invalidateIterators() {
	if (mIterator.isNull()) {
		return;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
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

		mCurrentIndex++;
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
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	add0(ref);
	return true;
}

bool LinkedList::addFirst(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	invalidateIterators();

	addFirst0(ref);
	return true;
}

bool LinkedList::addLast(Reference ref) {
	return add(ref);
}

bool LinkedList::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add(ref);
	}

	return true;
}

bool LinkedList::addAllLast(Reference ref) {
	return addAll(ref);
}

bool LinkedList::addAllFirst(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	Reference current = mHead;
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		insert(index, value);

		index++;
	}
	return true;
}

bool LinkedList::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);

	return indexOf0(ref) >= 0;
}

bool LinkedList::insert(tlint position, Reference ref) {
	if (position == mSize) {
		return add(ref);
	}

	boundCheck(position);
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

	seek0(position);
	insert0(ref);
	return true;
}

bool LinkedList::insertAll(tlint position, Reference ref) {
	if (position == mSize) {
		return addAll(ref);
	}

	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	boundCheck(position);
	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	if (collection->size() == 0) {
		return false;
	}

	tlint index = 0;
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		insert(position + index, value);
	}

	return true;
}

bool LinkedList::remove(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, mElementType);
	invalidateIterators();

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
	invalidateIterators();

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

	invalidateIterators();

	seek0(mSize);
	moveBackward();
	remove0();

	return true;
}

bool LinkedList::removeAll(Reference ref) {
	if (isEmpty()) {
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	invalidateIterators();

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	bool modified = false;
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		modified = modified || remove(value);
	}

	return modified;
}

void LinkedList::clear() {
	invalidateIterators();

	Reference current =
		dynamic_cast<LinkedListNode*>(mHead.getEntity())->next();
	while (!current.equals(mTail)) {
		remove0();
	}

	mSize = 0;
}

Reference LinkedList::get(tlint position) {
	boundCheck(position);

	seek0(position);
	return dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity())->value();
}

Reference LinkedList::set(tlint position, Reference ref) {
	if (ref.isNull()) {
		return Reference();
	}

	argumentTypeCheck(ref, mElementType);
	boundCheck(position);
	invalidateIterators();

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
	Reference current =
		(dynamic_cast<LinkedListNode*>(mHead.getEntity()))->next();
	for (tlint index = 0; index < mSize; index++) {
		arr->set(index,
			dynamic_cast<LinkedListNode*>(current.getEntity())->value());
	}

	return Reference(arr);
}

void LinkedList::trim() {

}

bool LinkedList::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

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

	argumentTypeCheck(ref, mElementType);

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

	argumentTypeCheck(ref, mElementType);

	LinkedListNode *tail = dynamic_cast<LinkedListNode*>(mTail.getEntity());
	tlint index = mSize - 1;
	Reference current = tail->previous();
	while (!current.equals(mHead)) {
		LinkedListNode *n = dynamic_cast<LinkedListNode*>(current.getEntity());
		if (n->value().equals(ref)) {
			return index;
		}

		index--;
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

	mHashCode = genHashCode(CLASS_SERIAL);
}

void LinkedList::LinkedListNode::setNext(Reference ref) {
	mNext = ref;
}

void LinkedList::LinkedListNode::setPrevious(Reference ref) {
	mPrevious = ref;
}

void LinkedList::LinkedListNode::setValue(Reference ref) {
	mValue = ref;
}

Reference LinkedList::LinkedListNode::next() {
	return mNext;
}

Reference LinkedList::LinkedListNode::previous() {
	return mPrevious;
}

Reference LinkedList::LinkedListNode::value() {
	return mValue;
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
	checkValidation();

	return !(mCurrentNode.isNull());
}

Reference LinkedList::LinkedListIterator::next() {
	checkValidation();

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

tlint LinkedList::LinkedListIterator::nextIndex() {
	return mCursor + 1;
}

bool LinkedList::LinkedListIterator::hasPrevious() {
	checkValidation();

	return !(mCurrentNode.isNull());
}

Reference LinkedList::LinkedListIterator::previous() {
	checkValidation();

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
	checkValidation();

	if (mLastNode.isNull()) {
		//cast an exception
	}

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

void LinkedList::LinkedListIterator::set(Reference ref) {

}

type_t LinkedList::LinkedListIterator::type() {
	return CLASS_SERIAL;
}

bool LinkedList::LinkedListIterator::instanceof(type_t type) {
	return CLASS_SERIAL == type || Iterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
