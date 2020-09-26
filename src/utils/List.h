/*
 * List.h
 *
 *  Created on: Sep 9, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_LIST_H_
#define SRC_UTILS_LIST_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class List: public lang::Object {
private:
	byte* mElements;
	size_t mUsed;
	size_t mCapacity;
	size_t mElementSize;
public:
	explicit List(size_t element_size);
	List(size_t element_size, size_t reserved);
	List(const List&);
	virtual List& operator=(List&);
	virtual ~List();
	virtual bool add(byte*) = 0;
	virtual bool addAll(const List&) = 0;
	virtual bool insert(byte*, size_t) = 0;
	virtual bool insertAll(const List&, size_t) = 0;
	virtual bool remove(size_t) = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual bool replace(byte*, size_t) = 0;
	virtual Object sort(bool (*)(byte*, byte*)) = 0;
	virtual Object each(byte* (*)(const byte*)) = 0;
	virtual void each(void (*)(const byte*)) = 0;
	size_t getCapacity() const;
	size_t getUsed() const;
	size_t getElementSize() const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_LIST_H_ */
