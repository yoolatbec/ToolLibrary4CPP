/*
 * Cloneable.h
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_CLONEABLE_H_
#define INCLUDE_LANG_CLONEABLE_H_

#include <tl/lang/Reference.h>

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

#endif /* INCLUDE_LANG_CLONEABLE_H_ */
