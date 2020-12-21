/*
 * ArrayList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_ARRAYLIST_H_
#define SRC_UTILS_ARRAYLIST_H_

#include "List.h"

namespace tl {
namespace utils {

using lang::Reference;
using lang::Comparable;
using lang::Array;

class ArrayList: virtual public List {
private:
	const static type_t CLASS_SERIAL = 13;
	Reference *mElements;

	class ArrayListIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 14;
		ArrayList *const mList;
		size_t mCurrent;
	public:
		ArrayListIterator(ArrayList*);
		static hash_t getType();
		bool instanceof(type_t);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();
		bool remove();
		bool insert(Reference);
		static type_t type();
	};

	friend class ArrayListIterator;

	void expand();
public:
	explicit ArrayList(type_t);
	ArrayList(type_t, size_t);
	~ArrayList();
	ArrayList(const ArrayList &other) = delete;
	ArrayList& operator=(const ArrayList&) = delete;
	bool add(Reference);
	bool addAll(Reference);
	bool contains(Reference);
	bool containsAll(Reference);
	bool insert(Reference, size_t position);
	bool insertAll(Reference, size_t);
	bool remove(size_t);
	bool remove(Reference);
	bool removeAll(Reference);
	Array* toArray();
	List* sublist(size_t, size_t);
	void clear();
	Reference get(size_t);
	bool set(size_t, Reference);
	Iterator* iterator();
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ARRAYLIST_H_ */
