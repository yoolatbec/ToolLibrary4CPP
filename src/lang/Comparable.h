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
	const static type_t CLASS_SERIAL = 11;
public:
	virtual tlint compareTo(Reference) = 0;
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_COMPARABLE_H_ */
