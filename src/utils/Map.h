/*
 * Map.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_MAP_H_
#define SRC_UTILS_MAP_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class Map: virtual public lang::Object {
public:
	Map();
	virtual ~Map();
	Map(const Map &other) = delete;
	Map& operator=(const Map &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_MAP_H_ */
