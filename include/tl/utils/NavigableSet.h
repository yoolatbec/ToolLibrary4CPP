/*
 * NavigableSet.h
 *
 *  Created on: 29 Jan 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_NAVIGABLESET_H_
#define INCLUDE_UTILS_NAVIGABLESET_H_

#include <tl/utils/SortedSet.h>

namespace tl {
namespace utils {

class NavigableSet: public virtual SortedSet {
private:
	const static type_t CLASS_SERIAL = 100;
public:
	NavigableSet(type_t);
	virtual ~NavigableSet();
	NavigableSet(const NavigableSet &other) = delete;
	NavigableSet& operator=(const NavigableSet &other) = delete;
	virtual Reference ceiling(Reference) = 0;
	virtual Reference floor(Reference) = 0;
	virtual Reference higher(Reference) = 0;
	virtual Reference lower(Reference) = 0;
	virtual Reference pollFirst() = 0;
	virtual Reference pollLast() = 0;
	virtual Reference iterator() = 0;
	virtual Reference descendingIterator() = 0;
//	virtual Reference subSet(Reference fromElement, bool fromInclusive,
//			Reference toElement, bool toInclusive) = 0;
//	virtual Reference subSet(Reference fromElement, Reference toElement) = 0;
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_NAVIGABLESET_H_ */
