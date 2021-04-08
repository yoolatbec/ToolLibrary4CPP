/*
 * List.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_LIST_H_
#define INCLUDE_UTILS_LIST_H_

#include <tl/utils/Collection.h>

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
	protected:
		Reference mList;
		tlint mCursor;
		tlint mLastCursor;

		void indexRangeCheck();
	public:
		ListIterator(Reference, tlint);
		ListIterator& operator=(const ListIterator&) = delete;
		ListIterator(const ListIterator&) = delete;
		bool hasNext() = 0;
		virtual bool hasPrevious() = 0;
		virtual Reference next() = 0;
		virtual tlint nextIndex() = 0;
		virtual Reference previous() = 0;
		virtual tlint previousIndex() = 0;
		virtual void remove() = 0;
		virtual void set(Reference) = 0;
		virtual bool instanceof(type_t);
		static type_t type();
	};

	static const tlint DEFAULT_CAPACITY = 10;
	tlint mCapacity;

	void indexBoundCheck(tlint);
	explicit List(type_t);
public:
	List(type_t, tlint reserved);
	List(const List&) = delete;
	virtual List& operator=(const List&) = delete;
	virtual ~List();
	virtual bool add(Reference) = 0;
	virtual bool addAll(Reference) = 0;
	virtual bool contains(Reference) = 0;
	virtual bool containsAll(Reference) = 0;
	virtual Reference get(tlint) = 0;
	virtual bool insert(tlint, Reference) = 0;
	virtual bool insertAll(tlint, Reference) = 0;
	virtual bool remove(tlint) = 0;
	virtual bool remove(Reference) = 0;
	virtual bool removeAll(Reference) = 0;
	virtual void clear() = 0;
	virtual Reference set(tlint, Reference) = 0;
	virtual tlint indexOf(Reference) = 0;
	virtual Reference toArray() = 0;

	/*
	 * from inclusive, to exclusive
	 */
	virtual Reference sublist(tlint, tlint) = 0;
	virtual void trim() = 0;
	type_t elementType();
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_LIST_H_ */
