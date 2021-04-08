/*
 * FailedToOpenFileException.h
 *
 *  Created on: Apr 6, 2021
 *      Author: yoolatbec
 */

#ifndef IO_FAILEDTOOPENFILEEXCEPTION_H_
#define IO_FAILEDTOOPENFILEEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class FailedToOpenFileException: public virtual IOException {
public:
	FailedToOpenFileException();
	virtual ~FailedToOpenFileException();
	FailedToOpenFileException(const FailedToOpenFileException &other) = delete;
	FailedToOpenFileException& operator=(const FailedToOpenFileException &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_FAILEDTOOPENFILEEXCEPTION_H_ */
