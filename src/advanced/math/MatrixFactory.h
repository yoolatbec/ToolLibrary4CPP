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

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using AbstractMatrix::MATRIX_TYPE;

class MatrixFactory: public lang::Object {
private:
	const static type_t CLASS_SERIAL = 129;

	MatrixFactory();
	static bool additionCapable(Reference, Reference);
	static bool multiplicationCapable(Reference, Reference);
	static bool dotCapable(Reference, Reference);

public:
	MatrixFactory(const MatrixFactory &other) = delete;
	MatrixFactory& operator=(const MatrixFactory &other) = delete;
	static Reference multiply(Reference, Reference);
	static Reference multiply(Reference, float);
	static Reference dot(Reference, Reference);
	static Reference cross(Reference, Reference);
	static Reference add(Reference, Reference);
	static Reference minus(Reference, Reference);
	static Reference negate(Reference);
	static Reference newMatrix(tlint, tlint);
	static Reference newMatrix(MATRIX_TYPE);
	static Reference newVector(Reference);
	static Reference matrixRowValue(Reference, tlint, Reference);
	static Reference matrixColumnValue(Reference, tlint, Reference);
	static Reference normalize(Reference);
	static Reference newIdenticalMatrix(tlint);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MATRIXFACTORY_H_ */
