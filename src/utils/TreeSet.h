/*
 * TreeSet.h
 *
 *  Created on: 2020Äê11ÔÂ11ÈÕ
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_TREESET_H_
#define SRC_UTILS_TREESET_H_

#include "Set.h"

namespace tl {
namespace utils {

class TreeSet: public Set {
public:
	TreeSet();
	virtual ~TreeSet();
	TreeSet(const TreeSet &other) = delete;
	TreeSet& operator=(const TreeSet &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREESET_H_ */
