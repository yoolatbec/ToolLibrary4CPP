/*
 * Set.h
 *
 *  Created on: Apr 24, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_SET_H_
#define TL_UTILS_SET_H_

#include <tl/utils/Collection.h>

namespace tl {
namespace utils {

using lang::Reference;

class Set: public virtual Collection {
private:
	const static type_t CLASS_SERIAL = 1042;
protected:
	Set(type_t);
public:
	virtual ~Set();
	Set(const Set &other) = delete;
	Set& operator=(const Set &other) = delete;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_SET_H_ */
