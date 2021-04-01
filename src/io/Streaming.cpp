/*
 * Streaming.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: yoolatbec
 */

#include <tl/io/Streaming.h>
#include <tl/lang/UnsupportedOperationException.h>

namespace tl {
namespace io {

using lang::UnsupportedOperationException;

Streaming::Streaming() {
	// TODO Auto-generated constructor stub

}

Streaming::~Streaming() {
	// TODO Auto-generated destructor stub
}

Reference Streaming::openInputStream() {
	throw UnsupportedOperationException();
}

Reference Streaming::openOutputStream() {
	throw UnsupportedOperationException();
}

type_t Streaming::type() {
	return CLASS_SERIAL;
}

bool Streaming::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
