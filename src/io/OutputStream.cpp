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
	mBufferSize = DEFAULT_BUFFER_SIZE;
	mBuffer = new byte[mBufferSize];
	mUsedBufferSize = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

OutputStream::OutputStream(tlint bufferSize) {
	dismissNegative(bufferSize);

	mBufferSize = bufferSize;
	mUsedBufferSize = 0;
	if (mBufferSize == 0) {
		mBuffer = nullptr;
	} else {
		mBuffer = new byte[mBufferSize];
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

OutputStream::~OutputStream() {
	// TODO Auto-generated destructor stub
	delete[] mBuffer;
}

void OutputStream::flush() {
	//throw an exception
	throw UnsupportedOperationException();
}

tlint OutputStream::bufferSize() {
	return mBufferSize;
}

bool OutputStream::isBuffered() {
	return mBufferSize != 0;
}

void OutputStream::flush(){
	//cast an exception
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
