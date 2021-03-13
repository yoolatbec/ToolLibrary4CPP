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
public:
	TCPServer();
	virtual ~TCPServer();
	TCPServer(const TCPServer &other) = delete;
	TCPServer& operator=(const TCPServer &other) = delete;

};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_TCPSERVER_H_ */
