/*
 * UndefinedException.cpp
 *
 *  Created on: Feb 24, 2021
 *      Author: yoolatbec
 */

#include <lang/String.h>
#include <lang/UndefinedException.h>

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
