/*
 * Set.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_SET_H_
#define SRC_UTILS_SET_H_

#include "Collection.h"

namespace tl {
namespace utils {

class Set: public Collection {
private:
	const static hash_t CLASS_HASH = 500L << 32;
public:
	Set(hash_t type);
	virtual ~Set();
	Set(const Set &other) = delete;
	Set& operator=(const Set &other) = delete;
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};


} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_SET_H_ */
