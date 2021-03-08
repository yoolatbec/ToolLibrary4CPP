/*
 * HashSet.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef INCLUDE_UTILS_HASHSET_H_
#define INCLUDE_UTILS_HASHSET_H_

#include <utils/HashMap.h>

namespace tl {
namespace utils {

using lang::Reference;

class HashSet: public virtual Set {
private:
	const static type_t CLASS_SERIAL = 604;

	Reference mMap;

	Reference mIterator;

	void invalidateIterators();

public:
	HashSet(type_t);
	virtual ~HashSet();
	HashSet(const HashSet &other) = delete;
	HashSet& operator=(const HashSet &other) = delete;
	bool add(Reference);
	bool addAll(Reference);
	bool remove(Reference);
	bool removeAll(Reference);
	bool contains(Reference);
	bool containsAll(Reference);
	void clear();
	Reference iterator();
	Reference toArray();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_HASHSET_H_ */
