/*
 * Reference.h
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_REFERENCE_H_
#define SRC_LANG_REFERENCE_H_

#include "Object.h"

namespace tl {
namespace lang {

class Reference: public lang::Object {
private:
	const static hash_t CLASS_HASH = 1L << 32;
	size_t *mRef;
	Object *mEntity;
public:
	Reference(Object* entity = nullptr);
	~Reference();
	Reference(const Reference &other);
	Reference& operator=(const Reference &other);
	hash_t getType() const;
	Object* getEntity() const;
	bool equals(const Reference&) const;
	bool isNull() const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_REFERENCE_H_ */
