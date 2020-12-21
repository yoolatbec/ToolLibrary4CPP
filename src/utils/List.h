/*
 * List.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_LIST_H_
#define SRC_UTILS_LIST_H_

#include "../lang/Reference.h"
#include "../lang/Comparable.h"
#include "Collection.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {

using tl::lang::Reference;
using tl::lang::Comparable;
using tl::lang::Array;

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
		bool hasPrevious() = 0;
		Reference next() = 0;
		Reference previous() = 0;
		bool insert() = 0;
		bool remove() = 0;
		virtual bool instanceof(type_t);
		static type_t type();
	};

	static const size_t DEFAULT_CAPACITY = 10;
	size_t mCapacity;
	bool mModified;
public:
	explicit List(type_t);
	List(type_t, size_t reserved);
	List(const List&) = delete;
	virtual List& operator=(const List&) = delete;
	virtual ~List();
	virtual bool add(Reference) = 0;
	virtual bool addAll(Reference) = 0;
	virtual bool contains(Reference) = 0;
	virtual bool containsAll(Reference) = 0;
	virtual Reference get(size_t) = 0;
	virtual bool insert(Reference, size_t position) = 0;
	virtual bool insertAll(Reference, size_t) = 0;
	virtual bool remove(size_t) = 0;
	virtual bool remove(Reference) = 0;
	virtual bool removeAll(Reference) = 0;
	virtual void clear() = 0;
	virtual bool set(size_t, Reference) = 0;
	virtual size_t indexOf(Reference) = 0;
	virtual Array* toArray() = 0;
	virtual List* sublist(size_t, size_t) = 0;
	size_t getCapacity();
	type_t elementType();
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LIST_H_ */
