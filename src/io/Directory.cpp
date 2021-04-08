/*
 * Directory.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include "Directory.h"

namespace tl {
namespace io {

using lang::String;

Directory::Directory(Reference path) {
	// TODO Auto-generated constructor stub
	mPath = standardizePath(path);
	String* dirPath = dynamic_cast<String*>(mPath.getEntity());
	mIdentifier = open(dirPath->toCharArray(), )

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference Directory::standardizePath(Reference path){

}

Directory::~Directory() {
	// TODO Auto-generated destructor stub
}

} /* namespace io */
} /* namespace tl */
