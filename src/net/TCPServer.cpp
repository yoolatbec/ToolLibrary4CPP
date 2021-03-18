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
#include <tl/net/InetAddress.h>
#include <tl/net/UnableToOpenSocketException.h>

namespace tl {
namespace net {

TCPServer::TCPServer() {
	// TODO Auto-generated constructor stub
	openSocket();

	mBuffer = new byte[DEFAULT_BUFFER_SIZE];
}

TCPServer::TCPServer(tlint bufferSize) {
	openSocket();
}

void TCPServer::openSocket() {
	mSocketID = socket(AF_INET, SOCK_STREAM, 0);
	if (mSocketID < 0) {
		//cast an exception
		throw UnableToOpenSocketException();
	}
}

TCPServer::~TCPServer() {
	// TODO Auto-generated destructor stub
}

void TCPServer::bind(Reference address) {
	dismissNull(address);
	argumentTypeCheck(address, InetAddress::type());


}

void TCPServer::listen(tlint backlog){
	tlint err = listen(mSocketID, backlog);
}

} /* namespace net */
} /* namespace tl */
