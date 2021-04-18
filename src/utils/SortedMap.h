/*
 * SortedMap.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_SORTEDMAP_H_
#define UTILS_SORTEDMAP_H_

#include "Map.h"

namespace tl {
namespace utils {

class SortedMap: public virtual Map {
public:
	SortedMap();
	virtual ~SortedMap();
	SortedMap(const SortedMap &other) = delete;
	SortedMap& operator=(const SortedMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_SORTEDMAP_H_ */
