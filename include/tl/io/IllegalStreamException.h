/*
 * RecloseException.h
 *
 *  Created on: Apr 6, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_ILLEGALSTREAMEXCEPTION_H_
#define TL_IO_ILLEGALSTREAMEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class IllegalStreamException: public virtual IOException {
private:
	const static type_t CLASS_SERIAL = 3665;
	const static constexpr char *DEFAULT_MESSAGE = "IllegalStreamException:";
	static Reference sDefaultMessage;

public:
	IllegalStreamException();
	IllegalStreamException(const char*);
	virtual ~IllegalStreamException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_ILLEGALSTREAMEXCEPTION_H_ */
