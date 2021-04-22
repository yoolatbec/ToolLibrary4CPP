/*
 * Comparator.h
 *
 *  Created on: Apr 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_COMPARATOR_H_
#define TL_UTILS_COMPARATOR_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace utils {

using lang::Reference;

class Comparator: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 1034;
protected:
	Comparator();
public:
	virtual ~Comparator();
	Comparator(const Comparator &other) = delete;
	Comparator& operator=(const Comparator &other) = delete;
	virtual tlint compare(Reference, Reference) = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_COMPARATOR_H_ */
