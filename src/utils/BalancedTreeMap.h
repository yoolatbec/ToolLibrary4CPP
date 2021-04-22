/*
 * BalancedTreeMap.h
 *
 *  Created on: Apr 22, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_BALANCEDTREEMAP_H_
#define UTILS_BALANCEDTREEMAP_H_

#include <tl/utils/SortedMap.h>

namespace tl {
namespace utils {

class BalancedTreeMap: public virtual SortedMap {
public:
	BalancedTreeMap();
	virtual ~BalancedTreeMap();
	BalancedTreeMap(const BalancedTreeMap &other) = delete;
	BalancedTreeMap& operator=(const BalancedTreeMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_BALANCEDTREEMAP_H_ */
