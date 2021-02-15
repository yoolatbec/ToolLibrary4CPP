/*
 * Vec2.h
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VEC2_H_
#define SRC_ADVANCED_MATH_VEC2_H_

#include "Vector.h"

namespace tl {
namespace advanced {
namespace math {

class Vec2: public virtual Vector {
private:
	const static type_t CLASS_SERIAL = 100;
	const static tlint COMPONENT_COUNT = 2;
	vec2 mValue;
public:
	Vec2(float = 0, float = 0);
	Vec2(vec2);
	virtual ~Vec2();
	Vec2(const Vec2 &other) = delete;
	Vec2& operator=(const Vec2 &other) = delete;
	float get(tlint);
	tlint size();
	vec2 values();
	void set(tlint, float);
	void set(vec2);
	void set(Reference);
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_VEC2_H_ */
