/*
 * UnacceptableArgumentException.h
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_UNACCEPTABLEARGUMENTEXCEPTION_H_
#define SRC_LANG_UNACCEPTABLEARGUMENTEXCEPTION_H_

#include "Exception.h"

namespace tl {
namespace lang {

class UnacceptableArgumentException: public virtual Exception {
public:
	UnacceptableArgumentException();
	virtual ~UnacceptableArgumentException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_UNACCEPTABLEARGUMENTEXCEPTION_H_ */
