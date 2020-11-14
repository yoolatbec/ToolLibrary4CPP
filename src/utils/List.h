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
#include "Collection.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {

using tl::lang::Reference;
using tl::lang::Comparable;
using tl::lang::Array;

class List: public virtual Collection {
private:
	const static hash_t CLASS_HASH = 12L << 32;
protected:
	static const size_t DEFAULT_CAPACITY = 10;
	size_t mCapacity;
	bool mModified;
public:
	explicit List(hash_t);
	List(hash_t, size_t reserved);
	List(const List&) = delete;
	virtual List& operator=(const List&) = delete;
	virtual ~List();
	virtual bool add(const Reference&) = 0;
	virtual bool addAll(const Reference&) = 0;
	virtual bool contains(const Reference&) = 0;
	virtual bool containsAll(const Reference&) = 0;
	virtual Reference get(size_t) = 0;
	virtual bool insert(const Reference&, size_t position) = 0;
	virtual bool insertAll(const Reference&, size_t) = 0;
	virtual bool remove(size_t) = 0;
	virtual bool remove(const Reference&) = 0;
	virtual bool removeAll(const Reference&) = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual bool replace(const Reference&, size_t) = 0;
	virtual Array* toArray() const = 0;
	size_t getCapacity() const;
	size_t getSize() const;
	hash_t elementType() const;
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LIST_H_ */
