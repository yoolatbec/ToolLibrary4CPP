/*
 * LinkedList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "LinkedList.h"

namespace tl {
namespace utils {

LinkedList::LinkedListNode::LinkedListNode(const Reference& ref){
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

bool LinkedList::add(const Reference& ref){
	if(ref.isNull()){
		return false;
	}

	if(!ref.instanceof(mElementType)){
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->previous = ((LinkedListNode*)tail.getEntity())->previous;

}

bool LinkedList::instanceof(hash_t type) const {
	return (mHash & CLASS_HASH == type) || List::instanceof(type);
}

hash_t LinkedList::getType() {
	return CLASS_HASH;
}

} /* namespace utils */
} /* namespace tl */
