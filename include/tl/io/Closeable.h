/*
 * Closeable.h
 *
 *  Created on: Apr 1, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_CLOSEABLE_H_
#define TL_IO_CLOSEABLE_H_

#include <tl/lang/Object.h>

namespace tl {
namespace io {

class Closeable: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 234;
protected:
	bool mClosed;

	Closeable();
public:
	virtual ~Closeable();
	Closeable(const Closeable &other) = delete;
	Closeable& operator=(const Closeable &other) = delete;
	virtual void close() = 0;
	bool isClosed();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_CLOSEABLE_H_ */
