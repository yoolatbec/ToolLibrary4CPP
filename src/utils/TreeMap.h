/*
 * TreeMap.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_TREEMAP_H_
#define UTILS_TREEMAP_H_

#include "SortedMap.h"

namespace tl {
namespace utils {

class TreeMap: public virtual SortedMap {
public:
	TreeMap();
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_TREEMAP_H_ */
