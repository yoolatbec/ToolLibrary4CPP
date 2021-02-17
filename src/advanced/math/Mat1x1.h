/*
 * Mat1x1.h
 *
 *  Created on: Feb 16, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_MAT1X1_H_
#define SRC_ADVANCED_MATH_MAT1X1_H_

#include "SquareMatrix.h"

namespace tl {
namespace advanced {
namespace math {

class Mat1x1: public virtual SquareMatrix {
private:
	const static type_t CLASS_SERIAL = 114;
	const static MATRIX_TYPE MATRIX_ARRANGEMENT = MATRIX_1X1;
	const static tlint MAX_ROW_INDEX = 0;
	const static tlint MIN_ROW_INDEX = 0;
	const static tlint MAX_COLUMN_INDEX = 0;
	const static tlint MIN_COLUMMN_INDEX = 0;

	mat1x1 mValue;

	double computeDeterminant();
	Reference inverse0();
	void update();

public:
	Mat1x1();
	Mat1x1(mat1x1);
	virtual ~Mat1x1();
	Mat1x1(const Mat1x1 &other) = delete;
	Mat1x1& operator=(const Mat1x1 &other) = delete;
	bool invertible();
	Reference inverse();
	Reference transpose();
	void set(tlint, tlint, float);
	void setColumn(tlint, vec);
	void setRow(tlint, vec);
	float get(tlint, tlint);
	Reference getRow(tlint);
	Reference getColumn(tlint);
	Reference toString();
	mat1x1 values();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */

#endif /* SRC_ADVANCED_MATH_MAT1X1_H_ */
