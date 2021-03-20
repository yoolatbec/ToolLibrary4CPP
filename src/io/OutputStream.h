/*
 * OutputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_OUTPUTSTREAM_H_
#define IO_OUTPUTSTREAM_H_

#include <tl/lang/Object.h>

namespace tl {
namespace io {

class OutputStream: public virtual lang::Object {
public:
	OutputStream();
	virtual ~OutputStream();
	OutputStream(const OutputStream &other) = delete;
	OutputStream& operator=(const OutputStream &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_OUTPUTSTREAM_H_ */
