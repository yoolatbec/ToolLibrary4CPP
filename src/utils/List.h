/*
 * List.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_LIST_H_
#define SRC_UTILS_LIST_H_

#include "../lang/Reference.h"


namespace tl {
namespace utils {

class List: public lang::Object {
	using tl::lang::Reference;
protected:
	Reference* mElement;
	const hash_t mElementType;
	size_t mSize;
	size_t mCapacity;
public:
	explicit List(hash_t);
	List(hash_t, size_t reserved);
	List(const List&);
	virtual List& operator=(const List&) = delete;
	virtual ~List();
	virtual bool add(const Reference&) = 0;
	virtual bool addAll(const List&) = 0;
	virtual bool insert(const Reference&, size_t position) = 0;
	virtual bool insertAll(const List&, size_t) = 0;
	virtual bool remove(size_t) = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual bool replace(Reference, size_t) = 0;
	virtual Reference sort(bool (*)(byte*, byte*)) = 0;
	virtual Reference each(Reference (*)(const byte*)) = 0;
	virtual void each(void (*)(const byte*)) = 0;
	size_t getCapacity() const;
	size_t getSize() const;
	hash_t elementType() const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LIST_H_ */
