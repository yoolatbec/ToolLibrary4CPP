/*
 * SortedSet.h
 *
 *  Created on: May 2, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_SORTEDSET_H_
#define TL_UTILS_SORTEDSET_H_

#include <tl/utils/Set.h>

namespace tl {
namespace utils {

class SortedSet: public virtual Set {
private:
	const static type_t CLASS_SERIAL = 1046;
protected:
	Reference mComparator;
	Reference mDescendingIterator;

	SortedSet(type_t);
	SortedSet(type_t, Reference);
	virtual void invalidateIterators();
public:
	virtual ~SortedSet();
	SortedSet(const SortedSet &other) = delete;
	SortedSet& operator=(const SortedSet &other) = delete;
	virtual Reference ceiling(Reference) = 0;
	virtual Reference descendingIterator() = 0;
	virtual Reference first() = 0;
	virtual Reference floor(Reference) = 0;
	virtual Reference higher(Reference) = 0;
	virtual Reference last() = 0;
	virtual Reference lower(Reference) = 0;
	virtual Reference pollFirst() = 0;
	virtual Reference pollLast() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_SORTEDSET_H_ */
