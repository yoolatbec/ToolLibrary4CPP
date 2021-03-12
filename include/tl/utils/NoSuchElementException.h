/*
 * NoSuchElementException.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_NOSUCHELEMENTEXCEPTION_H_
#define TL_UTILS_NOSUCHELEMENTEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace utils {

using lang::Reference;

class NoSuchElementException: public virtual lang::Exception {
private:
	const static type_t CLASS_SERIAL = 25;
	const static constexpr char *DEFAULT_MESSAGE = "NoSuchElementException:";
	static Reference sDefaultMessage;
public:
	NoSuchElementException();
	NoSuchElementException(const char*);
	virtual ~NoSuchElementException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_NOSUCHELEMENTEXCEPTION_H_ */
