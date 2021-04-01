/*
 * FileOutputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_FILEOUTPUTSTREAM_H_
#define IO_FILEOUTPUTSTREAM_H_

#include <tl/io/OutputStream.h>

namespace tl {
namespace io {

class FileOutputStream: public virtual OutputStream {
public:
	FileOutputStream();
	virtual ~FileOutputStream();
	FileOutputStream(const FileOutputStream &other) = delete;
	FileOutputStream& operator=(const FileOutputStream &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_FILEOUTPUTSTREAM_H_ */
