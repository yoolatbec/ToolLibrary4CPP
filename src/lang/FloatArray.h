/*
 * FloatArray.h
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_LANG_FLOATARRAY_H_
#define SRC_LANG_FLOATARRAY_H_

#include "NOArray.h"

namespace tl {
namespace lang {

class FloatArray: public NOArray {
private:
	static const type_t CLASS_SERIAL = 33;

	float* mElements;

	FloatArray(tlint, float*);

public:
	virtual ~FloatArray();
	FloatArray(const FloatArray &other) = delete;
	FloatArray& operator=(const FloatArray &other) = delete;
	static Reference newFloatArray(tlint);
	static Reference newFloatArray(tlint, float*);
	Reference clone();
	float get(tlint);
	void set(tlint, float);
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* SRC_LANG_FLOATARRAY_H_ */
