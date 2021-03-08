/*
 * FloatArray.h
 *
 *  Created on: Jan 14, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_LANG_FLOATARRAY_H_
#define INCLUDE_LANG_FLOATARRAY_H_

#include <lang/NOArray.h>

namespace tl {
namespace lang {

class FloatArray: public virtual NOArray {
private:
	static const type_t CLASS_SERIAL = 33;
	const static tlint RESERVED_WIDTH_FOR_EACH_BIT = 20;
	constexpr const static float DEFAULT_INIT_VALUE = 0;

	float* mElements;

	/*
	 * For the sake of parameter check, make the constructor private.
	 */
	FloatArray(tlint, float*);
	FloatArray(tlint, float);

	static void initParameterCheck(tlint);

public:
	virtual ~FloatArray();
	FloatArray(const FloatArray &other) = delete;
	FloatArray& operator=(const FloatArray &other) = delete;
	static Reference newFloatArray(tlint = NOArray::DEFAULT_SIZE);
	static Reference newFloatArray(tlint, float*);
	static Reference newFloatArray(tlint, float);
	Reference clone();
	float get(tlint);
	void set(tlint, float);
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* INCLUDE_LANG_FLOATARRAY_H_ */
