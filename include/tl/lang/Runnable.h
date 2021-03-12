/*
 * Runnable.h
 *
 *  Created on: Feb 4, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_RUNNABLE_H_
#define INCLUDE_LANG_RUNNABLE_H_

#include <pthread.h>
#include <tl/lang/Object.h>

namespace tl {
namespace lang {

class Runnable: public Object {
private:
	const static type_t CLASS_SERIAL = 10;
public:
	Runnable();
	virtual ~Runnable();
	Runnable(const Runnable &other) = delete;
	Runnable& operator=(const Runnable &other) = delete;
	virtual void run() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_RUNNABLE_H_ */
