/*
 * InputStream.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_INPUTSTREAM_H_
#define TL_IO_INPUTSTREAM_H_

#include <tl/io/Closeable.h>

namespace tl {
namespace io {

using lang::Reference;

class InputStream: public virtual Closeable {
private:
	const static type_t CLASS_SERIAL = 183;

protected:
	const static tlint DEFAULT_BUFFER_SIZE = 4096;
	tlint64 mMarker;

	InputStream();
public:
	virtual ~InputStream();
	InputStream(const InputStream &other) = delete;
	InputStream& operator=(const InputStream &other) = delete;
	virtual tlint readn(Reference, tlint);
	virtual Reference readAll();
	virtual void skip(tlint64);
	virtual void mark();
	virtual void reset();
	virtual void rewind();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_INPUTSTREAM_H_ */
