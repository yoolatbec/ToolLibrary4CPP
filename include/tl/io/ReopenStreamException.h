/*
 * ReopenStreamException.h
 *
 *  Created on: Mar 28, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_REOPENSTREAMEXCEPTION_H_
#define TL_IO_REOPENSTREAMEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class ReopenStreamException: public virtual IOException {
public:
	ReopenStreamException();
	virtual ~ReopenStreamException();
	ReopenStreamException(const ReopenStreamException &other) = delete;
	ReopenStreamException& operator=(const ReopenStreamException &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_REOPENSTREAMEXCEPTION_H_ */
