/*
 * Boolean.cpp
 *
 *  Created on: Feb 27, 2021
 *      Author: yoolatbec
 */

#include "Boolean.h"

namespace tl {
namespace lang {

Boolean::Boolean(bool value)
	: mValue(value) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference Boolean::trueValue = Reference(new Boolean(true));
Reference Boolean::falseValue = Reference(new Boolean(false));

Boolean::~Boolean() {
	// TODO Auto-generated destructor stub
}

bool Boolean::value(){
	return mValue;
}

Reference Boolean::valueOf(bool value){
	if(value){
		return trueValue;
	} else {
		return falseValue;
	}
}

type_t Boolean::type(){
	return CLASS_SERIAL;
}

bool Boolean::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
