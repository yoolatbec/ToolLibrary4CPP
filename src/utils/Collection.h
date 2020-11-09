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

class Collection: public virtual Iterable {
	using lang::Reference;
private:
	const static hash_t CLASS_HASH = 10L << 32;
public:
	Collection();
	virtual ~Collection();
	Collection(const Collection &other) = delete;
	Collection& operator=(const Collection &other) = delete;
	virtual bool add(const Reference&) = 0;
	virtual void addAll(const Reference&) = 0;
	virtual bool contains(const Reference&) = 0;
	virtual bool containsAll(const Reference&) = 0;
	virtual bool empty() const = 0;
	virtual Iterator iterator() = 0;
	virtual bool remove(const Reference&) = 0;
	virtual void removeAll(const Reference&) = 0;
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_COLLECTION_H_ */
