/*
 * OutputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_OUTPUTSTREAM_H_
#define TL_IO_OUTPUTSTREAM_H_

#include <tl/lang/Object.h>

namespace tl {
namespace io {

using lang::Reference;

class OutputStream: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 249;

protected:
	const static tlint DEFAULT_BUFFER_SIZE = 4096;

	byte* mBuffer;
	tlint mBufferSize;

	OutputStream();
	OutputStream(tlint);
public:
	virtual ~OutputStream();
	OutputStream(const OutputStream &other) = delete;
	OutputStream& operator=(const OutputStream &other) = delete;
	tlint bufferSize();
	bool isBuffered();
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
