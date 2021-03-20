/*
 * Reader.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_READER_H_
#define IO_READER_H_

#include <tl/lang/Object.h>

namespace tl {
namespace io {

class Reader: public virtual lang::Object {
public:
	Reader();
	virtual ~Reader();
	Reader(const Reader &other) = delete;
	Reader& operator=(const Reader &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_READER_H_ */
