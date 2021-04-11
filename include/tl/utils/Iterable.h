/*
 * Iterable.h
 *
 *  Created on: Apr 9, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_ITERABLE_H_
#define TL_UTILS_ITERABLE_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class Iterable: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 1024;

protected:
	Iterable();
public:
	virtual ~Iterable();
	Iterable(const Iterable &other) = delete;
	Iterable& operator=(const Iterable &other) = delete;
	virtual Reference iterator() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_ITERABLE_H_ */
