/*
 * Inet4Address.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_INET4ADDRESS_H_
#define TL_NET_INET4ADDRESS_H_

#include <tl/net/InetAddress.h>
#include <netinet/in.h>

namespace tl {
namespace net {

class Inet4Address: public virtual InetAddress {
private:
	const static type_t CLASS_SERIAL = 262;
	const static short DEFAULT_PORT = 0;

	sockaddr_in mAddress;

	Inet4Address(const char*, short);
	Inet4Address(sockaddr_in);
public:
	virtual ~Inet4Address();
	Inet4Address(const Inet4Address &other) = delete;
	Inet4Address& operator=(const Inet4Address &other) = delete;
	static Reference newInstance(const char*, short = DEFAULT_PORT);
	static Reference newInstance(Reference, short = DEFAULT_PORT);
	static Reference newInstance(sockaddr_in);
	Reference toString();
	short getPort();
	Reference getAddress();
	sockaddr_in getInetAddress();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_INET4ADDRESS_H_ */
