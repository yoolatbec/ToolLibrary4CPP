/*
 * LinkedList.h
 *
 *  Created on: Apr 11, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_LINKEDLIST_H_
#define TL_UTILS_LINKEDLIST_H_

#include <tl/utils/List.h>

namespace tl {
namespace utils {

class LinkedList: public virtual List {
private:
	const static type_t CLASS_SERIAL = 1031;

	class LinkedListNode: public virtual Object {
	private:
		const static type_t CLASS_SERIAL = 1032;

		Reference mNext;
		Reference mPrevious;
		Reference mValue;
	public:
		LinkedListNode();
		LinkedListNode(Reference);
		Reference getNext();
		Reference getPrevious();
		Reference getValue();
		void setNext(Reference);
		void setPrevious(Reference);
		void setValue(Reference);
		static type_t type();
		bool instanceof(type_t);
	};

	class LinkedListIterator: virtual public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 1033;

		Reference mLastNode;
		Reference mCurrentNode;

	public:
		LinkedListIterator(type_t, Reference);
		LinkedListIterator(type_t, Reference, tlint);
		LinkedListIterator(const LinkedListIterator&) = delete;
		LinkedListIterator& operator=(const LinkedListIterator&) = delete;
		void add(Reference);
		bool hasNext();
		bool hasPrevious();
		Reference next();
		Reference previous();
		void remove();
		void set(Reference);
		static type_t type();
		bool instanceof(type_t);
	};

	friend class LinkedListIterator;

	Reference mHead;
	Reference mTail;
	Reference mCurrentNode;
	tlint mCurrentIndex;

	/*
	 * Move mCurrentNode point to the element whose index is the given index.
	 * Will modify mCurrentIndex and mCurrentNode.
	 */
	void seek0(tlint);
	void forward0();
	void backward0();
	void invalidateIterators();

	/*
	 * Add an object to the list. The index of the newly inserted element
	 * is mCurrentIndex, and thus the newly inserted element is in front
	 * of mCurrentNode. Thus mCurrentIndex increases.
	 */
	void add0(Reference);
	void remove0();
public:
	LinkedList(type_t);
	virtual ~LinkedList();
	LinkedList(const LinkedList &other) = delete;
	LinkedList& operator=(const LinkedList &other) = delete;
	bool add(Reference);
	/*
	 * Insert an object at the given position.
	 * Null is not allowed.
	 * Return true if successfully inserted.
	 */
	bool add(tlint, Reference);
	bool addAll(Reference);
	bool addAll(tlint, Reference);
	bool contains(Reference);
	bool containsAll(Reference);
	Reference get(tlint);
	tlint indexOf(Reference);
	Reference iterator();
	tlint lastIndexOf(Reference);
	Reference listIterator();
	Reference listIterator(tlint);
	/*
	 * Remove the first occurrence of the given object.
	 * Return true if successful delete or false otherwise.
	 */
	bool remove(Reference);
	Reference remove(tlint);
	void removeAll(Reference);
	bool removeLast(Reference);
	Reference set(tlint, Reference);
	Reference subList(tlint, tlint);
	Reference toArray();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_LINKEDLIST_H_ */
