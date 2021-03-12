/*
 * MatrixFactory.h
 *
 *  Created on: Jan 7, 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_ADVANCED_MATH_MATRIXFACTORY_H_
#define INCLUDE_ADVANCED_MATH_MATRIXFACTORY_H_

#include <tl/advanced/math/Matrix.h>
#include <tl/advanced/math/Vector.h>
#include <tl/lang/Reference.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;

class MatrixFactory: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 129;

	constexpr const static MATRIX_TYPE MATRIX_MAP[4][4] =
		{
			{ MATRIX_1X1, MATRIX_1X2, MATRIX_1X3, MATRIX_1X4 },
				{ MATRIX_2X1, MATRIX_2X2, MATRIX_2X3, MATRIX_2X4 },
				{ MATRIX_3X1, MATRIX_3X2, MATRIX_3X3, MATRIX_3X4 },
				{ MATRIX_4X1, MATRIX_4X2, MATRIX_4X3, MATRIX_4X4 } };

	MatrixFactory();
	static float dot_vec4(vec4, vec4);
	static float dot_vec3(vec3, vec3);
	static float dot_vec2(vec2, vec2);
	static float dot_vec(vec, vec);

	static vec3 cross_vec3(vec3, vec3);

	static vec4 add0(vec4, vec4);
	static vec3 add0(vec3, vec3);
	static vec2 add0(vec2, vec2);
	static vec add0(vec, vec);

	static vec4 scale0(vec4, float);
	static vec3 scale0(vec3, float);
	static vec2 scale0(vec2, float);
	static vec scale0(vec, float);

	static Reference mScale0(Reference, float);
	static Reference vScale0(Reference, float);
	static Reference mmMultiply0(Reference, Reference);
	static Reference mvMultiply0(Reference, Reference);
	static Reference vmMultiply0(Reference, Reference);

	static Reference vAdd0(Reference, Reference);
	static Reference mAdd0(Reference, Reference);

	static Reference vMinus0(Reference, Reference);
	static Reference mMinus0(Reference, Reference);

	static Reference newMatrix(tlint, tlint);
	static Reference newMatrix(MATRIX_TYPE);

	static Reference newVector(tlint);
	static Reference newVector(VECTOR_TYPE);
public:
	MatrixFactory(const MatrixFactory &other) = delete;
	MatrixFactory& operator=(const MatrixFactory &other) = delete;
	static Reference multiply(Reference, Reference);
	static Reference scale(Reference, float);
	static float dot(Reference, Reference);
	static Reference cross(Reference, Reference);
	static Reference add(Reference, Reference);
	static Reference minus(Reference, Reference);
	static Reference normalize(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* INCLUDE_ADVANCED_MATH_MATRIXFACTORY_H_ */
