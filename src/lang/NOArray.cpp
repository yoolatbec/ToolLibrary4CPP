/*
 * NOArray.cpp
 *
 *  Created on: Jan 8, 2021
 *      Author: yoolatbec
 */

#include <lang/IndexOutOfBoundsException.h>
#include <lang/NOArray.h>

namespace tl {
namespace lang {

NOArray::NOArray(tlint size)
		: mSize(size) {
}

tlint NOArray::size() {
	return mSize;
}

void NOArray::indexBoundCheck(tlint i){
	if(i < 0 || i >= mSize){
		throw IndexOutOfBoundsException();
	}
}

type_t NOArray::type() {
	return CLASS_SERIAL;
}

bool NOArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Cloneable::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
