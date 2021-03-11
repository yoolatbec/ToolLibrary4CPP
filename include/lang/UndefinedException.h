/*
 * UndefinedException.h
 *
 *  Created on: Feb 24, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_UNDEFINEDEXCEPTION_H_
#define INCLUDE_LANG_UNDEFINEDEXCEPTION_H_

#include <lang/Exception.h>

namespace tl {
namespace lang {

class UndefinedException: public virtual Exception {
private:
	const static type_t CLASS_SERIAL = 656;
	constexpr const static char *DEFAULT_MESSAGE = "UndefinedException:";
	static Reference sDefaultMessage;
public:
	UndefinedException();
	UndefinedException(const char*);
	virtual ~UndefinedException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_UNDEFINEDEXCEPTION_H_ */
