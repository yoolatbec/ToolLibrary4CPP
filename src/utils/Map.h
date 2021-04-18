/*
 * Map.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef UTILS_MAP_H_
#define UTILS_MAP_H_

#include <tl/lang/Object.h>

namespace tl {
namespace utils {

class Map: public virtual lang::Object {
public:
	Map();
	virtual ~Map();
	Map(const Map &other) = delete;
	Map& operator=(const Map &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* UTILS_MAP_H_ */
