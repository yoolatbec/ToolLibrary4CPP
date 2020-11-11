/*
 * Set.h
 *
 *  Created on: 2020Äê11ÔÂ11ÈÕ
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_SET_H_
#define SRC_UTILS_SET_H_

#include "Collection.h"

namespace tl {
namespace utils {

class Set: public Collection {
public:
	Set();
	virtual ~Set();
	Set(const Set &other) = delete;
	Set& operator=(const Set &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_SET_H_ */
