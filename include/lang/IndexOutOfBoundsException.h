/*
 * IndexOutOfBoundsException.h
 *
 *  Created on: Mar 6, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_INDEXOUTOFBOUNDSEXCEPTION_H_
#define INCLUDE_LANG_INDEXOUTOFBOUNDSEXCEPTION_H_

#include <lang/Exception.h>

namespace tl {
namespace lang {

class IndexOutOfBoundsException: public virtual Exception {
public:
	IndexOutOfBoundsException();
	virtual ~IndexOutOfBoundsException();
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_INDEXOUTOFBOUNDSEXCEPTION_H_ */
