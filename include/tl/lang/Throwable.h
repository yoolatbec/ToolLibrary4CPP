/*
 * Throwable.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef TL_LANG_THROWABLE_H_
#define TL_LANG_THROWABLE_H_

#include <tl/lang/Object.h>

namespace tl {
namespace lang {

class Throwable: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 110;
protected:
	Throwable();
public:
	virtual ~Throwable();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* TL_LANG_THROWABLE_H_ */
