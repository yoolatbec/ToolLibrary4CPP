/*
 * UndefinedException.cpp
 *
 *  Created on: Feb 24, 2021
 *      Author: yoolatbec
 */

#include "UndefinedException.h"
#include "String.h"

namespace tl {
namespace lang {

UndefinedException::UndefinedException() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

UndefinedException::~UndefinedException() {
	// TODO Auto-generated destructor stub
}

} /* namespace lang */
} /* namespace tl */
