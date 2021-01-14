/*
 * NOArray.cpp
 *
 *  Created on: Jan 8, 2021
 *      Author: yoolatbec
 */

#include "NOArray.h"

namespace tl {
namespace lang {

NOArray::NOArray(tlint size)
		: mSize(size) {
}

tlint NOArray::size() {
	return mSize;
}

static type_t NOArray::type() {
	return CLASS_SERIAL;
}

bool NOArray::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Cloneable::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
