/*
 * Vec4.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: yoolatbec
 */

#include "Vec4.h"
#include "../../lang/FloatArray.h"
#include "../../lang/String.h"

namespace tl {
namespace advanced {
namespace math {

using lang::FloatArray;

Vec4::Vec4(float value) {
	// TODO Auto-generated constructor stub
	mValues = new float[COMPONENT_COUNT];
	for(tlint index =  0; index < COMPONENT_COUNT; index++){
		mValues[index] = value;
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

Vec4::Vec4(Reference ref) {
	mValues = new float[COMPONENT_COUNT];

	if (ref.getEntity()->instanceof(FloatArray::type())) {
		FloatArray *arr = dynamic_cast<FloatArray*>(ref.getEntity());
		for (tlint index = 0; index < COMPONENT_COUNT && index < arr->size(); index++) {
			mValues[index] = arr->get(index);
		}
	} else if (ref.getEntity()->instanceof(Vector::type())) {
		Vector *another = dynamic_cast<Vector*>(ref.getEntity());
		tlint size = another->size();
		tlint index;
		for (index = 0; index < size; index++) {
			mValues[index] = another->get(index);
		}
		for (; index < COMPONENT_COUNT; index++) {
			mValues[index] = 0;
		}
	} else {
		//cast an exception here
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

float Vec4::get(tlint index) {
	FloatArray *elements = dynamic_cast<FloatArray*>(mElements.getEntity());
	return elements->get(index);
}

void Vec4::set(tlint index, float value) {
	FloatArray *elements = dynamic_cast<FloatArray*>(mElements.getEntity());
	elements->set(index, value);
}

void Vec4::set(Reference ref) {
	if (ref.getEntity()->instanceof(FloatArray::type())) {
		FloatArray *arr = dynamic_cast<FloatArray*>(ref.getEntity());
		FloatArray *elements = dynamic_cast<FloatArray*>(mElements.getEntity());
		for (tlint index = 0; index < COMPONENT_COUNT && index < arr->size(); index++) {
			elements->set(index, arr->get(index));
		}
	} else if (ref.getEntity()->instanceof(Vector::type())) {
		FloatArray *elements = dynamic_cast<FloatArray*>(mElements.getEntity());
		Vector *another = dynamic_cast<Vector*>(ref.getEntity());
		for (tlint index = 0; index < COMPONENT_COUNT && index < another->size();
				index++) {
			elements->set(index, another->get(index));
		}
	} else {
		//cast an exception
	}
}

tlint Vec4::rowSize() {
	return 4;
}

tlint Vec4::size() {
	return 4;
}

Reference Vec4::toString(){
	FloatArray* elements = dynamic_cast<FloatArray*>(mElements.getEntity());
	return elements->toString();
}

Vec4::~Vec4() {
	// TODO Auto-generated destructor stub
}

} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
