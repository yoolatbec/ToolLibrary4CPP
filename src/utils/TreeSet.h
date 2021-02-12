/*
 * TreeSet.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_TREESET_H_
#define SRC_UTILS_TREESET_H_

#include "Set.h"
#include "TreeMap.h"

namespace tl {
namespace utils {

class TreeSet: public NavigableSet {
private:
	const static type_t CLASS_SERIAL = 510;

	class TreeSetIterator: public SetIterator {
	private:
		const static type_t CLASS_SERIAL = 511;
		Reference mSetElements;
	public:
		TreeSetIterator(Reference);
		Reference next();
		bool hasNext();
		void remove();
		static type_t type();
		bool instanceof(type_t);
	};
	friend class TreeSetIterator;

	Reference mMap;

private:
	bool contains0(Reference);
	void add0(Reference);
	void remove0(Reference);
	void typeCheck(Reference, type_t);
	void typeCheck(type_t, type_t);

public:
	TreeSet(type_t);
	virtual ~TreeSet();
	TreeSet(const TreeSet &other) = delete;
	TreeSet& operator=(const TreeSet &other) = delete;
	bool add(Reference);
	bool addAll(Reference);
	bool contains(Reference);
	bool containsAll(Reference);
	void clear();
	Reference iterator();
	bool remove(Reference);
	bool removeAll(Reference);
	Reference first();
	Reference last();
	Reference ceiling(Reference);
	Reference floor(Reference);
	Reference higher(Reference);
	Reference lower(Reference);
	Reference pollFirst();
	Reference pollLast();
//	Reference subSet(Reference fromElement, bool fromInclusive,
//			Reference toElement, bool toInclusive);
//	Reference subSet(Reference fromElement, Reference toElement);
	Reference toArray();
	bool instanceof(type_t);
	type_t elementType();
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREESET_H_ */
