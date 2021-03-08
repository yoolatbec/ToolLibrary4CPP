/*
 * NullPointerException.h
 *
 *  Created on: Mar 7, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_NULLPOINTEREXCEPTION_H_
#define INCLUDE_LANG_NULLPOINTEREXCEPTION_H_

#include <lang/Exception.h>

namespace tl {
namespace lang {

class NullPointerException: public virtual Exception {
public:
	NullPointerException();
	virtual ~NullPointerException();
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_NULLPOINTEREXCEPTION_H_ */
