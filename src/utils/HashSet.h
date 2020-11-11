/*
 * HashSet.h
 *
 *  Created on: 2020Äê11ÔÂ11ÈÕ
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_HASHSET_H_
#define SRC_UTILS_HASHSET_H_

#include "Set.h"

namespace tl {
namespace utils {

class HashSet: public Set {
public:
	HashSet();
	virtual ~HashSet();
	HashSet(const HashSet &other) = delete;
	HashSet& operator=(const HashSet &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_HASHSET_H_ */
