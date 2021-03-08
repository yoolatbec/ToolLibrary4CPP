/*
 * Socket.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include <net/Socket.h>
#include <sys/socket.h>
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

} /* namespace net */
} /* namespace tl */
