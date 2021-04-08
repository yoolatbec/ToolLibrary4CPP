/*
 * Collection.h
 *
 *  Created on: Nov 9, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_COLLECTION_H_
#define INCLUDE_UTILS_COLLECTION_H_

#include <tl/utils/Iterable.h>
#include "../lang/Reference.h"

namespace tl {
namespace utils {

using lang::Reference;

class Collection: public virtual Iterable {
private:
	const static type_t CLASS_SERIAL = 10;
protected:
	const type_t mElementType;
	tlint mSize;
	explicit Collection(type_t);
public:
	virtual ~Collection();
	Collection(const Collection &other) = delete;
	Collection& operator=(const Collection &other) = delete;
	virtual bool add(Reference) = 0;
	virtual bool addAll(Reference) = 0;
	virtual bool contains(Reference) = 0;
	virtual bool containsAll(Reference) = 0;
	virtual Reference iterator() = 0;
	virtual bool remove(Reference) = 0;
	virtual bool removeAll(Reference) = 0;
	virtual void clear() = 0;
	virtual Reference toArray() = 0;
	virtual tlint size();
	virtual type_t elementType();
	virtual bool isEmpty();
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_COLLECTION_H_ */
