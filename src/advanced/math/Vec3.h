/*
 * Vec3.h
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VEC3_H_
#define SRC_ADVANCED_MATH_VEC3_H_

#include "Vector.h"

namespace tl {
namespace advanced {
namespace math {

class Vec3: virtual public Vector {
private:
	const static type_t CLASS_SERIAL = 99;
	static const tlint COMPONENT_COUNT = 3;
	const static VECTOR_TYPE VECTOR_TYPE_VALUE = VECTOR_3;
	const static tlint MAX_INDEX = 2;
	const static tlint MIN_INDEX = 0;
	vec3 mValue;

public:
	Vec3(float = 0, float = 0, float = 0);
	Vec3(vec3);
	virtual ~Vec3();
	Vec3(const Vec3 &other) = delete;
	Vec3& operator=(const Vec3 &other) = delete;
	float get(tlint);
	tlint size();
	void set(vec3);
	void set(tlint, float);
	void set(Reference);
	Reference toString();
	vec3 values();
	VECTOR_TYPE vectorType();
	tlint maxIndex();
	tlint minIndex();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_VEC3_H_ */
