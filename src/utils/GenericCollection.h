/*
 * GenericCollection.h
 *
 *  Created on: 2020Äê11ÔÂ10ÈÕ
 *      Author: Yoolatbec
 */

#ifndef SRC_UTILS_GENERICCOLLECTION_H_
#define SRC_UTILS_GENERICCOLLECTION_H_

#include "../lang/Object.h"

namespace tl {
namespace utils {

class GenericCollection: public virtual tl::lang::Object {
private:
	const static hash_t CLASS_HASH = 20L << 32;
protected:
	size_t mSize;
public:
	GenericCollection();
	virtual ~GenericCollection();
	GenericCollection& operator=(const GenericCollection &other) = delete;
	GenericCollection(const GenericCollection &other) = delete;
	static hash_t getType();
	bool instanceof(hash_t) const;
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_GENERICCOLLECTION_H_ */
