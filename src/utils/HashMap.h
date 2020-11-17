/*
 * HashMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_HASHMAP_H_
#define SRC_UTILS_HASHMAP_H_

#include "Map.h"

namespace tl {
namespace utils {

class HashMap: virtual public Map {
public:
	HashMap();
	virtual ~HashMap();
	HashMap(const HashMap &other) = delete;
	HashMap& operator=(const HashMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_HASHMAP_H_ */
