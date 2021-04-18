/*
 * HashMap.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_HASHMAP_H_
#define UTILS_HASHMAP_H_

#include "Map.h"

namespace tl {
namespace utils {

class HashMap: public virtual Map {
public:
	HashMap();
	virtual ~HashMap();
	HashMap(const HashMap &other) = delete;
	HashMap& operator=(const HashMap &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_HASHMAP_H_ */
