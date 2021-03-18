/*
 * Vec.h
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_VEC_H_
#define INCLUDE_ADVANCED_MATH_VEC_H_

#include <tl/advanced/math/Vector.h>

namespace tl {
namespace advanced {
namespace math {

class Vec: public virtual Vector {
private:
	const static type_t CLASS_SERIAL = 101;
	const static tlint COMPONENT_COUNT = 1;
	const static tlint MAX_INDEX = 0;
	const static tlint MIN_INDEX = 0;
	const static VectorType VECTOR_TYPE_VALUE = VECTOR_1;
	vec mValue;

public:
	Vec(float = 0);
	Vec(vec);
	virtual ~Vec();
	Vec(const Vec &other) = delete;
	Vec& operator=(const Vec &other) = delete;
	tlint size();
	void set(tlint, float);
	void set(vec);
	float get(tlint);
	vec values();
	VectorType vectorType();
	tlint maxIndex();
	tlint minIndex();
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_VEC_H_ */
