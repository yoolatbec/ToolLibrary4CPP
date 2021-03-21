/*
 * TCPServer.h
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#ifndef NET_IPV6_TCPSERVER_H_
#define NET_IPV6_TCPSERVER_H_

#include <tl/net/Socket.h>

namespace tl {
namespace net {
namespace ipv6 {

class TCPServer: public virtual Socket {
public:
	TCPServer();
	virtual ~TCPServer();
	TCPServer(const TCPServer &other) = delete;
	TCPServer& operator=(const TCPServer &other) = delete;
};

} /* namespace ipv6 */
} /* namespace net */
} /* namespace tl */

#endif /* NET_IPV6_TCPSERVER_H_ */
