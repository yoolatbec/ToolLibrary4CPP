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
	const static hash_t CLASS_HASH = 13L << 32;
	Reference *mElements;

	class ArrayListIterator : public Iterator{
	private:
		const static hash_t CLASS_HASH = 14L << 32;
		ArrayList* const mList;
		size_t mCurrent;
	public:
		ArrayListIterator(ArrayList*);
		static hash_t getType();
		bool instanceof(hash_t) const;
		bool hasNext() const;
		Reference next();
		bool remove();
		bool insert(const Reference&);
	};

	friend class ArrayListIterator;

	void expand();
public:
	explicit ArrayList(hash_t);
	ArrayList(hash_t, size_t);
	~ArrayList();
	ArrayList(const ArrayList &other) = delete;
	ArrayList& operator=(const ArrayList&) = delete;
	bool add(const Reference&);
	bool addAll(const Reference&);
	bool contains(const Reference&) const;
	bool containsAll(const Reference&) const;
	bool insert(const Reference&, size_t position);
	bool insertAll(const Reference&, size_t);
	bool remove(size_t);
	bool remove(const Reference&);
	bool removeAll(const Reference&);
	Array* toArray() const;
	void clear();
	Reference get(size_t);
	bool replace(const Reference&, size_t);
	Iterator* iterator();
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ARRAYLIST_H_ */
