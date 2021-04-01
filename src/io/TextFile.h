/*
 * TextFile.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef IO_TEXTFILE_H_
#define IO_TEXTFILE_H_

#include "File.h"
#include <tl/io/TextStreaming.h>

namespace tl {
namespace io {

class TextFile: public virtual File, public virtual TextStreaming {
public:
	TextFile(Reference);
	virtual ~TextFile();
	TextFile(const TextFile &other) = delete;
	TextFile& operator=(const TextFile &other) = delete;
	bool isFile();
	bool isDirectory();
	Reference getReader();
	Reference getWriter();
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_TEXTFILE_H_ */
