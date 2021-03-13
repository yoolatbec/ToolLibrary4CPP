/*
 * Inet4Address.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_INET4ADDRESS_H_
#define TL_NET_INET4ADDRESS_H_

#include <tl/net/InetAddress.h>

namespace tl {
namespace net {

class Inet4Address: public virtual InetAddress {
private:
	const static type_t CLASS_SERIAL = 262;
	Inet4Address();
public:
	virtual ~Inet4Address();
	Inet4Address(const Inet4Address &other) = delete;
	Inet4Address& operator=(const Inet4Address &other) = delete;
	static Reference newInstance(const char*);
	static Reference newInstance(Reference);
	static Reference newInstance(const byte*, short);
	Reference toString();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_INET4ADDRESS_H_ */
