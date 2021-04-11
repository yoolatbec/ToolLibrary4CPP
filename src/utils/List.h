/*
 * List.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_LIST_H_
#define UTILS_LIST_H_

#include <tl/utils/Collection.h>
#include <tl/utils/Iterator.h>

namespace tl {
namespace utils {

class List: public virtual Collection {
private:
	const static type_t CLASS_SERIAL = 1026;

protected:
	List(type_t);
	void indexBoundsCheck(tlint);

public:
	class ListIterator: public virtual Iterator {
	private:
		const static type_t CLASS_SERIAL = 1028;

	protected:
		Reference mList;
		type_t mElementType;
		tlint mCurrentIndex;
		tlint mLastIndex;
		bool mForward;

		ListIterator(type_t, Reference);
		ListIterator(type_t, Reference, tlint);
	public:
		ListIterator& operator=(const ListIterator&) = delete;
		ListIterator(const ListIterator&) = delete;
		virtual void add(Reference) = 0;
		virtual tlint currentIndex();
		virtual bool hasPrevious();
		virtual bool hasNext();
		virtual tlint nextIndex();
		virtual Reference previous() = 0;
		virtual tlint previousIndex();
		virtual void set(Reference) = 0;
		static type_t type();
		bool instanceof(type_t);
	};

	virtual ~List();
	List(const List &other) = delete;
	List& operator=(const List &other) = delete;
	virtual bool add(tlint, Reference) = 0;
	virtual bool addAll(tlint, Reference) = 0;
	virtual Reference get(tlint) = 0;
	virtual tlint indexOf(Reference) = 0;
	virtual tlint lastIndexOf(Reference) = 0;
	virtual Reference listIterator() = 0;
	virtual Reference remove(tlint) = 0;
	virtual void removeAll(Reference) = 0;
	virtual bool removeLast(Reference) = 0;
	virtual Reference set(Reference, tlint) = 0;
	virtual Reference subList(tlint, tlint) = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_LIST_H_ */
