/*
 * Comparable.h
 *
 *  Created on: Sep 28, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_COMPARABLE_H_
#define SRC_LANG_COMPARABLE_H_

#include "Reference.h"

namespace tl {
namespace lang {

class Comparable: public virtual Object {
private:
	const static hash_t CLASS_HASH = 11L << 32;
public:
	virtual tlint compareTo(const Reference&) const = 0;
	virtual bool instanceof(hash_t) const;
	static hash_t getType();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_COMPARABLE_H_ */
