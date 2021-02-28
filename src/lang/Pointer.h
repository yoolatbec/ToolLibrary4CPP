/*
 * Pointer.h
 *
 *  Created on: Feb 25, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_POINTER_H_
#define SRC_LANG_POINTER_H_

#include "Object.h"

namespace tl {
namespace lang {

class Pointer: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 11;

	const void* mPointer;
public:
	explicit Pointer(void*);
	virtual ~Pointer();
	Pointer(const Pointer &other) = delete;
	Pointer& operator=(const Pointer &other) = delete;
	void* get();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_POINTER_H_ */
