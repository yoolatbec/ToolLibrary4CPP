/*
 * IOException.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/io/IOException.h>
#include <tl/lang/String.h>

namespace tl {
namespace io {

using lang::String;

Reference IOException::sDefaultMessage = Reference(new String(DEFAULT_MESSAGE));

IOException::IOException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IOException::IOException(const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IOException::~IOException() {
	// TODO Auto-generated destructor stub
}

type_t IOException::type() {
	return CLASS_SERIAL;
}

bool IOException::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
