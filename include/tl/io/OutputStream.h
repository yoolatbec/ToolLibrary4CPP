/*
 * OutputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_OUTPUTSTREAM_H_
#define TL_IO_OUTPUTSTREAM_H_

#include <tl/io/Closeable.h>

namespace tl {
namespace io {

using lang::Reference;

class OutputStream: public virtual Closeable {
private:
	const static type_t CLASS_SERIAL = 249;


protected:
	const static tlint DEFAULT_BUFFER_SIZE = 4096;
	const static tlint INVALID_IDENTIFIER = -1;
	const static tlint UNSUCCESS_WRITE = -1;

	OutputStream();
public:
	virtual ~OutputStream();
	OutputStream(const OutputStream &other) = delete;
	OutputStream& operator=(const OutputStream &other) = delete;
	virtual void flush();
	virtual void writen(Reference, tlint);
	virtual void writeAll(Reference);
	virtual void writeByte(byte);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_OUTPUTSTREAM_H_ */
