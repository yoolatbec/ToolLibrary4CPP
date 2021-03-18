/*
 * ThreadException.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/String.h>
#include <tl/thread/ThreadException.h>

namespace tl {
namespace thread {

using lang::Reference;
using lang::String;

Reference ThreadException::sDefaultMessage = Reference(new String(DEFAULT_MESSAGE));

ThreadException::ThreadException() {
	// TODO Auto-generated constructor stub
	mMessage = sDefaultMessage;

	mHashCode = genHashCode(CLASS_SERIAL);
}

ThreadException::ThreadException(const char* msg){
	msg = concatMessage(DEFAULT_MESSAGE, msg);
	mMessage = Reference(new String(msg));
	delete[] msg;

	mHashCode = genHashCode(CLASS_SERIAL);
}

ThreadException::~ThreadException() {
	// TODO Auto-generated destructor stub
}

type_t ThreadException::type(){
	return CLASS_SERIAL;
}

bool ThreadException::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Exception::instanceof(type);
}

} /* namespace thread */
} /* namespace tl */
