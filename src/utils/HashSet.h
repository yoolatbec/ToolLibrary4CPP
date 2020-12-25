/*
 * HashSet.h
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_HASHSET_H_
#define SRC_UTILS_HASHSET_H_

#include "Set.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {

using lang::Array;

class HashSet: public Set {
private:
	const static type_t CLASS_SERIAL = 84;
protected:
	class HashEntry: public Entry{

	};
public:
	HashSet(hash_t);
	virtual ~HashSet();
	HashSet(const HashSet &other) = delete;
	HashSet& operator=(const HashSet &other) = delete;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_HASHSET_H_ */
