/*
 * LinkedList.cpp
 *
 *  Created on: Apr 11, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/NoSuchElementException.h>
#include <tl/lang/Array.h>
#include <tl/utils/LinkedList.h>

namespace tl {
namespace utils {

using lang::Array;

LinkedList::LinkedList(type_t elementType)
	: Collection(elementType), List(elementType) {
	// TODO Auto-generated constructor stub
	mHead = Reference(new LinkedListNode());
	mTail = Reference(new LinkedListNode());
	LinkedListNode *head = dynamic_cast<LinkedListNode*>(mHead.getEntity());
	LinkedListNode *tail = dynamic_cast<LinkedListNode*>(mTail.getEntity());

	head->setNext(mTail);
	tail->setPrevious(mHead);

	mCurrentNode = mHead;
	mCurrentIndex = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void LinkedList::seek0(tlint index) {
	if (index == mCurrentIndex) {
		return;
	}

	if (index < mCurrentIndex) {
		if (index < mCurrentIndex / 2) {
			mCurrentNode = mHead;
			mCurrentIndex = -1;
			while (mCurrentIndex < index) {
				forward0();
			}
		} else {
			while (mCurrentIndex > index) {
				backward0();
			}
		}
	} else {
		if (index < (mCurrentIndex + mSize) / 2) {
			while (mCurrentIndex < index) {
				forward0();
			}
		} else {
			mCurrentNode = mTail;
			mCurrentIndex = mSize;
			while (mCurrentIndex > index) {
				backward0();
			}
		}
	}
}

void LinkedList::forward0() {
	LinkedListNode *current =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	mCurrentNode = current->getNext();
	mCurrentIndex++;
}

void LinkedList::backward0() {
	LinkedListNode *current =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	mCurrentNode = current->getPrevious();
	mCurrentIndex--;
}

void LinkedList::add0(Reference ref) {
	LinkedListNode *current =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference newNode = Reference(new LinkedListNode(ref));
	LinkedListNode *node = dynamic_cast<LinkedListNode*>(newNode.getEntity());
	ref = current->getPrevious();
	LinkedListNode *previousNode =
		dynamic_cast<LinkedListNode*>(ref.getEntity());

	node->setNext(mCurrentNode);
	node->setPrevious(ref);
	current->setPrevious(newNode);
	previousNode->setNext(newNode);

	mCurrentIndex++;
	mSize++;
}

void LinkedList::remove0() {
	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference previousNodeRef = currentNode->getPrevious();
	Reference nextNodeRef = currentNode->getNext();

	LinkedListNode *previousNode =
		dynamic_cast<LinkedListNode*>(previousNodeRef.getEntity());
	LinkedListNode *nextNode =
		dynamic_cast<LinkedListNode*>(nextNodeRef.getEntity());

	nextNode->setPrevious(previousNodeRef);
	previousNode->setNext(nextNodeRef);

	mCurrentNode = nextNodeRef;
}

bool LinkedList::add(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, mElementType);

	Reference newNode = Reference(new LinkedListNode(ref));
	LinkedListNode *node = dynamic_cast<LinkedListNode*>(newNode.getEntity());
	LinkedListNode *tail = dynamic_cast<LinkedListNode*>(mTail.getEntity());
	ref = tail->getPrevious();
	LinkedListNode *last = dynamic_cast<LinkedListNode*>(ref.getEntity());

	node->setNext(mTail);
	node->setPrevious(ref);
	tail->setPrevious(newNode);
	last->setNext(newNode);

	mSize++;

	return true;
}

bool LinkedList::add(tlint position, Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, mElementType);
	indexBoundsCheck(position);

	seek0(position);
	add0(ref);

	return true;
}

bool LinkedList::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	ref = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());

	bool flag = false;
	while (iterator->hasNext()) {
		ref = iterator->next();
		if (ref.isNull()) {
			continue;
		}

		flag = flag || add(ref);
	}

	return flag;
}

bool LinkedList::addAll(tlint position, Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	ref = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());

	bool flag = false;
	while (iterator->hasNext()) {
		ref = iterator->next();
		if (ref.isNull()) {
			continue;
		}

		flag = flag || add(position, ref);
		position++;
	}

	return flag;
}

bool LinkedList::contains(Reference ref) {
	return indexOf(ref) != -1;
}

bool LinkedList::containsAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	ref = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());

	bool flag = true;
	while (iterator->hasNext()) {
		ref = iterator->next();
		flag = flag && contains(ref);
		if (!flag) {
			return flag;
		}
	}

	return flag;
}

Reference LinkedList::get(tlint index) {
	indexBoundsCheck(index);

	seek0(index);
	LinkedListNode *node =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	return node->getValue();
}

tlint LinkedList::indexOf(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	argumentTypeCheck(ref, mElementType);

	LinkedListNode *head = dynamic_cast<LinkedListNode*>(mHead.getEntity());
	Reference current = head->getNext();

	tlint index = 0;
	while (!current.equals(mTail)) {
		LinkedListNode *node =
			dynamic_cast<LinkedListNode*>(current.getEntity());
		if (ref.equals(node->getValue())) {
			return index;
		}

		current = node->getNext();
		index++;
	}

	return -1;
}

Reference LinkedList::iterator() {
	return listIterator();
}

tlint LinkedList::lastIndexOf(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	argumentTypeCheck(ref, mElementType);

	LinkedListNode *tail = dynamic_cast<LinkedListNode*>(mHead.getEntity());
	Reference current = tail->getPrevious();

	tlint index = mSize - 1;
	while (!current.equals(mHead)) {
		LinkedListNode *node =
			dynamic_cast<LinkedListNode*>(current.getEntity());
		if (ref.equals(node->getValue())) {
			return index;
		}

		current = node->getPrevious();
		index--;
	}

	return -1;
}

Reference LinkedList::listIterator(tlint index) {
	indexBoundsCheck(index);

	return Reference(
		new LinkedListIterator(mElementType, Reference(this, false), index));
}

Reference LinkedList::listIterator() {
	return Reference(
		new LinkedListIterator(mElementType, Reference(this, false)));
}

bool LinkedList::remove(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, mElementType);

	tlint index = indexOf(ref);
	if (index != -1) {
		seek0(index);
		remove0();
		return true;
	}

	return false;
}

Reference LinkedList::remove(tlint index) {
	indexBoundsCheck(index);

	seek0(index);

	LinkedListNode *current =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference value = current->getValue();
	mCurrentNode = current->getNext();

	Reference p = current->getPrevious();
	LinkedListNode *previousNode = dynamic_cast<LinkedListNode*>(p.getEntity());
	Reference n = current->getNext();
	LinkedListNode *nextNode = dynamic_cast<LinkedListNode*>(n.getEntity());

	previousNode->setNext(n);
	nextNode->setPrevious(p);

	mSize--;

	return value;
}

void LinkedList::removeAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	while (iterator->hasNext()) {
		ref = iterator->next();
		if (ref.isNull()) {
			continue;
		}

		remove(ref);
	}
}

bool LinkedList::removeLast(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, mElementType);

	tlint index = lastIndexOf(ref);
	if (index != -1) {
		remove(index);
		return true;
	}

	return false;
}

Reference LinkedList::set(tlint index, Reference value) {
	if (value.isNull()) {
		return remove(index);
	}

	indexBoundsCheck(index);
	argumentTypeCheck(value, mElementType);

	seek0(index);
	LinkedListNode *node =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference oldValue = node->getValue();
	node->setValue(value);

	return oldValue;
}

Reference LinkedList::subList(tlint fromIndex, tlint toIndex) {
	indexBoundsCheck(fromIndex);
	indexBoundsCheck(toIndex);

	if (fromIndex >= toIndex) {
		return Reference();
	}

	Reference newList = Reference(new LinkedList(mElementType));
	LinkedList *list = dynamic_cast<LinkedList*>(newList.getEntity());

	for (tlint index = fromIndex; index < toIndex; index++) {
		seek0(index);
		list->add(mCurrentNode);
	}

	return newList;

}

Reference LinkedList::toArray() {
	Reference array = Reference(new Array(mElementType, mSize));
	Array *arr = dynamic_cast<Array*>(array.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	tlint index = 0;
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		arr->set(index, ref);
		index++;
	}

	return array;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

type_t LinkedList::type() {
	return CLASS_SERIAL;
}

bool LinkedList::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || List::instanceof(type);
}

LinkedList::LinkedListNode::LinkedListNode() {
	mHashCode = genHashCode(CLASS_SERIAL);
}

LinkedList::LinkedListNode::LinkedListNode(Reference value) {
	mValue = value;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference LinkedList::LinkedListNode::getNext() {
	return mNext;
}

Reference LinkedList::LinkedListNode::getPrevious() {
	return mPrevious;
}

Reference LinkedList::LinkedListNode::getValue() {
	return mValue;
}

void LinkedList::LinkedListNode::setNext(Reference next) {
	mNext = next;
}

void LinkedList::LinkedListNode::setPrevious(Reference pre) {
	mPrevious = pre;
}

void LinkedList::LinkedListNode::setValue(Reference value) {
	mValue = value;
}

type_t LinkedList::LinkedListNode::type() {
	return CLASS_SERIAL;
}

bool LinkedList::LinkedListNode::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

LinkedList::LinkedListIterator::LinkedListIterator(type_t elementType,
	Reference list)
	: ListIterator(elementType, list) {
	LinkedList *linkedList = dynamic_cast<LinkedList*>(mList.getEntity());
	mCurrentNode = linkedList->mHead;
	LinkedListNode *node =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	mCurrentNode = node->getNext();

	mHashCode = genHashCode(CLASS_SERIAL);
}

LinkedList::LinkedListIterator::LinkedListIterator(type_t elementType,
	Reference list, tlint initIndex)
	: ListIterator(elementType, list) {
	LinkedList *linkedList = dynamic_cast<LinkedList*>(mList.getEntity());
	mCurrentNode = linkedList->mHead;
	LinkedListNode *node =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	mCurrentNode = node->getNext();

	for (tlint index = 0; index < initIndex; index++) {
		LinkedListNode *current =
			dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
		mCurrentNode = current->getNext();
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

void LinkedList::LinkedListIterator::add(Reference value) {
	checkValidation();

	dismissNull(value);
	argumentTypeCheck(value, mElementType);

	if (mLastNode.isNull()) {
		//cast an exception
		throw NoSuchElementException();
	}

	LinkedList *list = dynamic_cast<LinkedList*>(mList.getEntity());
	LinkedListNode *lastNode =
		dynamic_cast<LinkedListNode*>(mLastNode.getEntity());
	Reference oldPrevious = lastNode->getPrevious();
	LinkedListNode *previousNode =
		dynamic_cast<LinkedListNode*>(oldPrevious.getEntity());

	Reference newNode = Reference(new LinkedListNode(value));
	LinkedListNode *node = dynamic_cast<LinkedListNode*>(newNode.getEntity());
	node->setNext(mLastNode);
	node->setPrevious(oldPrevious);

	lastNode->setPrevious(newNode);
	previousNode->setNext(newNode);

	if (list->mCurrentIndex >= mCurrentIndex) {
		list->mCurrentIndex++;
	}

	if (mCurrentIndex > mLastIndex) {
		mCurrentIndex++;
	}
	mLastIndex++;
	list->mSize++;
}

bool LinkedList::LinkedListIterator::hasNext() {
	checkValidation();

	return !mCurrentNode.isNull();
}

bool LinkedList::LinkedListIterator::hasPrevious() {
	checkValidation();

	return !mCurrentNode.isNull();
}

Reference LinkedList::LinkedListIterator::next() {
	checkValidation();

	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference value = currentNode->getValue();

	LinkedList *list = dynamic_cast<LinkedList*>(mList.getEntity());
	mLastNode = mCurrentNode;
	if (currentNode->getNext().equals(list->mTail)) {
		mCurrentNode = Reference();
	} else {
		mCurrentNode = currentNode->getNext();
	}
	mLastIndex = mCurrentIndex;
	mCurrentIndex++;

	return value;
}

Reference LinkedList::LinkedListIterator::previous() {
	checkValidation();

	LinkedListNode *currentNode =
		dynamic_cast<LinkedListNode*>(mCurrentNode.getEntity());
	Reference value = currentNode->getValue();

	LinkedList *list = dynamic_cast<LinkedList*>(mList.getEntity());
	mLastNode = mCurrentNode;
	if (currentNode->getPrevious().equals(list->mHead)) {
		mCurrentNode = Reference();
	} else {
		mCurrentNode = currentNode->getPrevious();
	}
	mLastIndex = mCurrentIndex;
	mCurrentIndex--;

	return value;
}

void LinkedList::LinkedListIterator::remove() {
	checkValidation();

	if (mLastNode.isNull()) {
		//cast an exception
		throw NoSuchElementException();
	}

	LinkedList *list = dynamic_cast<LinkedList*>(mList.getEntity());
	list->remove(mLastIndex);

	if (mCurrentIndex > mLastIndex) {
		mCurrentIndex--;
	}

	mLastNode = Reference();
	mLastIndex = -1;
}

void LinkedList::LinkedListIterator::set(Reference value) {
	checkValidation();

	dismissNull(value);
	argumentTypeCheck(value, mElementType);

	if (mLastNode.isNull()) {
		//cast an exception
		throw NoSuchElementException();
	}

	LinkedListNode *node = dynamic_cast<LinkedListNode*>(mLastNode.getEntity());
	node->setValue(value);
}

type_t LinkedList::LinkedListIterator::type() {
	return CLASS_SERIAL;
}

bool LinkedList::LinkedListIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || ListIterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
