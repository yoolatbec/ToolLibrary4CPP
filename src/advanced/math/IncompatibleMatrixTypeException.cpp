/*
 * IncompatibleArgumentException.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: yoolatbec
 */

#include <tl/advanced/math/IncompatibleMatrixTypeException.h>
#include <tl/lang/String.h>

namespace tl {
namespace advanced {
namespace math {

using lang::Reference;
using lang::String;

Reference IncompatibleMatrixTypeException::sDefaultMessage = Reference(
	new String(DEFAULT_MESSAGE));

IncompatibleMatrixTypeException::IncompatibleMatrixTypeException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IncompatibleMatrixTypeException::IncompatibleMatrixTypeException(
	const char *msg) {
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

IncompatibleMatrixTypeException::~IncompatibleMatrixTypeException() {
	// TODO Auto-generated destructor stub
}

type_t IncompatibleMatrixTypeException::type() {
	return CLASS_SERIAL;
}

bool IncompatibleMatrixTypeException::instanceof(type_t type) {
	return (CLASS_SERIAL == type)
		|| IllegalArgumentTypeException::instanceof(type);
}
} /* namespace math */
} /* namespace advanced */
} /* namespace tl */
