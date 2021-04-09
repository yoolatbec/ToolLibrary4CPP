/*
 * File.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_FILE_H_
#define TL_IO_FILE_H_

#include <tl/io/Streaming.h>
#include <sys/stat.h>
#include <tl/io/AbstractFile.h>
#include <tl/io/InputStream.h>
#include <tl/io/OutputStream.h>

namespace tl {
namespace io {

using lang::Reference;

class File: public virtual AbstractFile, public virtual Streaming {
private:
	const static type_t CLASS_SERIAL = 5389;
	const static tlint DEFAULT_ACCESS = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
		| S_IROTH;

	class FileInputStream: public virtual InputStream {
	private:
		const static type_t CLASS_SERIAL = 879;

		Reference mPath;
		tlint mIdentifier;
	public:
		FileInputStream(Reference);
		FileInputStream(const FileInputStream&) = delete;
		FileInputStream& operator=(const FileInputStream&) = delete;
		~FileInputStream();
		Reference getPath();
		tlint readn(tlint, Reference);
		Reference readAll();
		void skip(tlint64);
		void reset();
		void mark();
		void rewind();
		void shutDown();
		static type_t type();
		bool instanceof(type_t);
	};

	class FileOutputStream: public virtual OutputStream {
	private:
		const static type_t CLASS_SERIAL = 880;
		const static tlint DEFAULT_WRITE_ACCESS = S_IRUSR | S_IWUSR | S_IRGRP
			| S_IWGRP | S_IROTH;

		Reference mPath;
		tlint mIdentifier;
	public:
		FileOutputStream(Reference, bool);
		FileOutputStream(const FileOutputStream&) = delete;
		FileOutputStream& operator=(const FileOutputStream&) = delete;
		~FileOutputStream();
		Reference getPath();
		void writen(tlint, Reference);
		void writeAll(Reference);
		void writeByte(byte);
		void shutDown();
		void flush();
		static type_t type();
		bool instanceof(type_t);
	};

	Reference mMutex;
	bool mAppending;

public:
	File(Reference, bool append = true);
	File(Reference, Reference, bool append = true);
	virtual ~File();
	File(const File &other) = delete;
	File& operator=(const File &other) = delete;
	Reference openInputStream();
	Reference openOutputStream();
	tlint64 length();
	bool canRead();
	bool canWrite();
	bool canExecute();
	void remove();
	static bool isAbsolutePath(Reference);
	static void newFile(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_FILE_H_ */
