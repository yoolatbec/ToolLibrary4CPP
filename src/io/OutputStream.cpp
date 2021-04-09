/*
 * OutputStream.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#include <tl/io/OutputStream.h>
#include <tl/lang/UnsupportedOperationException.h>

namespace tl {
namespace io {

using lang::UnsupportedOperationException;

OutputStream::OutputStream() {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

OutputStream::~OutputStream() {
	// TODO Auto-generated destructor stub
}

void OutputStream::flush() {
	//throw an exception
	throw UnsupportedOperationException();
}

void OutputStream::writen(Reference ref, tlint length){
	//cast an exception
	throw UnsupportedOperationException();
}

void OutputStream::writeAll(Reference ref){
	//cast an exception
	throw UnsupportedOperationException();
}

void OutputStream::writeByte(byte b){
	//cast an exception
	throw UnsupportedOperationException();
}

type_t OutputStream::type() {
	return CLASS_SERIAL;
}

bool OutputStream::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Closeable::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
