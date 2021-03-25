/*
 * TextFile.h
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#ifndef IO_TEXTFILE_H_
#define IO_TEXTFILE_H_

#include "File.h"

namespace tl {
namespace io {

class TextFile: public virtual File {
public:
	TextFile();
	virtual ~TextFile();
	TextFile(const TextFile &other) = delete;
	TextFile& operator=(const TextFile &other) = delete;
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_TEXTFILE_H_ */
