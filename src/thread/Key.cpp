/*
 * Key.cpp
 *
 *  Created on: Mar 14, 2021
 *      Author: yoolatbec
 */

#include "Function.h"
#include <tl/lang/Pointer.h>
#include <tl/thread/Key.h>
#include <tl/thread/ErrorChecker.h>

namespace tl {
namespace thread {

using lang::Pointer;

Key::Key() {
	// TODO Auto-generated constructor stub
	tlint err = pthread_key_create(&mKey, nullptr);
	ErrorChecker::check(err);

	mHashCode = genHashCode(CLASS_SERIAL);
}
//
//Key::Key(Reference func){
//
//}

void Key::set(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Pointer::type());

	Pointer *data = dynamic_cast<Pointer*>(ref.getEntity());
	pthread_setspecific(mKey, data->get());
}

Reference Key::get() {
	void *data = pthread_getspecific(mKey);
	return Reference(new Pointer(data));
}

Key::~Key() {
	// TODO Auto-generated destructor stub
}

type_t Key::type() {
	return CLASS_SERIAL;
}

bool Key::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
