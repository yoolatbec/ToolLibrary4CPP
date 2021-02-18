/*
 * MatrixFactory.h
 *
 *  Created on: Jan 7, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MATRIXFACTORY_H_
#define SRC_ADVANCED_MATH_MATRIXFACTORY_H_

#include "../../lang/Reference.h"

#include "Mat4x4.h"
#include "Vec4.h"
#include "Vec3.h"
#include "Vec2.h"
#include "Vec.h"

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using Matrix::MATRIX_TYPE;

class MatrixFactory: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 129;

	const static MATRIX_TYPE MATRIX_MAP[][] = { {
		MATRIX_TYPE::MATRIX_1X1,
		MATRIX_TYPE::MATRIX_1X2,
		MATRIX_TYPE::MATRIX_1X3,
		MATRIX_TYPE::MATRIX_1X4 }, {
		MATRIX_TYPE::MATRIX_2X1,
		MATRIX_TYPE::MATRIX_2X2,
		MATRIX_TYPE::MATRIX_2X3,
		MATRIX_TYPE::MATRIX_2X4 }, {
		MATRIX_TYPE::MATRIX_3X1,
		MATRIX_TYPE::MATRIX_3X2,
		MATRIX_TYPE::MATRIX_3X3,
		MATRIX_TYPE::MATRIX_3X4 }, {
		MATRIX_TYPE::MATRIX_4X1,
		MATRIX_TYPE::MATRIX_4X2,
		MATRIX_TYPE::MATRIX_4X3,
		MATRIX_TYPE::MATRIX_4X4 } };

	MatrixFactory();
	static bool additionCapable(Reference, Reference);
	static bool multiplicationCapable(Reference, Reference);
	static bool dotCapable(Reference, Reference);

	static Reference matrixMultiply(Reference, float);

	static float dot_vec4(vec4, vec4);
	static float dot_vec3(vec3, vec3);
	static float dot_vec2(vec2, vec2);
	static float dot_vec(vec, vec);

	static vec4 add0(vec4, vec4);
	static vec3 add0(vec3, vec3);
	static vec2 add0(vec2, vec2);
	static vec add0(vec, vec);

	static vec4 negate0(vec4);
	static vec3 negate0(vec3);
	static vec2 negate0(vec2);
	static vec negate0(vec);

	static vec4 multiply0(vec4, float);
	static vec3 multiply0(vec3, float);
	static vec2 multiply0(vec2, float);
	static vec multiply0(vec, float);

	static Reference newMatrix(tlint, tlint);
	static Reference newMatrix(MATRIX_TYPE);
public:
	MatrixFactory(const MatrixFactory &other) = delete;
	MatrixFactory& operator=(const MatrixFactory &other) = delete;
	static Reference multiply(Reference, Reference);
	static Reference multiply(Reference, float);
	static float dot(Reference, Reference);
	static Reference cross(Reference, Reference);
	static Reference add(Reference, Reference);
	static Reference minus(Reference, Reference);
	static Reference negate(Reference);
	static Reference normalize(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MATRIXFACTORY_H_ */
