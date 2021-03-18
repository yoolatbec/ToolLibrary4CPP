/*
 * Function.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#include "Function.h"
#include <tl/lang/Pointer.h>
#include <tl/thread/FailedToExecuteException.h>

namespace tl {
namespace thread {

using lang::Pointer;

Function::Function(fp f) {
	// TODO Auto-generated constructor stub
	mFunction = f;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Function::~Function() {
	// TODO Auto-generated destructor stub
}

fp Function::getFunction() {
	return mFunction;
}

void Function::setArgument(Reference ref) {
	argumentTypeCheck(ref, Pointer::type());

	mArguments = ref;
}

void Function::setArgument(void *arguments) {
	mArguments = Reference(new Pointer(arguments));
}

void* Function::perform(void *arguments) {
	return mFunction(arguments);
}

void* Function::perform() {
	if (mArguments.isNull()) {
		throw FailedToExecuteException();
	}

	Pointer *p = dynamic_cast<Pointer*>(mArguments.getEntity());
	return mFunction(p->get());
}

type_t Function::type() {
	return CLASS_SERIAL;
}

bool Function::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
