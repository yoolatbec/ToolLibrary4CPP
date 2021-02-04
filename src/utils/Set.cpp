/*
 * Set.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "Set.h"

namespace tl {
namespace utils {

Set::Set(type_t type)
		: Collection(type) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Set::~Set() {
	// TODO Auto-generated destructor stub
}

bool Set::instanceof(type_t type){
	return CLASS_SERIAL == type || Collection::instanceof(type);
}

type_t Set::type(){
	return CLASS_SERIAL;
}

Set::Entry::Entry(){
	mValue = Reference();
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference Set::Entry::value(){
	return mValue;
}

} /* namespace utils */
} /* namespace tl */
