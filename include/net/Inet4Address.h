/*
 * Inet4Address.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef NET_INET4ADDRESS_H_
#define NET_INET4ADDRESS_H_

#include <net/InetAddress.h>

namespace tl {
namespace net {

class Inet4Address: public virtual InetAddress {
public:
	Inet4Address();
	virtual ~Inet4Address();
	Inet4Address(const Inet4Address &other) = delete;
	Inet4Address& operator=(const Inet4Address &other) = delete;
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_INET4ADDRESS_H_ */
