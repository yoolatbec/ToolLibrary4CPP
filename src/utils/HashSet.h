/*
 * HashSet.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_HASHSET_H_
#define SRC_UTILS_HASHSET_H_

#include "Set.h"

namespace tl {
namespace utils {

class HashSet: public Set {
public:
	HashSet(hash_t);
	virtual ~HashSet();
	HashSet(const HashSet &other) = delete;
	HashSet& operator=(const HashSet &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_HASHSET_H_ */
