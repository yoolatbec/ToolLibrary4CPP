/*
 * HashSet.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_HASHSET_H_
#define SRC_UTILS_HASHSET_H_

#include "Set.h"

namespace tl {
namespace utils {

using lang::Array;
using lang::Reference;

class HashSet: public Set {
private:
	const static type_t CLASS_SERIAL = 84;
	const static tlint TABLE_NUM = 5;
	const static tlint MAX_TRANSFER = 9;
	const static tlint INITIAL_CAPACITY[] = {
			8, 13, 21, 34, 55
	};

	class HashEntry: public Entry{
	private:
		const static type_t CLASS_SERIAL = 85;
	public:
		bool mValid;
		HashEntry();
	};

	Reference mTableArray;
	tlint mHashFactor[TABLE_NUM];

	void reHash();
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

#endif /* SRC_UTILS_HASHSET_H_ */
