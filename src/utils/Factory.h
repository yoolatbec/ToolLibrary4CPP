/*
 * Factory.h
 *
 *  Created on: Sep 10, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_FACTORY_H_
#define SRC_UTILS_FACTORY_H_

#include "List.h"
#include "../lang/Reference.h"

namespace tl {
namespace utils {

class Factory: public lang::Object {
	using tl::lang::Reference;
private:
	static const hash_t CLASS_HASH = 32L << 32;
	const Reference (*generator)(Reference);
public:
	explicit Factory(Reference (*)(Reference));
	Reference generate(const Reference&) const;
	virtual bool instanceof(hash_t type) const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_FACTORY_H_ */
