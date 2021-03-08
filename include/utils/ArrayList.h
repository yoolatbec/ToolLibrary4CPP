/*
 * ArrayList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_ARRAYLIST_H_
#define INCLUDE_UTILS_ARRAYLIST_H_

#include <lang/Integer.h>

#include <utils/List.h>

namespace tl {
namespace utils {

using lang::Reference;

class ArrayList: virtual public List {
private:
	const static type_t CLASS_SERIAL = 13;
	/*
	 * the array containing elements
	 */
	Reference *mElements;
	Reference mIterator;

	void invalidateIterators();

	class ArrayListIterator: virtual public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 15;

	protected:
		Reference nextElement();
		Reference previousElement();
	public:
		ArrayListIterator(Reference, tlint);
		virtual bool hasNext();
		virtual bool hasPrevious();
		virtual void remove();
		virtual void set(Reference);
		virtual tlint nextIndex();
		virtual tlint previousIndex();
		virtual Reference next();
		virtual Reference previous();
		static type_t type();
		bool instanceof(type_t);
	};

	/*
	 * Increase the capacity of the list to accommodate more elements.
	 * By default the capacity doubles.
	 * Stop expanding when the capacity reaches MAX_CAPACITY. Will cast
	 * SizeOutOfLimitException then.
	 */
	void expand();

	/*
	 * Add the specified object to the end of the list
	 * No type check
	 */
	void add0(Reference);
	void boundCheck(tlint);

	/*
	 * Insert an element to the specific position
	 * No type check
	 */
	void insert0(tlint, Reference);

	/*
	 * Seek for the position where the specified object first occurs.
	 * Seeking from index 0 in increasing order.
	 * No type check
	 * Return -1 if not found.
	 * If null is given, always return -1.
	 */
	tlint indexOf0(Reference);

	/*
	 * Act the same as indexOf0, except that it seeks for the position
	 * where the specified element last occurs.
	 * No type check
	 */
	tlint lastIndexOf0(Reference);
	/*
	 * Remove an element from the list at the specified position
	 * Remove will lead to element movement
	 * No bound check
	 */
	void remove0(tlint);

	/*
	 * Replace the element at the specified position with the given object.
	 * Null is allowed. Setting an element to null won't lead to element movement
	 * Can only modify already existed elements
	 * No type check and bound check
	 */
	Reference set0(tlint, Reference);

public:
	const static tlint MAX_CAPACITY = lang::Integer::MAX_VALUE;
	/*
	 * Create an ArrayList with specified type and default size of 10
	 */
	explicit ArrayList(type_t);

	/*
	 * Create an ArrayList with specified type and specified size
	 */
	ArrayList(type_t, tlint);
	~ArrayList();
	ArrayList(const ArrayList &other) = delete;
	ArrayList& operator=(const ArrayList&) = delete;
	bool add(Reference);
	bool addAll(Reference);

	/*
	 * if null is passed as argument, always return false
	 */
	bool contains(Reference);
	bool containsAll(Reference);

	/*
	 * Increase the capacity when necessary to make sure the list can accommodate
	 * elements of a given count
	 */
	void ensureCapacity(tlint);
	tlint indexOf(Reference);
	tlint lastIndexOf(Reference);
	bool insert(tlint, Reference);
	bool insertAll(tlint, Reference);
	bool remove(tlint);
	bool remove(Reference);
	bool removeLast(Reference);
	bool removeAll(Reference);

	/*
	 * Return an Array which contains the same elements as the list
	 */
	Reference toArray();

	/*
	 * Return a list which contains the elements in the ArrayList with index from
	 * begin to end - 1
	 * Will check whether begin and end are legal: begin and end are greater or equal to 0,
	 * less than mSize and begin is less than end.
	 */
	Reference sublist(tlint begin, tlint end);

	/*
	 * remove all elements in the list and make the capacity to the default capacity
	 */
	void clear();
	/*
	 * bound check
	 */
	Reference get(tlint);
	/*
	 * bound check and type check
	 */
	Reference set(tlint, Reference);

	/*
	 * Reduce the unnecessary capacity to save memory
	 */
	void trim();
	Reference iterator();
	Reference iterator(tlint);
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_ARRAYLIST_H_ */
