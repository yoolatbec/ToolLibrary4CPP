/*
 * LinkedList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_LINKEDLIST_H_
#define SRC_UTILS_LINKEDLIST_H_

#include "List.h"

namespace tl {
namespace utils {

using lang::Array;
using lang::Reference;

class LinkedList: virtual public List {
private:
	const static type_t CLASS_SERIAL = 16;
	class LinkedListNode: public Object {
		friend class LinkedList;
	private:
		const static type_t CLASS_SERIAL = 17;
		Reference mPrevious;
		Reference mNext;
		Reference mValue;
	public:
		LinkedListNode(Reference);
		LinkedListNode(const LinkedListNode&) = delete;
		LinkedListNode& operator=(const LinkedListNode&) = delete;
		static type_t type();
		bool instanceof(type_t);
	};

	Reference mHead, mTail;

	class LinkedListIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 18;
		LinkedList* const mList;
		Reference mCurrent;
	public:
		LinkedListIterator(LinkedList*);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();
		bool insert(Reference);
		bool remove();
		static type_t type();
		bool instanceof(type_t);
	};

	class LinkedListReversedIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 19;
		LinkedList* const mList;
		Reference mCurrent;
	public:
		LinkedListReversedIterator(LinkedList*);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();
		bool insert(Reference);
		bool remove();
		bool instanceof(type_t);
		static type_t type();
	};

	friend class LinkedListIterator;
	friend class LinkedListReversedIterator;
public:
	LinkedList(hash_t);
	virtual ~LinkedList();
	LinkedList(const LinkedList &other) = delete;
	LinkedList& operator=(const LinkedList&) = delete;
	bool add(Reference);
	bool addFirst(Reference);
	bool addLast(Reference);
	bool addAll(Reference);
	bool addAllFirst(Reference);
	bool addAllLast(Reference);
	bool contains(Reference);
	bool insert(Reference, size_t);
	bool insertAll(Reference, size_t);
	bool remove(Reference);
	bool removeFirst();
	bool removeLast();
	bool remove(size_t);
	bool removeAll(Reference);
	void clear();
	Array* toArray();
	Reference get(size_t);
	Reference getFirst();
	Reference getLast();
	Iterator* iterator();
	Iterator* reversedIterator();
	bool replace(Reference, size_t);
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LINKEDLIST_H_ */
