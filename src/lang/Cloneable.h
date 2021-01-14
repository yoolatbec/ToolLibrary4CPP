/*
 * Cloneable.h
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_CLONEABLE_H_
#define SRC_LANG_CLONEABLE_H_

#include "Reference.h"

namespace tl {
namespace lang {

class Cloneable: public Object {
private:
	static const type_t CLASS_SERIAL = 4;
public:
	Cloneable();
	virtual ~Cloneable();
	Cloneable(const Cloneable &other) = delete;
	Cloneable& operator=(const Cloneable &other) = delete;
	virtual Reference clone() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_CLONEABLE_H_ */
