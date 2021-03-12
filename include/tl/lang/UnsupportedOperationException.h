/*
 * UnsupportedOperationException.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_UNSUPPORTEDOPERATIONEXCEPTION_H_
#define TL_LANG_UNSUPPORTEDOPERATIONEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace lang {

class UnsupportedOperationException: public virtual Exception {
private:
	const static type_t CLASS_SERIAL = 348;
	constexpr const static char *DEFAULT_MESSAGE =
		"UnsupportedOperationException:";
	static Reference sDefaultMessage;
public:
	UnsupportedOperationException();
	UnsupportedOperationException(const char*);
	virtual ~UnsupportedOperationException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_UNSUPPORTEDOPERATIONEXCEPTION_H_ */
