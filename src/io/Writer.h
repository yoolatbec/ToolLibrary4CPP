/*
 * Writer.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef IO_WRITER_H_
#define IO_WRITER_H_

#include <tl/io/Closeable.h>

namespace tl {
namespace io {

class Writer: public virtual Closeable {
public:
	Writer();
	virtual ~Writer();
	Writer(const Writer &other) = delete;
	Writer& operator=(const Writer &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_WRITER_H_ */
