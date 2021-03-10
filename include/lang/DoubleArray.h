/*
 * DoubleArray.h
 *
 *  Created on: Mar 8, 2021
 *      Author: yoolatbec
 */

#ifndef LANG_DOUBLEARRAY_H_
#define LANG_DOUBLEARRAY_H_

#include <lang/NOArray.h>

namespace tl {
namespace lang {

class DoubleArray final : public virtual NOArray {
private:
	const static type_t CLASS_SERIAL = 50;
	const static tlint RESERVED_WIDTH_FOR_EACH_BIT = 20;
	constexpr const static double DEFAULT_VALUE = 0;

	double* mElements;

	DoubleArray(tlint, double);
	DoubleArray(tlint, double*);

	static void initParameterCheck(tlint);
public:
	virtual ~DoubleArray();
	DoubleArray(const DoubleArray &other) = delete;
	DoubleArray& operator=(const DoubleArray &other) = delete;
	static Reference newInstance(tlint = NOArray::DEFAULT_SIZE, double = DEFAULT_VALUE);
	static Reference newInstance(tlint, double*);
	Reference clone();
	void set(tlint, double);
	double get(tlint);
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace lang */
} /* namespace tl */

#endif /* LANG_DOUBLEARRAY_H_ */
