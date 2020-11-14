/*
 * Iterator.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "Iterator.h"

namespace tl {
namespace utils {

Iterator::Iterator() {
	// TODO Auto-generated constructor stub
	mValidate = true;
}

Iterator::~Iterator() {
	// TODO Auto-generated destructor stub
}

bool Iterator::isValidate() const{
	return mValidate;
}

} /* namespace utils */
} /* namespace tl */
