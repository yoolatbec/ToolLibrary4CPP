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

class LinkedList: public List {
private:
	const static hash_t CLASS_HASH = 16L << 32;
	class LinkedListNode: public Object {
		friend class LinkedList;
	private:
		const static hash_t CLASS_HASH = 17L << 32;
		Reference previous;
		Reference next;
		Reference value;
	public:
		LinkedListNode(const Reference&);
		LinkedListNode(const LinkedListNode&) = delete;
		LinkedListNode& operator=(const LinkedListNode&) = delete;
		static hash_t getType();
		bool instanceof(hash_t) const;
	};

	Reference head, tail;

	class LinkedListIterator: public Iterator {

	};

	class LinkedListReversedIterator: public Iterator {

	};

	friend class LinkedListNode;
	friend class LinkedListIterator;
	friend class LinkedListReversedIterator;
public:
	LinkedList(hash_t);
	virtual ~LinkedList();
	LinkedList(const LinkedList &other) = delete;
	LinkedList& operator=(const LinkedList&) = delete;
	bool add(const Reference&);
	bool addFirst(const Reference&);
	bool addLast(const Reference&);
	bool addAll(const Reference&);
	bool addAllFirst(const Reference&);
	bool addAllLast(const Reference&);
	bool contains(const Reference&) const;
	bool insert(const Reference&, size_t);
	bool insertAll(const Reference&, size_t);
	bool remove(const Reference&);
	bool removeFirst();
	bool removeLast();
	bool remove(size_t);
	bool removeAll(const Reference&);
	bool empty() const;
	void clear();
	bool replace(const Reference&, size_t);
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LINKEDLIST_H_ */
