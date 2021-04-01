/*
 * Pointer.h
 *
 *  Created on: Feb 25, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_POINTER_H_
#define INCLUDE_LANG_POINTER_H_

#include <tl/lang/Object.h>

namespace tl {
namespace lang {

class Pointer: public virtual Object {
private:
	const static type_t CLASS_SERIAL = 11;

	void* const mPointer;
	tlint64 mLength;
public:
	Pointer(void*, tlint64);
	virtual ~Pointer();
	Pointer(const Pointer &other) = delete;
	Pointer& operator=(const Pointer &other) = delete;
	tlint64 length();
	void* get();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_POINTER_H_ */
