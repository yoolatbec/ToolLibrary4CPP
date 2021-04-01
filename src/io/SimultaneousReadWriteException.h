/*
 * SimultaneousReadWriteException.h
 *
 *  Created on: Mar 28, 2021
 *      Author: yoolatbec
 */

#ifndef IO_SIMULTANEOUSREADWRITEEXCEPTION_H_
#define IO_SIMULTANEOUSREADWRITEEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class SimultaneousReadWriteException: public virtual IOException {
public:
	SimultaneousReadWriteException();
	virtual ~SimultaneousReadWriteException();
	SimultaneousReadWriteException(const SimultaneousReadWriteException &other) = delete;
	SimultaneousReadWriteException& operator=(
		const SimultaneousReadWriteException &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_SIMULTANEOUSREADWRITEEXCEPTION_H_ */
