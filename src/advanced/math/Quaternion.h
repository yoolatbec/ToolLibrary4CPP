/*
 * Quaternion.h
 *
 *  Created on: Mar 20, 2021
 *      Author: yoolatbec
 */

#ifndef ADVANCED_MATH_QUATERNION_H_
#define ADVANCED_MATH_QUATERNION_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace advanced {
namespace math {

struct quaternion {
	float x;
	float y;
	float z;
	float w;
};

using lang::Reference;

class Quaternion: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 483;
	constexpr const static float DEFAULT_VALUE = 0;
	const static constexpr float INVERSE_CRITICAL_VALUE = 0.005;

	quaternion mValue;
	quaternion mConjugate;
	quaternion mInverse;
	float mModulus;

	float computeModulus();
	quaternion conjugate0();
	quaternion inverse0();

	void update();
public:
	const static tlint MAX_COMPONENT_INDEX = 4;
	const static tlint MIN_COMPONENT_INDEX = 0;

	Quaternion(float = DEFAULT_VALUE, float = DEFAULT_VALUE, float =
		DEFAULT_VALUE, float = DEFAULT_VALUE);
	Quaternion(quaternion);
	virtual ~Quaternion();
	Quaternion(const Quaternion &other) = delete;
	Quaternion& operator=(const Quaternion &other) = delete;
	quaternion values();
	Reference inverse();
	Reference conjugate();
	float value(tlint);
	float modulus();
	Reference sgn();
	float arg();
	bool invertible();
	static Reference straightMultiply(Reference, Reference);
	static Reference add(Reference, Reference);
	static Reference minus(Reference, Reference);
	static float dot(Reference, Reference);
	static Reference outer(Reference, Reference);
	static Reference even(Reference, Reference);
	static Reference cross(Reference, Reference);
	static Reference scale(Reference, float);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* ADVANCED_MATH_QUATERNION_H_ */
