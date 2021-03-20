/*
 * Writer.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_WRITER_H_
#define IO_WRITER_H_

#include <tl/lang/Object.h>

namespace tl {
namespace io {

class Writer: public virtual lang::Object {
public:
	Writer();
	virtual ~Writer();
	Writer(const Writer &other) = delete;
	Writer& operator=(const Writer &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_WRITER_H_ */
