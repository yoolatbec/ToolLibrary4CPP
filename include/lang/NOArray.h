/*
 * NOArray.h
 *
 *  Created on: Jan 8, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_NOARRAY_H_
#define INCLUDE_LANG_NOARRAY_H_

#include <lang/Cloneable.h>
#include <lang/Integer.h>

namespace tl {
namespace lang {

/*
 * NOArray means Array of Non-object.
 */
class NOArray: public Cloneable {
private:
	static const tlint MAX_SIZE = Integer::MAX_VALUE;
	static const type_t CLASS_SERIAL = 32;

protected:
	const static tlint DEFAULT_SIZE = 10;

	const tlint mSize;

	void indexBoundCheck(tlint);
	NOArray(tlint);

public:
	NOArray(const NOArray &other) = delete;
	NOArray& operator=(const NOArray &other) = delete;
	tlint size();
	Reference toString() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_NOARRAY_H_ */
