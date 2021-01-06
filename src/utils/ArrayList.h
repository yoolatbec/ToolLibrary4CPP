/*
 * ArrayList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_ARRAYLIST_H_
#define SRC_UTILS_ARRAYLIST_H_

#include "List.h"
#include "../lang/Integer.h"

namespace tl {
namespace utils {

using lang::Reference;

class ArrayList: virtual public List{
private:
	const static type_t CLASS_SERIAL = 13;
	/*
	 * the array containing elements
	 */
	Reference *mElements;

	/*
	 * child class of ListIterator
	 */
	class ArrayListIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 14;
		/*
		 * pointer to the ArrayList instance which it should iterate
		 * Considering changing it to a Reference instance, but this will sacrifice
		 * some performance
		 */
		ArrayList *const mList;
		/*
		 * the index of the current element it points to in the ArrayList
		 */
		tlint mCurrent;
	public:
		ArrayListIterator(ArrayList*);
		static hash_t getType();
		bool instanceof(type_t);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();

		/*
		 * Remove the element currently pointing to.
		 */
		void remove();
		bool insert(Reference);
		static type_t type();
	};

	friend class ArrayListIterator;

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
	 * Check whether the given object is an instance of the class whose
	 * identifier is the given identifier
	 * Return 0 if the given Reference instance refers to null
	 * Return -1 if the given object is not an instance of the given class, 1 otherwise.
	 */
	tlint argumentCheck(Reference, type_t);

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
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ARRAYLIST_H_ */
