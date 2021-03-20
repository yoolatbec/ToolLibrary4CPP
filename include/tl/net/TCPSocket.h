/*
 * TCPSocket.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_TCPSOCKET_H_
#define TL_NET_TCPSOCKET_H_

#include <tl/net/Socket.h>

namespace tl {
namespace net {

class TCPSocket: public virtual Socket {
private:
	const static type_t CLASS_SERIAL = 345;
public:
	TCPSocket();
	TCPSocket(tlint, Reference);
	virtual ~TCPSocket();
	TCPSocket(const TCPSocket &other) = delete;
	TCPSocket& operator=(const TCPSocket &other) = delete;
	void bindLocalAddress(Reference);
	void connectTo(Reference);
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_TCPSOCKET_H_ */
