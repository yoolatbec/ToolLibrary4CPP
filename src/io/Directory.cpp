/*
 * Directory.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/io/Directory.h>
#include <tl/lang/String.h>
#include <unistd.h>
#include <tl/io/IOException.h>

namespace tl {
namespace io {

using lang::String;

Directory::Directory(Reference path) {
	// TODO Auto-generated constructor stub
	mPath = standardizePath(path);
	String *dirPath = dynamic_cast<String*>(mPath.getEntity());
	mDirectory = opendir(dirPath->toCharArray());
	if (mDirectory == nullptr) {
		throw IOException();
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference Directory::standardizePath(Reference path) {
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	String *str = dynamic_cast<String*>(path.getEntity());
	const char *s = str->toCharArray();
	if (s[str->length() - 1] != '/') {
		return str->append('/');
	}

	return path;
}

void Directory::remove() {
	String *path = dynamic_cast<String*>(mPath.getEntity());

	tlint err = rmdir(path->toCharArray());
	if (err != SUCCESS) {
		throw IOException();
	}
}

void Directory::newDirectory(Reference path) {
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	String *str = dynamic_cast<String*>(path.getEntity());
	tlint err = mkdir(str->toCharArray(), DEFAULT_DIRECTORY_ACCESS);
	if (err != SUCCESS) {
		throw IOException();
	}
}

Directory::~Directory() {
	// TODO Auto-generated destructor stub
}

type_t Directory::type() {
	return CLASS_SERIAL;
}

bool Directory::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || AbstractFile::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
