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
		void setNext(Reference);
		void setPrevious(Reference);
		void setValue(Reference);
		Reference previous();
		Reference next();
		Reference value();
		static type_t type();
		bool instanceof(type_t);
	};

	/*
	 * Record the head node and the tail node for gaining higher performance
	 */
	Reference mHead, mTail;

	/*
	 * Record the last accessed node to optimize the next access or seek.
	 */
	Reference mCurrentNode;
	/*
	 * The index of the last accessed node.
	 */
	tlint mCurrentIndex;

	class LinkedListIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 18;
		LinkedList *const mList;
		Reference mCurrent;
	public:
		LinkedListIterator(LinkedList*);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();
		bool insert(Reference);
		void remove();
		static type_t type();
		bool instanceof(type_t);
	};

	class LinkedListReversedIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 19;
		LinkedList *const mList;
		Reference mCurrent;
	public:
		LinkedListReversedIterator(LinkedList*);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();
		bool insert(Reference);
		void remove();
		bool instanceof(type_t);
		static type_t type();
	};

	friend class LinkedListIterator;
	friend class LinkedListReversedIterator;

private:
	tlint typeCheck(Reference, type_t);
	void boundCheck(tlint);
	void insert0(Reference);
	void remove0();
	tlint indexOf0(Reference);
	tlint lastIndexOf0(Reference);
	void add0(Reference);
	void addFirst0(Reference);
	void moveForward();
	void moveBackward();
	Reference get0();
	Reference set0(Reference);

	/*
	 * Jump to the specified position
	 * No bound check
	 */
	void seek0(tlint);

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
	bool insert(tlint, Reference);
	bool insertAll(tlint, Reference);
	bool remove(Reference);
	bool removeFirst();
	bool removeLast();
	bool remove(tlint);
	bool removeAll(Reference);
	void clear();
	Reference toArray();
	Reference get(tlint);
	Reference getFirst();
	Reference getLast();
	Reference iterator();
	Reference reversedIterator();
	Reference set(tlint, Reference);
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LINKEDLIST_H_ */
