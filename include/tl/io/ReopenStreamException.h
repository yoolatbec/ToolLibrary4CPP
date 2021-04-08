/*
 * ReopenStreamException.h
 *
 *  Created on: Mar 28, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_REOPENSTREAMEXCEPTION_H_
#define TL_IO_REOPENSTREAMEXCEPTION_H_

#include <tl/io/IOException.h>

namespace tl {
namespace io {

class ReopenStreamException: public virtual IOException {
private:
	const static type_t CLASS_SERIAL = 3546;
	const static constexpr char *DEFAULT_MESSAGE = "ReopenStreamException:";
	static Reference sDefaultMessage;
public:
	ReopenStreamException();
	ReopenStreamException(const char*);
	virtual ~ReopenStreamException();
	type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_REOPENSTREAMEXCEPTION_H_ */
