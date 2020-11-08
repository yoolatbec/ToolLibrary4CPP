/*
 * Number.cpp
 *
 *  Created on: Sep 20, 2020
 *      Author: yoolatbec
 */

#include "Number.h"

namespace tl {
namespace lang {

Number::Number() {
	// TODO Auto-generated constructor stub

}

Number::~Number() {
	// TODO Auto-generated destructor stub
}

bool Number::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
