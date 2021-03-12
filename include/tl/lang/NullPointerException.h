/*
 * NullPointerException.h
 *
 *  Created on: Mar 7, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_NULLPOINTEREXCEPTION_H_
#define INCLUDE_LANG_NULLPOINTEREXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace lang {

class NullPointerException: public virtual Exception {
private:
	const static type_t CLASS_SERIAL = 67;
	constexpr const static char *DEFAULT_MESSAGE = "NullPointerException:";
	static Reference sDefaultMessage;
public:
	NullPointerException();
	NullPointerException(const char*);
	virtual ~NullPointerException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_NULLPOINTEREXCEPTION_H_ */
