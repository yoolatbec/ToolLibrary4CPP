/*
 * InputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_INPUTSTREAM_H_
#define IO_INPUTSTREAM_H_

#include <tl/lang/Object.h>

namespace tl {
namespace io {

class InputStream: public virtual lang::Object {
public:
	InputStream();
	virtual ~InputStream();
	InputStream(const InputStream &other) = delete;
	InputStream& operator=(const InputStream &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_INPUTSTREAM_H_ */
