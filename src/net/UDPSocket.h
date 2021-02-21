/*
 * UDPSocket.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef NET_UDPSOCKET_H_
#define NET_UDPSOCKET_H_

#include "Socket.h"

namespace tl {
namespace net {

class UDPSocket: public virtual Socket {
public:
	UDPSocket();
	virtual ~UDPSocket();
	UDPSocket(const UDPSocket &other) = delete;
	UDPSocket& operator=(const UDPSocket &other) = delete;
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_UDPSOCKET_H_ */
