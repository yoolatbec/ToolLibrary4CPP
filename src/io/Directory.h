/*
 * Directory.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef IO_DIRECTORY_H_
#define IO_DIRECTORY_H_

#include "AbstractFile.h"

namespace tl {
namespace io {

class Directory: public virtual AbstractFile {

public:
	Directory(Reference);
	virtual ~Directory();
	Directory(const Directory &other) = delete;
	Directory& operator=(const Directory &other) = delete;
	static type_t type();
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_DIRECTORY_H_ */
