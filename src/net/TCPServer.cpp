/*
 * TCPServer.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: yoolatbec
 */

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <tl/net/TCPServer.h>

namespace tl {
namespace net {

TCPServer::TCPServer() {
	// TODO Auto-generated constructor stub
	mSocketID = socket(AF_INET, SOCK_STREAM, 0);
	if(mSocketID < 0){
		//cast an exception
	}
}

TCPServer::~TCPServer() {
	// TODO Auto-generated destructor stub
}

} /* namespace net */
} /* namespace tl */
