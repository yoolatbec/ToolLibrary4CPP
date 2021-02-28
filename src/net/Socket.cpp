/*
 * Socket.cpp
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#include "Socket.h"
#include <sys/socket.h>
#include <unistd.h>

namespace tl {
namespace net {

Socket::Socket() {
	// TODO Auto-generated constructor stub
}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
	if(mStatus != SOCKET_STATUS::CLOSED){
		close(mSocketID);
	}
}

void Socket::closeSocket(){
	close(mSocketID);
	mStatus = SOCKET_STATUS::CLOSED;
}

} /* namespace net */
} /* namespace tl */
