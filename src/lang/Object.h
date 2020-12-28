/*
 * Object.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_OBJECT_H_
#define SRC_LANG_OBJECT_H_

#include "../tl_def.h"

namespace tl {
namespace lang {

class Reference;
class String;

class Object {
private:
	const static type_t CLASS_SERIAL = 0;
protected:
	hash_t mHashCode;
public:

protected:
	virtual hash_t genHashCode(type_t);
public:
	Object();
	Object(const Object&) = delete;
	virtual Object& operator=(const Object&) = delete;
	virtual ~Object();
	virtual bool equals(Reference);
	virtual bool operator==(Reference);
	virtual Reference clone();
	virtual Reference toString();
	virtual bool instanceof(type_t) const;
	static type_t type();
	hash_t hashCode();
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_OBJECT_H_ */
