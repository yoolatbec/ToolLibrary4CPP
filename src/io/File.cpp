/*
 * File.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include "File.h"
#include <tl/lang/String.h>
#include <fcntl.h>
#include <unistd.h>
#include <tl/thread/Mutex.h>
#include <tl/io/ReopenStreamException.h>
#include "SimultaneousReadWriteException.h"
#include "Directory.h"
#include <tl/lang/Pointer.h>

namespace tl {
namespace io {

using thread::Mutex;
using lang::String;
using lang::Reference;
using lang::Pointer;

File::File(Reference path, bool append)
	: AbstractFile(path) {
	// TODO Auto-generated constructor stub
	String *str = dynamic_cast<String*>(path.getEntity());
	if (append) {
		mIdentifier = open(str->toCharArray(), O_RDWR | O_CREAT | O_APPEND,
			DEFAULT_ACCESS);
	} else {
		mIdentifier = open(str->toCharArray(), O_RDWR | O_CREAT | O_TRUNC,
			DEFAULT_ACCESS);
	}

	if (mIdentifier < 0) {
		//cast an exception
	}

	mMutex = Reference(new Mutex());
	mInputStream = Reference();
	mOutputStream = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

File::File(Reference parent, Reference path, bool append) {
	dismissNull(parent);
	argumentTypeCheck(parent, Directory::type());
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	Directory *dir = dynamic_cast<Directory*>(parent.getEntity());
	String *str = dynamic_cast<String*>(path.getEntity());
	if (append) {
		mIdentifier = openat(dir->mIdentifier, str->toCharArray(),
		O_RDWR | O_CREAT | O_APPEND, DEFAULT_ACCESS);
	} else {
		mIdentifier = openat(dir->mIdentifier, str->toCharArray(),
		O_RDWR | O_CREAT | O_TRUNC, DEFAULT_ACCESS);
	}

	if (mIdentifier < 0) {
		//cast an exception
	}

	mMutex = Reference(new Mutex());
	mInputStream = Reference();
	mOutputStream = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

File::~File() {
	// TODO Auto-generated destructor stub
	close(mIdentifier);
}

Reference File::openInputStream() {
	Mutex *mutex = dynamic_cast<Mutex*>(mMutex.getEntity());
	mutex->lock();

	if (!mOutputStream.isNull()) {
		OutputStream *out =
			dynamic_cast<OutputStream*>(mOutputStream.getEntity());
		if (!out->isClosed()) {
			//cast an exception
			throw SimultaneousReadWriteException();
		}
	}

	if (!mInputStream.isNull()) {
		InputStream *in = dynamic_cast<InputStream*>(mInputStream.getEntity());
		if (!in->isClosed()) {
			//cast an exception
			throw ReopenStreamException();
		}
	}

	mInputStream = Reference(new FileInputStream(mIdentifier));

	mutex->unlock();
	return mInputStream;
}

Reference File::openOutputStream() {
	Mutex *mutex = dynamic_cast<Mutex*>(mMutex.getEntity());
	mutex->lock();

	if (!mInputStream.isNull()) {
		InputStream *in = dynamic_cast<InputStream*>(mInputStream.getEntity());
		if (!in->isClosed()) {
			//cast an exception
			throw SimultaneousReadWriteException();
		}
	}

	if (!mOutputStream.isNull()) {
		OutputStream *out =
			dynamic_cast<OutputStream*>(mOutputStream.getEntity());
		if (!out->isClosed()) {
			//cast an exception
			throw ReopenStreamException();
		}
	}

	mOutputStream = Reference(new FileOutputStream(mIdentifier));
	mutex->unlock();

	return mOutputStream;
}

Reference File::openOutputStream(tlint bufferSize) {
	dismissNegative(bufferSize);

	Mutex *mutex = dynamic_cast<Mutex*>(mMutex.getEntity());
	mutex->lock();

	if (!mInputStream.isNull()) {
		InputStream *in = dynamic_cast<InputStream*>(mInputStream.getEntity());
		if (!in->isClosed()) {
			//cast an exception
			throw SimultaneousReadWriteException();
		}
	}

	if (!mOutputStream.isNull()) {
		OutputStream *out =
			dynamic_cast<OutputStream*>(mOutputStream.getEntity());
		if (!out->isClosed()) {
			//cast an exception
			throw ReopenStreamException();
		}
	}

	mOutputStream = Reference(new FileOutputStream(mIdentifier, bufferSize));

	mutex->unlock();
	return mOutputStream;
}

bool File::canRead() {
	String *path = dynamic_cast<String*>(mPath.getEntity());
	return access(path->toCharArray(), R_OK) == SUCCESS;
}

bool File::canWrite() {
	String *path = dynamic_cast<String*>(mPath.getEntity());
	return access(path->toCharArray(), W_OK) == SUCCESS;
}

bool File::canExecute() {
	String *path = dynamic_cast<String*>(mPath.getEntity());
	return access(path->toCharArray(), X_OK) == SUCCESS;
}

tlint64 File::length() {
	struct stat status;
	String *path = dynamic_cast<String*>(mPath.getEntity());
	if (stat(path->toCharArray(), &status) != SUCCESS) {
		//cast an exception
	}

	return status.st_size;
}

void File::newFile(Reference path) {
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	String *str = dynamic_cast<String*>(path.getEntity());

}

type_t File::type() {
	return CLASS_SERIAL;
}

bool File::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || AbstractFile::instanceof(type)
		|| Streaming::instanceof(type);
}

File::FileInputStream::FileInputStream(tlint identifier) {
	mIdentifier = identifier;

	mHashCode = genHashCode(CLASS_SERIAL);
}

tlint File::FileInputStream::readn(tlint length, Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Pointer::type());
	dismissNegative(length);

	Pointer *ptr = dynamic_cast<Pointer*>(ref.getEntity());
	return read(mIdentifier, ptr->get(), length);
}

Reference File::FileInputStream::readAll() {
	tlint64 marker = lseek(mIdentifier, 0, SEEK_CUR);
	tlint64 length = lseek(mIdentifier, 0, SEEK_END);
	lseek(mIdentifier, 0, SEEK_SET);

	byte *data = new byte[length];
	//add new handler to detect memory shortness

	read(mIdentifier, data, length);
	lseek(mIdentifier, marker, SEEK_SET);

	return Reference(new Pointer(data, length));
}

void File::FileInputStream::skip(tlint64 offset) {
	lseek(mIdentifier, offset, SEEK_CUR);
}

void File::FileInputStream::mark() {
	mMarker = lseek(mIdentifier, 0, SEEK_CUR);
}

void File::FileInputStream::reset() {
	lseek(mIdentifier, mMarker, SEEK_SET);
}

void File::FileInputStream::rewind() {
	lseek(mIdentifier, 0, SEEK_SET);
	mMarker = 0;
}

File::FileInputStream::~FileInputStream() {

}

type_t File::FileInputStream::type() {
	return CLASS_SERIAL;
}

bool File::FileInputStream::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || InputStream::instanceof(type);
}

File::FileOutputStream::FileOutputStream(tlint identifier) {
	mIdentifier = identifier;

	mHashCode = genHashCode(CLASS_SERIAL);
}

File::FileOutputStream::FileOutputStream(tlint identifier, tlint bufferSize)
	: OutputStream(bufferSize) {
	mIdentifier = identifier;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void File::FileOutputStream::writen(tlint length, Reference ref){
	dismissNull(ref);
	dismissNegative(length);

	if(length == 0){
		return;
	}

	argumentTypeCheck(ref, Pointer::type());
	if(mBuffer == nullptr){
		unbufferedWrite0(length, ref);
	} else {
		bufferedWrite0(length, ref);
	}
}

void File::FileOutputStream::writeAll(Reference ref){
	dismissNull(ref);
	argumentTypeCheck(ref, Pointer::type());
}

void File::FileOutputStream::flush(){
	tlint err = write(mIdentifier, mBuffer, mUsedBufferSize);
	if(err == -1){
		//cast an exception
		throw IOException();
	}

	mUsedBufferSize = 0;
}

} /* namespace io */
} /* namespace tl */
