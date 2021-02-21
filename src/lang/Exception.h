/*
 * Exception.h
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_EXCEPTION_H_
#define SRC_LANG_EXCEPTION_H_

#include "Reference.h"

namespace tl {
namespace lang {

class Exception: public Object {
private:
	const static type_t CLASS_SERIAL = 10;
public:
	Exception();
	explicit Exception(const String&);
	virtual ~Exception();
	Exception(const Exception &other) = delete;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_EXCEPTION_H_ */
