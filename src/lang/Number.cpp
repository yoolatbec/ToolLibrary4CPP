/*
 * Number.cpp
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#include <lang/Number.h>

namespace tl {
namespace lang {

Number::Number() {
	// TODO Auto-generated constructor stub
}

Number::~Number() {
	// TODO Auto-generated destructor stub
}

bool Number::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Comparable::instanceof(type);
}

type_t Number::type(){
	return CLASS_SERIAL;
}

} /* namespace lang */
} /* namespace tl */
