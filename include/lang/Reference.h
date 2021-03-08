/*
 * Reference.h
 *
 *  Created on: Sep 18, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_REFERENCE_H_
#define INCLUDE_LANG_REFERENCE_H_

#include <lang/Object.h>

namespace tl {
namespace lang {
/*
 * Reference encapsulates pointers to instances of other classes so that programmer
 * need not to manually manage memory. To free a piece of allocated memory encapsulated by
 * Reference instance, assign a new Reference instance created without argument passed to it.
 * Copies between Reference instances won't duplicate encapsulated instance. Instead, they share
 * the pointer to the instance and increase the reference count. While one Reference instance fades,
 * it will decrease the reference count while the reference count is greater than one. Otherwise, it frees
 * the allocated memory.
 * A Reference instance created without argument, actually nullptr passed as argument by default, works as nullptr in cpp or null in java.
 * That means no instance pointer is referred by the instance, so no method should be called by the referred pointer.
 * Use method isNull() to judge whether an instance hold a pointer to nullptr.
 * Remember that once an instance pointer is managed by a Reference instance, it should ever be managed by the
 * Reference instance.
 * Never use a single pointer to newly allocated memory region to initialize multiple Reference instances, because they may differ in reference counts
 * to the memory region and then cause memory fault.
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
	 * the pointer to an instance which is in form of allocated memory or to nullptr by default
	 */
	Object *mEntity;

	/*
	 * When the instance fades, whether or not free the instance referred to.
	 * true to free while false will not free.
	 */
	bool mAutoFree;
public:
	/*
	 * Default constructor, nullptr as default argument.
	 * if autoFree is given true, when the Reference instance fades, the
	 * instance referred to will be freed.
	 * autoFree is given false only when an instance referred to should not be freed
	 * too early or the Reference instance is encapsulate pointer 'this'.
	 */
	explicit Reference(Object* entity = nullptr, bool autoFree = true);
	/*
	 * The destructor will make sure the memory is appropriately deallocated.
	 */
	~Reference();

	/*
	 * Copy constructor. It won't duplicate any allocated memory. Instead, it shares the pointer to the
	 * allocated memory between the existing Reference instance and the new Reference instance. The reference
	 * count of the instance will increase by 1. However, if the capsulated pointer owns a value of nullptr,
	 * the new Reference instance shares value nullptr but won't create a reference count variable, therefore no increase.
	 */
	Reference(const Reference& other);

	/*
	 * Assignment operator. Copy the reference pointer from the existing Reference instance to the caller Reference
	 * instance and increase the reference count by 1. Before that memory deallocation may happen if the reference count
	 * equals 1, which means the caller Reference instance is the only instance referring to the memory so that it's
	 * accountable to free the memory.
	 */
	Reference& operator=(Reference other);

	/*
	 * Return the referred pointer to instance. While using the returned pointer, type cast may be necessary. It's better to
	 * use dynamic cast for the instance may be an instance of a class which extends multiple classes virtually.
	 * May nullptr when is initialized by default or manually set as reference to nullptr.
	 */
	Object* getEntity() const;

	/*
	 * Return the class identifier of the referred instance. Will cast an exception when referring to nullptr.
	 */
	type_t entityType() const;

	/*
	 * Judge whether two Reference instance refer to the same instance. Return true if so.
	 */
	bool equals(Reference) const;

	/*
	 * Return true if referring to nullptr.
	 */
	bool isNull() const;
	static type_t type();
	virtual bool instanceof(type_t) const;
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_REFERENCE_H_ */
