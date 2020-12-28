/*
 * List.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_LIST_H_
#define SRC_UTILS_LIST_H_

#include "Collection.h"

namespace tl {
namespace utils {

using tl::lang::Reference;

class List: public virtual Collection {
private:
	const static type_t CLASS_SERIAL = 512;
protected:
	class ListIterator: public virtual Iterator {
	private:
		const static type_t CLASS_SERIAL = 157;
	public:
		ListIterator();
		ListIterator& operator=(const ListIterator&) = delete;
		ListIterator(const ListIterator&) = delete;
		bool hasNext() = 0;
		virtual bool hasPrevious() = 0;
		virtual Reference next() = 0;
		virtual Reference previous() = 0;
		virtual bool insert(Reference) = 0;
		void remove() = 0;
		virtual bool instanceof(type_t);
		static type_t type();
	};

	static const size_t DEFAULT_CAPACITY = 10;
	tlint mCapacity;
	bool mModified;
public:
	explicit List(type_t);
	List(type_t, tlint reserved);
	List(const List&) = delete;
	virtual List& operator=(const List&) = delete;
	virtual ~List();
	virtual bool add(Reference) = 0;
	virtual bool addAll(Reference) = 0;
	virtual bool contains(Reference) = 0;
	virtual bool containsAll(Reference) = 0;
	virtual Reference get(tlint) = 0;
	virtual bool insert(Reference, tlint position) = 0;
	virtual bool insertAll(Reference, tlint) = 0;
	virtual bool remove(tlint) = 0;
	virtual bool remove(Reference) = 0;
	virtual bool removeAll(Reference) = 0;
	virtual void clear() = 0;
	virtual bool set(tlint, Reference) = 0;
	virtual tlint indexOf(Reference) = 0;
	virtual Reference toArray() = 0;
	virtual Reference sublist(tlint, tlint) = 0;
	size_t getCapacity();
	type_t elementType();
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LIST_H_ */
