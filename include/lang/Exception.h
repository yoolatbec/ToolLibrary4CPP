/*
 * Exception.h
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_EXCEPTION_H_
#define INCLUDE_LANG_EXCEPTION_H_

#include <lang/Reference.h>

namespace tl {
namespace lang {

using lang::Reference;

class Exception: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 10;
	Reference mMessage;
public:
	Exception();
	explicit Exception(Reference);
	virtual ~Exception();
	Reference message();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_EXCEPTION_H_ */