/*
 * LinkedList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_LINKEDLIST_H_
#define INCLUDE_UTILS_LINKEDLIST_H_

#include <utils/List.h>

namespace tl {
namespace utils {

using lang::Reference;

class LinkedList: virtual public List {
private:
	const static type_t CLASS_SERIAL = 16;
	class LinkedListNode: public virtual Object {
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

	Reference mIterator;

	void invalidateIterators();

	class LinkedListIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 18;
		Reference mCurrentNode;
		Reference mLastNode;
	public:
		LinkedListIterator(Reference, tlint);
		bool hasNext();
		Reference next();
		tlint nextIndex();
		bool hasPrevious();
		tlint previousIndex();
		Reference previous();
		void remove();
		void set(Reference);
		static type_t type();
		bool instanceof(type_t);
	};

	friend class LinkedListIterator;

private:
	void boundCheck(tlint);
	/*
	 * Insert an element at the given position. After the insertion the
	 * node pointer points to the given position. That is, the pointer points
	 * to the newly inserted element.
	 * No bound check and type check.
	 */
	void insert0(Reference);

	/*
	 * Remove the element which the node pointer is pointing to.
	 * After remove, the node pointer points to the next element of the removed element
	 * and therefore the index remains unchanged.
	 * No bound check.
	 */
	void remove0();
	/*
	 * will move the cursor
	 */
	tlint indexOf0(Reference);
	tlint lastIndexOf0(Reference);

	/*
	 * Add an element to the end of the list. Won't change the element node pointer
	 * points to.
	 */
	void add0(Reference);
	/*
	 * Add an element to the front of the list. Won't change the element node pointer
	 * points to, but may change the index of the pointed element.
	 */
	void addFirst0(Reference);

	/*
	 * Make the node pointer point to the next element of the currently pointed element.
	 */
	void moveForward();

	/*
	 * Make the node pointer point to the previous element of the currrently pointed element.
	 */
	void moveBackward();

	/*
	 * Return the value of the currently pointed element.
	 */
	Reference get0();
	/*
	 * Set the value of the currently pointed element and return the old value of the element.
	 * No type check.
	 */
	Reference set0(Reference);

	/*
	 * Point the node pointer to the specified position
	 * Seeking the position mSize will jump to point the pointer to mTail
	 * No bound check
	 */
	void seek0(tlint);

	Reference seekNode0(tlint);

public:
	LinkedList(type_t);
	virtual ~LinkedList();
	LinkedList(const LinkedList &other) = delete;
	LinkedList& operator=(const LinkedList&) = delete;

	/*
	 * Add an element at the end of the list
	 */
	bool add(Reference);

	/*
	 * Add an element at the beginning of the list
	 */
	bool addFirst(Reference);
	/*
	 * Act the same as add(Reference)
	 */
	bool addLast(Reference);
	bool addAll(Reference);
	bool addAllFirst(Reference);
	bool addAllLast(Reference);
	bool contains(Reference);
	bool containsAll(Reference);
	void trim();
	bool insert(tlint, Reference);
	bool insertAll(tlint, Reference);
	/*
	 * won't move the cursor
	 */
	tlint indexOf(Reference);
	tlint lastIndexOf(Reference);
	/*
	 * Remove the first encountered element with the given value when iterating from the
	 * beginning to the end
	 */
	bool remove(Reference);

	/*
	 * Remove the first element of the list, if exists.
	 */
	bool removeFirst();

	/*
	 * Remove the last element of the list, if exists.
	 */
	bool removeLast();
	bool remove(tlint);
	bool removeAll(Reference);
	void clear();
	Reference toArray();
	Reference get(tlint);
	Reference getFirst();
	Reference getLast();
	Reference iterator();

	/*
	 * Return an iterator which iterates elements from the end of the list
	 * to the beginning of the list.
	 */
	Reference set(tlint, Reference);
	Reference sublist(tlint, tlint);
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_LINKEDLIST_H_ */
