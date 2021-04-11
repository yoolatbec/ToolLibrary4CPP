/*
 * ArrayList.h
 *
 *  Created on: Apr 10, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_ARRAYLIST_H_
#define TL_UTILS_ARRAYLIST_H_

#include "List.h"

namespace tl {
namespace utils {
/*
 * null-allowed list implementation
 */
class ArrayList: public virtual List {
private:
	const static type_t CLASS_SERIAL = 1029;
	const static tlint DEFAULT_CAPACITY = 10;
	const static constexpr double EXPAND_FACTOR = 1.5;
	const static tlint MAX_CAPACITY;

	class ArrayListIterator: public virtual ListIterator {
	private:
		const static type_t CLASS_SERIAL = 1030;

	public:
		ArrayListIterator(type_t, Reference);
		ArrayListIterator(type_t, Reference, tlint);
		ArrayListIterator& operator=(const ArrayListIterator&) = delete;
		ArrayListIterator(const ArrayListIterator&) = delete;
		~ArrayListIterator();
		/*
		 * Insert an object to the list. The index of the new element
		 * is the index of the last returned element. This will also move
		 * the cursor to the newly inserted element.
		 */
		void add(Reference);
		/*
		 * Return the element the iterator currently points to and move the
		 * iterator forward.
		 */
		Reference next();

		/*
		 * Return the element the iterator currently points to and move the
		 * iterator backward.
		 */
		Reference previous();
		/*
		 * Remove the last returned element.
		 */
		void remove();
		/*
		 * Set the value of the last element returned by previous() or next()
		 * Null is not allowed. This method clears the last index.
		 */
		void set(Reference) = 0;
		static type_t type();
		bool instanceof(type_t);
	};

	Reference mElements;
	tlint mCurrentCapacity;

	void tryExpand();
	bool anyVacancy();

public:
	/*
	 * Create an instance with default capacity
	 */
	ArrayList(type_t elementType);
	/*
	 * Create an instance with given capacity
	 */
	ArrayList(type_t elementType, tlint capacity);
	virtual ~ArrayList();
	ArrayList(const ArrayList &other) = delete;
	ArrayList& operator=(const ArrayList &other) = delete;

	/*
	 * Add an object to the end
	 */
	bool add(Reference);

	/*
	 * Insert an object to the specified position
	 */
	bool add(tlint position, Reference);

	/*
	 * Add all objects to the end
	 */
	bool addAll(Reference);

	/*
	 * Insert all objects to the specified position
	 */
	bool addAll(tlint position, Reference);

	/*
	 * Query whether an object exists in the list
	 */
	bool contains(Reference);

	/*
	 * Query whether all objects exist in the list
	 */
	bool containsAll(Reference);
	void ensureCapacity(tlint);
	Reference get(tlint);

	/*
	 * Return the index of first occurrence of the given object in the list
	 * Return -1 if the object doesn't exist or null is given
	 */
	tlint indexOf(Reference);
	Reference iterator();

	/*
	 * Return the index of last occurrence of the given object
	 * Return -1 if the object doesn't exist or null is given
	 */
	tlint lastIndexOf(Reference);
	Reference listIterator();

	/*
	 * Remove the first occurrence of the given object
	 * Return true if the list changes
	 * Return false when no changes happen or null is given
	 */
	bool remove(Reference);
	Reference remove(tlint);
	void removeAll(Reference);

	/*
	 * Remove the last occurrence of the given object
	 * Return true if the list changes
	 */
	bool removeLast(Reference);
	/*
	 * If null is given, the method is the same as remove(index)
	 */
	void set(tlint, Reference);
	void trim();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_ARRAYLIST_H_ */
