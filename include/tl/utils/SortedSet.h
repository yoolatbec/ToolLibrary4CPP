/*
 * SortedSet.h
 *
 *  Created on: 29 Jan 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_SORTEDSET_H_
#define INCLUDE_UTILS_SORTEDSET_H_

#include <tl/utils/Set.h>

namespace tl {
namespace utils {

class SortedSet: public virtual Set {
private:
	const static type_t CLASS_SERIAL = 92;
public:
	SortedSet(type_t);
	virtual ~SortedSet();
	SortedSet(const SortedSet &other) = delete;
	SortedSet& operator=(const SortedSet &other) = delete;
	virtual Reference first() = 0;
	virtual Reference last() = 0;
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_SORTEDSET_H_ */
