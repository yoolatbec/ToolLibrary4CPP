/*
 * Vec4.h
 *
 *  Created on: Jan 17, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VEC4_H_
#define SRC_ADVANCED_MATH_VEC4_H_

#include "Vector.h"

namespace tl {
namespace advanced {
namespace math {

class Vec4: public Vector {
private:
	const static type_t CLASS_SERIAL = 90;
	const static tlint SIZE = 4;

public:
	/*
	 * Create a new instance and initialize all elements to the given value
	 */
	Vec4(float = 0);
	/*
	 * Create a new instance by an given Vector instance or FloatArray instance.
	 * If a Vector instance is given, the n-th element will be initialized the same
	 * as the n-th element of the given Vector instance, where n can be 1, 2, 3, 4.
	 * If the given Vector instance has less elements than the newly created instance,
	 * the elements remained of the newly created instance will be initialized to 0.
	 * If a FloatArray instance is given, the action occurs in the same way.
	 */
	Vec4(Reference);
	virtual ~Vec4();
	Vec4(const Vec4 &other) = delete;
	Vec4& operator=(const Vec4 &other) = delete;
	/*
	 * Always return 4 since this is a vector of 4 elements.
	 */
	tlint size();
	float get(tlint);
	void set(tlint, float);

	/*
	 * Modify values of elements. Only instances of Vector or FloatArray can be given.
	 */
	void set(Reference);
	tlint rowSize();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_VEC4_H_ */
