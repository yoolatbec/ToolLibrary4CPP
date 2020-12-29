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
/*
 * Reference capsulates pointers to instances of other classes so that programmer
 * need not to manually manage memory. To free a piece of allocated memory capsulated by
 * Reference instance, assign a new Reference instance created without argument passed to it.
 * Copies between Reference instances won't duplicate capsulated instance. Instead, they share
 * the pointer to the instance and increase the reference count. While one Reference instance fades,
 * it will decrease the reference count while the reference count is greater than one. Otherwise, it frees
 * the allocated memory.
 * A Reference instance created without argument, actually nullptr passed as argument by default, works as nullptr.
 * That means no instance pointer is referred by the instance, so no method can be called by the referred pointer.
 * Use method isNull() to judge whether an instance hold a pointer to nullptr.
 * Remember that once an instance pointer is managed by a Reference instance, it should ever be managed by the
 * Reference instance.
 */
class Reference: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 1;
	/*
	 * reference count, made as a pointer to size_t to make sure that every Reference instance
	 * share the reference count as sharing the instance.
	 */
	size_t *mRef;

	/*
	 * the pointer to an instance or to nullptr by default
	 */
	Object *mEntity;
public:
	/*
	 * Default constructor, nullptr as default argument.
	 */
	explicit Reference(Object* entity = nullptr);
	/*
	 * The destructor will make sure the memory is appropriately deallocated.
	 */
	~Reference();
	Reference(const Reference& other);
	Reference& operator=(Reference other);
	Object* getEntity() const;
	type_t entityType() const;
	bool equals(Reference) const;
	bool isNull() const;
	static type_t type();
	virtual bool instanceof(type_t) const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_REFERENCE_H_ */
