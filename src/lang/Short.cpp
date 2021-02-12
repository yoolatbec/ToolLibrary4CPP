/*
 * Short.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: yoolatbec
 */

#include "Short.h"

namespace tl {
namespace lang {

Short::Short(short value) {
	// TODO Auto-generated constructor stub
	mValue = value;

	mHashCode = genHashCode();
}

Short::~Short() {
	// TODO Auto-generated destructor stub
}

} /* namespace lang */
} /* namespace tl */
