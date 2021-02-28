/*
 * InvalidIteratorException.h
 *
 *  Created on: Feb 26, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_INVALIDITERATOREXCEPTION_H_
#define SRC_UTILS_INVALIDITERATOREXCEPTION_H_

#include "../lang/Exception.h"

namespace tl {
namespace utils {

using lang::Reference;

class InvalidIteratorException: public virtual lang::Exception {
private:
	const static type_t CLASS_SERIAL = 600;
public:
	InvalidIteratorException();
	InvalidIteratorException(Reference);
	InvalidIteratorException(const InvalidIteratorException&);
	virtual ~InvalidIteratorException();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_INVALIDITERATOREXCEPTION_H_ */
