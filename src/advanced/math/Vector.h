/*
 * Vector.h
 *
 *  Created on: Jan 18, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VECTOR_H_
#define SRC_ADVANCED_MATH_VECTOR_H_

#include "AbstractMatrix.h"

namespace tl {
namespace advanced {
namespace math {

class Vector: public AbstractMatrix {
private:
	const static type_t CLASS_SERIAL = 78;

protected:
	Reference mElements;

public:
	Vector();
	virtual ~Vector();
	Vector(const Vector &other) = delete;
	Vector& operator=(const Vector &other) = delete;
	tlint size() = 0;
	float get(tlint) = 0;
	void set(tlint, float) = 0;
	void set(Reference) = 0;
	tlint columnSize();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_VECTOR_H_ */
