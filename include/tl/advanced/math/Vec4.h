/*
 * Vec4.h
 *
 *  Created on: Jan 17, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_VEC4_H_
#define INCLUDE_ADVANCED_MATH_VEC4_H_

#include <tl/advanced/math/Vector.h>

namespace tl {
namespace advanced {
namespace math {

class Vec4: virtual public Vector {
private:
	const static type_t CLASS_SERIAL = 90;
	const static tlint COMPONENT_COUNT = 4;
	const static VectorType VECTOR_TYPE_VALUE = VECTOR_4;
	const static tlint MAX_INDEX = 3;
	const static tlint MIN_INDEX = 0;

	vec4 mValue;

public:
	/*
	 * Create a new instance and initialise elements to the given value
	 */
	Vec4(float = 0, float = 0, float = 0, float = 0);
	Vec4(vec4);
	/*
	 * Create a new instance by an given Vector instance or FloatArray instance.
	 * If a Vector instance is given, the n-th element will be initialised the same
	 * as the n-th element of the given Vector instance, where n can be 1, 2, 3, 4.
	 * If the given Vector instance has less elements than the newly created instance,
	 * the elements remained of the newly created instance will be initialised to 0.
	 * If a FloatArray instance is given, the action occurs in the same way.
	 */
	virtual ~Vec4();
	Vec4(const Vec4 &other) = delete;
	Vec4& operator=(const Vec4 &other) = delete;
	/*
	 * Always return 4 since this is a vector of 4 elements.
	 */
	tlint size();
	float get(tlint);
	void set(tlint, float);
	void set(vec4);
	tlint maxIndex();
	tlint minIndex();

	/*
	 * Modify values of elements. Only instances of Vector or FloatArray can be given.
	 */
	Reference toString();
	vec4 values();
	VectorType vectorType();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_VEC4_H_ */
