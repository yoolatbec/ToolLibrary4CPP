/*
 * InputStream.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#include <tl/io/InputStream.h>
#include <tl/lang/UnsupportedOperationException.h>

namespace tl {
namespace io {

using lang::UnsupportedOperationException;

InputStream::InputStream() {
	// TODO Auto-generated constructor stub
	mMarker = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

InputStream::~InputStream() {
	// TODO Auto-generated destructor stub
}

tlint InputStream::readn(Reference ref, tlint length) {
	//cast an exception
	throw UnsupportedOperationException();
}

Reference InputStream::readAll() {
	//cast an exception
	throw UnsupportedOperationException();
}

void InputStream::skip(tlint64 offset) {
	//throw an exception
	throw UnsupportedOperationException();
}

void InputStream::mark() {
	//throw an exception
	throw UnsupportedOperationException();
}

void InputStream::reset() {
	//throw an exception
	throw UnsupportedOperationException();
}

void InputStream::rewind() {
	//throw an exception
	throw UnsupportedOperationException();
}

type_t InputStream::type() {
	return CLASS_SERIAL;
}

bool InputStream::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
