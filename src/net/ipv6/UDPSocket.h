/*
 * UDPSocket.h
 *
 *  Created on: Mar 21, 2021
 *      Author: yoolatbec
 */

#ifndef NET_IPV6_UDPSOCKET_H_
#define NET_IPV6_UDPSOCKET_H_

#include <tl/net/Socket.h>

namespace tl {
namespace net {
namespace ipv6 {

class UDPSocket: public Socket {
public:
	UDPSocket();
	virtual ~UDPSocket();
	UDPSocket(const UDPSocket &other) = delete;
	UDPSocket& operator=(const UDPSocket &other) = delete;
};

} /* namespace ipv6 */
} /* namespace net */
} /* namespace tl */

#endif /* NET_IPV6_UDPSOCKET_H_ */
