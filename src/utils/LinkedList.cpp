/*
 * LinkedList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "LinkedList.h"

namespace tl {
namespace utils {

LinkedList::LinkedListNode::LinkedListNode(const Reference &ref) {
	previous = Reference(nullptr);
	next = Reference(nullptr);
	value = ref;
}

LinkedList::LinkedList(hash_t type)
		: List(type) {
	// TODO Auto-generated constructor stub
	head = Reference(new LinkedListNode(Reference()));
	tail = Reference(new LinkedListNode(Reference()));
	((LinkedListNode*)head.getEntity())->next = tail;
	((LinkedListNode*)tail.getEntity())->previous = head;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

bool LinkedList::add(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->previous =
			((LinkedListNode*)tail.getEntity())->previous;
	((LinkedListNode*)node.getEntity())->next = tail;
	((LinkedListNode*)tail.getEntity())->previous = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->previous.getEntity()))->next =
			node;

	mModified = true;
	mSize++;
	return true;
}

bool LinkedList::addFirst(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->previous = head;
	((LinkedListNode*)node.getEntity())->next =
			((LinkedListNode*)head.getEntity())->next;
	((LinkedListNode*)head.getEntity())->next = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->next.getEntity()))->previous =
			node;

	mSize++;
	mModified = true;
	return true;
}

bool LinkedList::addLast(const Reference &ref) {
	return add(ref);
}

bool LinkedList::addAll(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add(ref);
	}

	return true;
}

bool LinkedList::addAllLast(const Reference &ref) {
	return addAll(ref);
}

bool LinkedList::addAllFirst(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Reference current = head;
	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference newNode = Reference(new LinkedListNode(iterator->next()));
		((LinkedListNode*)newNode.getEntity())->previous = current;
		((LinkedListNode*)newNode.getEntity())->next =
				((LinkedListNode*)current.getEntity())->next;
		((LinkedListNode*)current.getEntity())->next = newNode;
		((LinkedListNode*)(((LinkedListNode*)newNode.getEntity())->next.getEntity()))->previous =
				newNode;
		current = ((LinkedListNode*)current.getEntity())->next;
	}

	mModified = true;
	mSize += collection->size();
	return true;
}

bool LinkedList::contains(const Reference &ref) const {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference current = ((LinkedListNode*)head.getEntity())->next;
	while (!current.equals(tail)) {
		if (((LinkedListNode*)current.getEntity())->value.equals(ref)) {
			return true;
		}
	}
	return false;
}

bool LinkedList::insert(const Reference &ref, size_t position) {
	if (position < 0 || position > mSize) {
		return false;
	}

	if (position == mSize) {
		return addLast(ref);
	}

	if (position == 0) {
		return addFirst(ref);
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference current = ((LinkedListNode*)head.getEntity())->next;
	size_t index = 0;
	while (index < position - 1) {
		current = ((LinkedListNode*)current.getEntity())->next;
		index++;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->next =
			((LinkedListNode*)current.getEntity())->next;
	((LinkedListNode*)node.getEntity())->previous = current;
	((LinkedListNode*)current.getEntity())->next = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->next.getEntity()))->previous =
			node;

	mSize++;
	mModified = true;
	return true;
}

bool LinkedList::instanceof(hash_t type) const {
	return ((mHash & CLASS_HASH) == type) || List::instanceof(type);
}

hash_t LinkedList::getType() {
	return CLASS_HASH;
}

LinkedList::LinkedListNode::LinkedListNode(const Reference &ref) {
	value = ref;
	next = Reference();
	previous = Reference();
}

} /* namespace utils */
} /* namespace tl */
