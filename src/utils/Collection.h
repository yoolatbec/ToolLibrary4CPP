/*
 * Collection.h
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_COLLECTION_H_
#define SRC_UTILS_COLLECTION_H_

#include "Iterable.h"
#include "../lang/Reference.h"

namespace tl {
namespace utils {

using lang::Reference;

class Collection: public virtual Iterable {
private:
	const static hash_t CLASS_HASH = 10L << 32;
protected:
	const hash_t mElementType;
	size_t mSize;
public:
	explicit Collection(hash_t);
	virtual ~Collection();
	Collection(const Collection &other) = delete;
	Collection& operator=(const Collection &other) = delete;
	virtual bool add(const Reference&) = 0;
	virtual bool addAll(const Reference&) = 0;
	virtual bool contains(const Reference&) const = 0;
	virtual bool containsAll(const Reference&) const = 0;
	virtual bool empty() const = 0;
	virtual Iterator* iterator() = 0;
	virtual bool remove(const Reference&) = 0;
	virtual bool removeAll(const Reference&) = 0;
	size_t size() const;
	virtual bool instanceof(hash_t) const;
	virtual hash_t getElementType() const;
	static hash_t getType();
	bool empty() const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_COLLECTION_H_ */
