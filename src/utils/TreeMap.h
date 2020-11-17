/*
 * TreeMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_TREEMAP_H_
#define SRC_UTILS_TREEMAP_H_

#include "Map.h"

namespace tl {
namespace utils {

class TreeMap: public virtual Map {
public:
	TreeMap();
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREEMAP_H_ */
