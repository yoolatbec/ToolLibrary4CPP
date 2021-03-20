/*
 * TCPServer.h
 *
 *  Created on: Feb 20, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_TCPSERVER_H_
#define TL_NET_TCPSERVER_H_

#include <tl/net/Socket.h>

namespace tl {
namespace net {

class TCPServer: public virtual Socket {
private:
	const static type_t CLASS_SERIAL = 250;
	const static  tlint DEFAULT_BUFFER_SIZE = 4096;

	byte* mBuffer;

	void openSocket();
public:
	TCPServer();
	TCPServer(tlint);
	virtual ~TCPServer();
	TCPServer(const TCPServer &other) = delete;
	TCPServer& operator=(const TCPServer &other) = delete;
	void bindLocalAddress(Reference);
	void listenForConnection(tlint);
	Reference acceptNewConnection();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_TCPSERVER_H_ */
