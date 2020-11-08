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

class String;
class Object {
private:
	const static hash_t CLASS_HASH = 0L << 32;
protected:
	hash_t mHash;
public:
	const static hash_t INSTANCE_MASK = 0xFFFFFFFFL;
	const static hash_t CLASS_MASK = 0xFFFFFFFFL << 32;

protected:
	virtual hash_t genHash();
public:
	const static Object null;
	Object();
	Object(const Object* other);
	Object(const Object&) = delete;
	virtual Object& operator=(const Object&);
	virtual ~Object();
	virtual bool equals(const Object*) const;
	virtual bool operator==(const Object*) const;
	virtual Object* clone() const;
	String* toString() const;
	bool instanceof(hash_t) const;
	hash_t type() const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_OBJECT_H_ */
