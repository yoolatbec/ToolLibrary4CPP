/*
 * Collection.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_COLLECTION_H_
#define TL_UTILS_COLLECTION_H_

#include <tl/utils/Iterable.h>

namespace tl {
namespace utils {

class Collection: public virtual Iterable {
private:
	const static type_t CLASS_SERIAL = 1025;

protected:
	type_t mElementType;
	tlint mSize;

	Collection(type_t);
public:
	virtual ~Collection();
	Collection(const Collection &other) = delete;
	Collection& operator=(const Collection &other) = delete;
	virtual bool add(Reference);
	virtual bool addAll(Reference);
	virtual bool clear();
	virtual bool contains(Reference) = 0;
	virtual bool containsAll(Reference) = 0;
	virtual type_t elementType();
	virtual bool remove(Reference);
	virtual void removeAll(Reference);
	virtual Reference toArray() = 0;
	virtual bool isEmpty();
	virtual tlint size();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_COLLECTION_H_ */
