/*
 * TCPSocket.h
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#ifndef NET_IPV6_TCPSOCKET_H_
#define NET_IPV6_TCPSOCKET_H_

#include <tl/net/Socket.h>

namespace tl {
namespace net {
namespace ipv6 {

class TCPSocket: public virtual Socket {
public:
	TCPSocket();
	virtual ~TCPSocket();
	TCPSocket(const TCPSocket &other) = delete;
	TCPSocket& operator=(const TCPSocket &other) = delete;
};

} /* namespace ipv6 */
} /* namespace net */
} /* namespace tl */

#endif /* NET_IPV6_TCPSOCKET_H_ */
