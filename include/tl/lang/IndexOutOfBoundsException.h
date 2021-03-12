/*
 * IndexOutOfBoundsException.h
 *
 *  Created on: Mar 6, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_INDEXOUTOFBOUNDSEXCEPTION_H_
#define INCLUDE_LANG_INDEXOUTOFBOUNDSEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace lang {

class IndexOutOfBoundsException: public virtual Exception {
private:
	const static type_t CLASS_SERIAL = 78;
	constexpr const static char *DEFAULT_MESSAGE = "IndexOutOfBoundsException:";
	static Reference sDefaultMessage;
public:
	IndexOutOfBoundsException();
	IndexOutOfBoundsException(const char*);
	virtual ~IndexOutOfBoundsException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_INDEXOUTOFBOUNDSEXCEPTION_H_ */
