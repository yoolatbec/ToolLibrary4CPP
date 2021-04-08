/*
 * Directory.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_DIRECTORY_H_
#define TL_IO_DIRECTORY_H_

#include <tl/io/AbstractFile.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

namespace tl {
namespace io {

class Directory: public virtual AbstractFile {
private:
	const static type_t CLASS_SERIAL = 2424;
	const static tlint DEFAULT_DIRECTORY_ACCESS = S_IRUSR | S_IWUSR | S_IXUSR
		| S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IXOTH;

	DIR* mDirectory;

	Reference standardizePath(Reference);
public:
	Directory(Reference);
	virtual ~Directory();
	Directory(const Directory &other) = delete;
	Directory& operator=(const Directory &other) = delete;
	void remove();
	static void newDirectory(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_DIRECTORY_H_ */
