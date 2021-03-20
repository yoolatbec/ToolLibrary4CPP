/*
 * File.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_FILE_H_
#define IO_FILE_H_

#include <tl/lang/Reference.h>
#include <cstdio>

namespace tl {
namespace io {

using lang::Reference;

class File: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 340;

	FILE* mDescriptor;
public:
	File(Reference);
	virtual ~File();
	File(const File &other) = delete;
	File& operator=(const File &other) = delete;
	bool exists();
	bool isFile();
	bool isDirectory();
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_FILE_H_ */
