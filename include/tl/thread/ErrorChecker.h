/*
 * ErrorChecker.h
 *
 *  Created on: Mar 16, 2021
 *      Author: yoolatbec
 */

#ifndef TL_THREAD_ERRORCHECKER_H_
#define TL_THREAD_ERRORCHECKER_H_

#include <tl/lang/Object.h>

namespace tl {
namespace thread {

class ErrorChecker: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 810;
	ErrorChecker();
public:
	virtual ~ErrorChecker();
	ErrorChecker(const ErrorChecker &other) = delete;
	ErrorChecker& operator=(const ErrorChecker &other) = delete;
	static void check(tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace thread */
} /* namespace tl */

#endif /* TL_THREAD_ERRORCHECKER_H_ */
