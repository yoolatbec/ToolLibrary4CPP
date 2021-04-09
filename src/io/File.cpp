/*
 * File.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <fcntl.h>
#include <tl/io/Directory.h>
#include <tl/io/FailedToOpenFileException.h>
#include <tl/io/File.h>
#include <tl/io/IllegalStreamException.h>
#include <unistd.h>
#include <tl/thread/Mutex.h>
#include <tl/io/ReopenStreamException.h>
#include <tl/io/SimultaneousReadWriteException.h>
#include <tl/lang/ByteArray.h>
#include <tl/lang/IndexOutOfBoundsException.h>
#include <tl/lang/Integer.h>

namespace tl {
namespace io {

using thread::Mutex;
using lang::String;
using lang::Reference;
using lang::ByteArray;
using lang::IndexOutOfBoundsException;
using lang::Integer;

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

	if (mIdentifier == INVALID_IDENTIFIER) {
		//cast an exception
		throw FailedToOpenFileException();
	}

	mMutex = Reference(new Mutex());
	mInputStream = Reference();
	mOutputStream = Reference();
	mAppending = append;

	mHashCode = genHashCode(CLASS_SERIAL);
}

File::File(Reference parent, Reference path, bool append)
	: AbstractFile(parent, path) {
	String *str = dynamic_cast<String*>(mPath.getEntity());

	if (append) {
		mIdentifier = open(str->toCharArray(),
		O_RDWR | O_CREAT | O_APPEND, DEFAULT_ACCESS);
	} else {
		mIdentifier = open(str->toCharArray(),
		O_RDWR | O_CREAT | O_TRUNC, DEFAULT_ACCESS);
	}

	if (mIdentifier == INVALID_IDENTIFIER) {
		//cast an exception
		throw FailedToOpenFileException();
	}

	mMutex = Reference(new Mutex());
	mInputStream = Reference();
	mOutputStream = Reference();
	mAppending = append;

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

	mInputStream = Reference(new FileInputStream(mPath));

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

	mOutputStream = Reference(new FileOutputStream(mPath, mAppending));
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

void File::remove() {
	if (!mInputStream.isNull()) {
		InputStream *in = dynamic_cast<InputStream*>(mInputStream.getEntity());
		if (!in->isClosed()) {
			throw IOException();
		}
	}

	if (!mOutputStream.isNull()) {
		OutputStream *out =
			dynamic_cast<OutputStream*>(mOutputStream.getEntity());
		if (!out->isClosed()) {
			throw IOException();
		}
	}

	String *path = dynamic_cast<String*>(mPath.getEntity());
	tlint err = unlink(path->toCharArray());
	if (err != SUCCESS) {
		throw IOException();
	}
}

tlint64 File::length() {
	struct stat status;
	String *path = dynamic_cast<String*>(mPath.getEntity());
	if (stat(path->toCharArray(), &status) != SUCCESS) {
		//cast an exception
		throw IOException();
	}

	return status.st_size;
}

void File::newFile(Reference path) {
	if (!isAbsolutePath(path)) {
		//cast an exception
		throw IOException();
	}

	String *str = dynamic_cast<String*>(path.getEntity());
	tlint identifier = open(str->toCharArray(), O_RDONLY | O_CREAT | O_EXCL,
		DEFAULT_ACCESS);

	if (identifier == INVALID_IDENTIFIER) {
		throw IOException();
	}
}

bool File::isAbsolutePath(Reference path) {
	dismissNull(path);
	argumentTypeCheck(path, String::type());

	String *str = dynamic_cast<String*>(path.getEntity());
	const char *s = str->toCharArray();
	return s[0] == '/';
}

type_t File::type() {
	return CLASS_SERIAL;
}

bool File::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || AbstractFile::instanceof(type)
		|| Streaming::instanceof(type);
}

File::FileInputStream::FileInputStream(Reference path) {
	mPath = path;
	String *p = dynamic_cast<String*>(mPath.getEntity());
	mIdentifier = open(p->toCharArray(), O_RDONLY);

	if (mIdentifier == INVALID_IDENTIFIER) {
		//cast an exception
		throw FailedToOpenFileException();
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference File::FileInputStream::getPath() {
	return mPath;
}

tlint File::FileInputStream::readn(tlint length, Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, ByteArray::type());
	dismissNegative(length);

	ByteArray *arr = dynamic_cast<ByteArray*>(ref.getEntity());
	if (arr->size() < length) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	byte *data = new byte[length];
	tlint realLength = read(mIdentifier, data, length);

	for (tlint index = 0; index < realLength; index++) {
		arr->set(index, data[index]);
	}
	delete[] data;

	return realLength;
}

Reference File::FileInputStream::readAll() {
	tlint64 marker = lseek(mIdentifier, 0, SEEK_CUR);
	tlint64 length = lseek(mIdentifier, 0, SEEK_END);
	lseek(mIdentifier, 0, SEEK_SET);

	if (length > Integer::MAX_VALUE) {
		length = Integer::MAX_VALUE;
	}

	byte *data = new byte[length];
	//add new handler to detect memory shortness

	read(mIdentifier, data, length);
	lseek(mIdentifier, marker, SEEK_SET);

	Reference rtval = ByteArray::newInstance(length, data, true);

	return rtval;
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

void File::FileInputStream::shutDown() {
	if (mIdentifier == INVALID_IDENTIFIER) {
		//cast an exception
		throw IllegalStreamException();
	}

	close(mIdentifier);
	mIdentifier = INVALID_IDENTIFIER;
	mClosed = true;
}

File::FileInputStream::~FileInputStream() {
	if (!isClosed()) {
		close(mIdentifier);
	}
}

type_t File::FileInputStream::type() {
	return CLASS_SERIAL;
}

bool File::FileInputStream::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || InputStream::instanceof(type);
}

File::FileOutputStream::FileOutputStream(Reference path, bool append) {
	mPath = path;
	String *p = dynamic_cast<String*>(mPath.getEntity());
	if (append) {
		mIdentifier = open(p->toCharArray(), O_WRONLY | O_CREAT | O_APPEND,
			DEFAULT_WRITE_ACCESS);
	} else {
		mIdentifier = open(p->toCharArray(), O_WRONLY | O_CREAT | O_TRUNC,
			DEFAULT_WRITE_ACCESS);
	}

	if (mIdentifier == INVALID_IDENTIFIER) {
		//cast an exception
		throw FailedToOpenFileException();
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

void File::FileOutputStream::writen(tlint length, Reference ref) {
	dismissNull(ref);
	dismissNegative(length);
	argumentTypeCheck(ref, ByteArray::type());

	if (length == 0) {
		return;
	}

	ByteArray *arr = dynamic_cast<ByteArray*>(ref.getEntity());
	if (arr->size() < length) {
		//cast an exception
		throw IndexOutOfBoundsException();
	}

	tlint count = write(mIdentifier, arr->rawData(), length);
	if (count == UNSUCCESS_WRITE) {
		//cast an exception
		throw IOException();
	}
}

void File::FileOutputStream::writeAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, ByteArray::type());

	ByteArray *arr = dynamic_cast<ByteArray*>(ref.getEntity());

	tlint count = write(mIdentifier, arr->rawData(), arr->size());
	if (count == UNSUCCESS_WRITE) {
		//cast an exception
		throw IOException();
	}
}

void File::FileOutputStream::writeByte(byte b) {
	tlint count = write(mIdentifier, &b, sizeof(byte));
	if (count == UNSUCCESS_WRITE) {
		throw IOException();
	}
}

void File::FileOutputStream::shutDown() {
	if (mIdentifier == INVALID_IDENTIFIER) {
		//cast an exception
		throw IllegalStreamException();
	}

	flush();
	close(mIdentifier);
	mIdentifier = INVALID_IDENTIFIER;
	mClosed = true;
}

void File::FileOutputStream::flush() {
	fsync(mIdentifier);
}

Reference File::FileOutputStream::getPath() {
	return mPath;
}

File::FileOutputStream::~FileOutputStream() {
	if (!isClosed()) {
		flush();
		close(mIdentifier);
	}
}

type_t File::FileOutputStream::type() {
	return CLASS_SERIAL;
}

bool File::FileOutputStream::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || OutputStream::instanceof(type);
}

} /* namespace io */
} /* namespace tl */
