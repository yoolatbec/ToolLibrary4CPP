/*
 * TextStreaming.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/io/TextStreaming.h>
#include <tl/lang/UnsupportedOperationException.h>

namespace tl {
namespace io {

using lang::UnsupportedOperationException;

TextStreaming::TextStreaming() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

TextStreaming::~TextStreaming() {
	// TODO Auto-generated destructor stub
}

Reference TextStreaming::getReader() {
	throw UnsupportedOperationException();
}

Reference TextStreaming::getWriter() {
	throw UnsupportedOperationException();
}

type_t TextStreaming::type() {
	return CLASS_SERIAL;
}

bool TextStreaming::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Streaming::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
