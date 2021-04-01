/*
 * File.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef IO_ABSTRACTFILE_H_
#define IO_ABSTRACTFILE_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace io {

using lang::Reference;

class AbstractFile: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 340;

protected:
	const static tlint FILE_ACCESSIBLE = 0;
	const static tlint SUCCESS = 0;
	const static tlint UNSUCCESS = -1;

	Reference  mPath;
	tlint mIdentifier;

	AbstractFile(Reference);
	AbstractFile();
public:
	virtual ~AbstractFile();
	AbstractFile(const AbstractFile &other) = delete;
	AbstractFile& operator=(const AbstractFile &other) = delete;
	static bool exists(Reference);
	static bool isFile(Reference);
	static bool isDirectory(Reference);
	static bool isSymbol(Reference);
	Reference getPath();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_ABSTRACTFILE_H_ */
