/*
 * IOException.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_IO_IOEXCEPTION_H_
#define TL_IO_IOEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace io {

using lang::Reference;

class IOException: public lang::Exception {
private:
	const static type_t CLASS_SERIAL = 2487;
	const static constexpr char *DEFAULT_MESSAGE = "IOException:";
	static Reference sDefaultMessage;
public:
	IOException();
	IOException(const char*);
	virtual ~IOException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace io */
} /* namespace tl */

#endif /* TL_IO_IOEXCEPTION_H_ */
