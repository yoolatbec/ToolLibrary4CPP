/*
 * File.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef IO_FILE_H_
#define IO_FILE_H_

#include "AbstractFile.h"
#include <tl/io/Streaming.h>
#include <sys/stat.h>
#include <tl/io/InputStream.h>
#include <tl/io/OutputStream.h>

namespace tl {
namespace io {

using lang::Reference;

class File: public virtual AbstractFile, public virtual Streaming {
private:
	const static type_t CLASS_SERIAL = 5389;
	const static tlint DEFAULT_ACCESS = S_IRUSR | S_IWUSR | S_IRGRP
		| S_IWGRP | S_IROTH;

	class FileInputStream: public virtual InputStream {
	private:
		const static type_t CLASS_SERIAL = 879;

		tlint mIdentifier;
	public:
		FileInputStream(tlint);
		tlint readn(tlint, Reference);
		Reference readAll();
		void skip(tlint64);
		void reset();
		void mark();
		void rewind();
		static type_t type();
		bool instanceof(type_t);
	};

	class FileOutputStream: public virtual OutputStream {
	private:
		const static type_t CLASS_SERIAL = 880;

		tlint mIdentifier;
	public:
		FileOutputStream(tlint);
		FileOutputStream(tlint identifier, tlint bufferSize);
		tlint writen(tlint, Reference);
		tlint writeAll(Reference);
		void flush();
	};

	Reference mMutex;
	bool mReading;
	bool mWriting;
public:
	File(Reference, bool append = true);
	File(Reference, Reference, bool append = true);
	virtual ~File();
	File(const File &other) = delete;
	File& operator=(const File &other) = delete;
	Reference openInputStream();
	Reference openInputStream(tlint);
	Reference openOutputStream();
	Reference openOutputStream(tlint);
	tlint64 length();
	bool canRead();
	bool canWrite();
	bool canExecute();
	static void newFile(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* IO_FILE_H_ */
