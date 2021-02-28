/*
 * Float.cpp
 *
 *  Created on: 3 Feb 2021
 *      Author: yoolatbec
 */

#include "Float.h"

namespace tl {
namespace lang {

Float::Float(float value) {
	// TODO Auto-generated constructor stub
	mValue = value;

	mHashCode = genHashCode();
}

Float::~Float() {
	// TODO Auto-generated destructor stub
}

hash_t Float::genHashCode(){
	return (CLASS_SERIAL << 32) + *((tlint*)(&mValue));
}

} /* namespace lang */
} /* namespace tl */
