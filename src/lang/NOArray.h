/*
 * NOArray.h
 *
 *  Created on: Jan 8, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_NOARRAY_H_
#define SRC_LANG_NOARRAY_H_

#include "Cloneable.h"
#include "Integer.h"

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
	const tlint mSize;

	void parameterCheck(tlint);
	void boundCheck(tlint);
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

#endif /* SRC_LANG_NOARRAY_H_ */
