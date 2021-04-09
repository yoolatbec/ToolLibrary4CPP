/*
 * System.cpp
 *
 *  Created on: Mar 26, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/System.h>
#include <tl/thread/Mutex.h>

namespace tl {
namespace lang {

using thread::Mutex;

Reference System::sSystemMutex = Reference(new Mutex());

System::System() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

System::~System() {
	// TODO Auto-generated destructor stub
}

void System::systemMutexLock() {
	Mutex *mutex = dynamic_cast<Mutex*>(sSystemMutex.getEntity());
	mutex->lock();
}

void System::systemMutexUnlock() {
	Mutex *mutex = dynamic_cast<Mutex*>(sSystemMutex.getEntity());
	mutex->unlock();
}

type_t System::type() {
	return CLASS_SERIAL;
}

bool System::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace lang */
} /* namespace tl */
