/*
 * Vector.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VECTOR_H_
#define SRC_ADVANCED_MATH_VECTOR_H_

#include "AbstractMatrix.h"
#include "vec_func.h"

namespace tl {
namespace advanced {
namespace math {

enum VECTOR_TYPE {
	VECTOR_1, VECTOR_2, VECTOR_3, VECTOR_4
};

class Vector: public AbstractMatrix {
private:
	const static type_t CLASS_SERIAL = 78;

public:

	Vector();
	virtual ~Vector();
	Vector(const Vector &other) = delete;
	Vector& operator=(const Vector &other) = delete;
	virtual tlint size() = 0;
	virtual float get(tlint) = 0;
	virtual void set(tlint, float) = 0;
	virtual tlint maxIndex() = 0;
	virtual tlint minIndex() = 0;
	virtual VECTOR_TYPE vectorType() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_VECTOR_H_ */
