/*
 * File.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#include "AbstractFile.h"
#include <tl/lang/String.h>
#include <unistd.h>
#include <sys/stat.h>

namespace tl {
namespace io {

using lang::String;

AbstractFile::AbstractFile(Reference path) {
	// TODO Auto-generated constructor stub
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	mPath = path;
	mHashCode = genHashCode(CLASS_SERIAL);
}

AbstractFile::~AbstractFile() {
	// TODO Auto-generated destructor stub
}

bool AbstractFile::exists(Reference path) {
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	String *str = dynamic_cast<String*>(path.getEntity());
	tlint ret = access(str->toCharArray(), F_OK);

	return ret == FILE_ACCESSIBLE;
}

bool AbstractFile::isDirectory(Reference path) {
	if (!exists(path)) {
		//cast an exception
	}

	String *str = dynamic_cast<String*>(path.getEntity());
	struct stat status;
	tlint err = stat(str->toCharArray(), &status);
	if (err != SUCCESS) {
		//cast an exception
	}

	return S_ISDIR(status.st_mode);
}

bool AbstractFile::isFile(Reference path) {
	if (!exists(path)) {
		//cast an exception
	}

	String *str = dynamic_cast<String*>(path.getEntity());
	struct stat status;
	tlint err = stat(str->toCharArray(), &status);
	if (err != SUCCESS) {
		//cast an exception
	}

	return S_ISREG(status.st_mode);
}

bool AbstractFile::isSymbol(Reference path) {
	if (!exists(path)) {
		//cast an exception
	}

	String *str = dynamic_cast<String*>(path.getEntity());
	struct stat status;
	tlint err = lstat(str->toCharArray(), &status);
	if (err != SUCCESS) {
		//cast an exception
	}

	return S_ISLNK(status.st_mode);
}

Reference AbstractFile::getPath() {
	return mPath;
}

type_t AbstractFile::type() {
	return CLASS_SERIAL;
}

bool AbstractFile::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
