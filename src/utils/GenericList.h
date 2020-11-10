/*
 * GenericList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_GENERICLIST_H_
#define SRC_UTILS_GENERICLIST_H_

#include "GenericCollection.h"

namespace tl {
namespace utils {

class GenericList: public virtual GenericCollection {
private:
	static const hash_t CLASS_HASH = 21L << 32;
public:
	GenericList();
	virtual ~GenericList();
	GenericList(const GenericList &other) = delete;
	static hash_t getType();
	bool instanceof(hash_t) const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_GENERICLIST_H_ */
