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
	const static type_t CLASS_SERIAL = 1;
	size_t *mRef;
	Object *mEntity;
public:
	Reference(Object* entity = nullptr);
	~Reference();
	Reference(Reference other);
	Reference& operator=(Reference other);
	Object* getEntity();
	type_t entityType() const;
	bool equals(Reference) const;
	bool isNull() const;
	static type_t type();
	virtual bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_REFERENCE_H_ */
