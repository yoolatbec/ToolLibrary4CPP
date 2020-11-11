/*
 * Map.h
 *
 *  Created on: 2020Äê11ÔÂ11ÈÕ
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_MAP_H_
#define SRC_UTILS_MAP_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class Map: public lang::Object {
public:
	Map();
	virtual ~Map();
	Map(const Map &other) = delete;
	Map& operator=(const Map &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_MAP_H_ */
