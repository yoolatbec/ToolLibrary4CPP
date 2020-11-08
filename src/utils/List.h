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
#include "Iterator.h"
#include "ConstIterator.h"

namespace tl {
namespace utils {

class List: public lang::Object {
	using tl::lang::Reference;
	using tl::lang::Comparable;
protected:
	static const size_t DEFAULT_CAPACITY = 10;
	const hash_t mElementType;
	size_t mSize;
	size_t mCapacity;
	bool mModified;
public:
	explicit List(hash_t);
	List(hash_t, size_t reserved);
	List(const List&) = delete;
	virtual List& operator=(const List&) = delete;
	virtual ~List();
	virtual bool add(const Reference&) = 0;
	virtual bool addAll(const List*) = 0;
	virtual bool contains(const Reference&) = 0;
	virtual Reference get(size_t) = 0;
	virtual bool insert(const Reference&, size_t position) = 0;
	virtual bool insertAll(const List*, size_t) = 0;
	virtual bool remove(size_t) = 0;
	virtual bool remove(const Reference&) = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual bool replace(const Reference&, size_t) = 0;
	virtual List* sort(int (*)(Comparable*, Comparable*)) = 0;
	virtual List* each(Reference (*)(const Object*)) = 0;
	virtual void each(void (*)(const Object*)) = 0;
	size_t getCapacity() const;
	size_t getSize() const;
	hash_t elementType() const;
	Iterator* iterator() = 0;
	ConstIterator* constIterator() const = 0;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LIST_H_ */
