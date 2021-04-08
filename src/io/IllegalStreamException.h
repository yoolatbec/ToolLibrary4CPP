/*
 * RecloseException.h
 *
 *  Created on: Apr 6, 2021
 *      Author: yoolatbec
 */

#ifndef IO_ILLEGALSTREAMEXCEPTION_H_
#define IO_ILLEGALSTREAMEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class IllegalStreamException: public virtual IOException {
public:
	IllegalStreamException();
	virtual ~IllegalStreamException();
	IllegalStreamException(const IllegalStreamException &other) = delete;
	IllegalStreamException& operator=(const IllegalStreamException &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_ILLEGALSTREAMEXCEPTION_H_ */
