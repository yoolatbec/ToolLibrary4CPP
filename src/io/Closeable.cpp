/*
 * Closeable.cpp
 *
 *  Created on: Apr 1, 2021
 *      Author: yoolatbec
 */

#include <tl/io/Closeable.h>

namespace tl {
namespace io {

Closeable::Closeable() {
	// TODO Auto-generated constructor stub
	mClosed = false

	mHashCode = genHashCode(CLASS_SERIAL);
}

Closeable::~Closeable() {
	// TODO Auto-generated destructor stub
}

bool Closeable::isClosed() {
	return mClosed;
}

type_t Closeable::type() {
	return CLASS_SERIAL;
}

bool Closeable::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
