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
	class LinkedListNode : public Object{
		friend class LinkedList;
		LinkedListNode* previous;
		LinkedListNode* next;
		Reference value;
	};

	class LinkedListIterator : public Iterator{

	};

	class LinkedListConstantIterator : public ConstantIterator{

	};

	class LinkedListReversedIterator : public Iterator{

	};

	class LinkedListReversedConstantIterator : public ConstantIterator{

	};

	friend class LinkedListNode;
public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList &other) = delete;
	LinkedList& operator=(const LinkedList&) = delete;
	bool add(const Reference&);
	bool addFirst(const Reference&);
	bool addLast(const Reference&);
	void addAll(const List*);
	void addAllFirst(const List*);
	void addAllLast(const List*);
	bool contains(const Reference&) const;
	bool insert(const Reference&);
	bool insertFirst(const Reference&);
	bool insertLast(const Reference&);
	void insertAll(const Reference&);
	void insertAllFirst(const List*);
	void insertAllLast(const List*);
	bool remove(const Reference&);
	bool removeFirst();
	bool removeLast();
	bool remove(size_t);
	bool empty() const;
	void clear();
	bool replace(const Reference&, size_t);
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LINKEDLIST_H_ */
