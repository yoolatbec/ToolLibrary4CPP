/*
 * Socket.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include <sys/socket.h>
#include <tl/net/Socket.h>
#include <unistd.h>

namespace tl {
namespace net {

Socket::Socket() {
	// TODO Auto-generated constructor stub
}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
	close(mSocketID);
}

type_t Socket::type() {
	return CLASS_SERIAL;
}

bool Socket::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
