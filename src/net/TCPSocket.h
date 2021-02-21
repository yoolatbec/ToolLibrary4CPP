/*
 * TCPSocket.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef NET_TCPSOCKET_H_
#define NET_TCPSOCKET_H_

#include "Socket.h"

namespace tl {
namespace net {

class TCPSocket: public virtual Socket {
private:
	const static type_t CLASS_SERIAL = 345;
public:
	TCPSocket();
	virtual ~TCPSocket();
	TCPSocket(const TCPSocket &other) = delete;
	TCPSocket& operator=(const TCPSocket &other) = delete;
	void connectTo(Reference);
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_TCPSOCKET_H_ */
