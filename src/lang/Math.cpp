/*
 * Math.cpp
 *
 *  Created on: Dec 24, 2020
 *      Author: yoolatbec
 */

#include <lang/Math.h>
#include <math.h>

namespace tl {
namespace lang {

Math::Math() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

type_t Math::type(){
	return CLASS_SERIAL;
}

bool Math::instanceof(type_t type){
	return CLASS_SERIAL == type || Object::instanceof(type);
}

double Math::abs(double i){
	return i > 0 ? i : -i;
}

double Math::power(double base, double exp){
	return pow(base, exp);
}

} /* namespace lang */
} /* namespace tl */
