/*
 * FileInputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_FILEINPUTSTREAM_H_
#define IO_FILEINPUTSTREAM_H_

#include <tl/io/InputStream.h>

namespace tl {
namespace io {

class FileInputStream: public virtual InputStream {
public:
	FileInputStream();
	virtual ~FileInputStream();
	FileInputStream(const FileInputStream &other) = delete;
	FileInputStream& operator=(const FileInputStream &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_FILEINPUTSTREAM_H_ */
