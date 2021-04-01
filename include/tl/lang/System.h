/*
 * System.h
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_SYSTEM_H_
#define TL_LANG_SYSTEM_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace lang {

class System: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 2498;

	static Reference sSystemMutex;
	System();
public:
	virtual ~System();
	System(const System &other) = delete;
	System& operator=(const System &other) = delete;
	static void systemMutexLock();
	static void systemMutexUnlock();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_SYSTEM_H_ */
