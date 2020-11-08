/*
 * ArrayList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_ARRAYLIST_H_
#define SRC_UTILS_ARRAYLIST_H_

#include "List.h"
#include "Iterator.h"

namespace tl {
namespace utils {

class ArrayList: public List {
	using tl::lang::Comparable;
private:
	const static hash_t CLASS_HASH = 13L << 32;
	Reference *mElements;
	class ArrayListIterator : public Iterator{

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
	void addAll(const List*);
	bool insert(const Reference&, size_t position);
	void insertAll(const List*, size_t);
	bool remove(size_t);
	bool remove(const Reference&);
	bool empty() const;
	void clear();
	bool replace(const Reference&, size_t);
	ArrayList* sort(int (*)(Comparable*, Comparable*));
	ArrayList* each(Reference (*)(const Object*));
	void each(void (*)(const Object*));
	Iterator* iterator();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ARRAYLIST_H_ */
