/*
 * Math.cpp
 *
 *  Created on: Dec 24, 2020
 *      Author: yoolatbec
 */

#include "Math.h"
#include <math.h>

namespace tl {
namespace lang {

Math::Math() {
	// TODO Auto-generated constructor stub

}

type_t Math::type(){
	return CLASS_SERIAL;
}

bool Math::instanceof(type_t type){
	return CLASS_SERIAL == type || Object::instanceof(type);
}

tlint Math::min(tlint a, tlint b){
	return a < b ? a : b;
}

tlint Math::max(tlint a, tlint b){
	return a > b ? a : b;
}

double Math::abs(double i){
	return i > 0 ? i : -i;
}

} /* namespace lang */
} /* namespace tl */
