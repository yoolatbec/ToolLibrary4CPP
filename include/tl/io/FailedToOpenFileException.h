/*
 * FailedToOpenFileException.h
 *
 *  Created on: Apr 6, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_FAILEDTOOPENFILEEXCEPTION_H_
#define TL_IO_FAILEDTOOPENFILEEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class FailedToOpenFileException: public virtual IOException {
private:
	const static type_t CLASS_SERIAL = 2456;
	const constexpr static char *DEFAULT_MESSAGE = "FailedToOpenFileException:";
	static Reference sDefaultMessage;

public:
	FailedToOpenFileException();
	FailedToOpenFileException(const char*);
	virtual ~FailedToOpenFileException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_FAILEDTOOPENFILEEXCEPTION_H_ */
