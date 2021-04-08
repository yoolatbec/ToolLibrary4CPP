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
private:
	const static type_t CLASS_SERIAL = 2424;

	Reference standardizePath(Reference);
public:
	Directory(Reference);
	virtual ~Directory();
	Directory(const Directory &other) = delete;
	Directory& operator=(const Directory &other) = delete;
	Reference getPath();
	static void mkdir(Reference);
	static void mkdirs(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_DIRECTORY_H_ */
