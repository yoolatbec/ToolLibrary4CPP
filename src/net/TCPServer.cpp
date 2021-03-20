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
#include <tl/net/TCPSocket.h>
#include <tl/net/Inet4Address.h>
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

void TCPServer::bindLocalAddress(Reference address) {
	dismissNull(address);
	argumentTypeCheck(address, Inet4Address::type());

	mLocalAddress = address;

	int err = 0;

	Inet4Address *addr = dynamic_cast<Inet4Address*>(address.getEntity());
	sockaddr_in s_addr = addr->getInetAddress();
	err = bind(mSocketID, (sockaddr*)&s_addr, sizeof(sockaddr_in));

}

void TCPServer::listenForConnection(tlint backlog) {
	tlint err = listen(mSocketID, backlog);
}

Reference TCPServer::acceptNewConnection() {
	tlint client;
	sockaddr_in clientAddress;
	socklen_t addressLen;

	client = accept(mSocketID, (sockaddr*)&clientAddress, &addressLen);
	if(client <= 0){
		//cast an exception
	}

	Reference address = Inet4Address::newInstance(clientAddress);
	return Reference(new TCPSocket(client, address));
}

type_t TCPServer::type(){
	return CLASS_SERIAL;
}

bool TCPServer::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Socket::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
