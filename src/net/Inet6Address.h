/*
 * Inet6Address.h
 *
 *  Created on: Mar 18, 2021
 *      Author: yoolatbec
 */

#ifndef NET_INET6ADDRESS_H_
#define NET_INET6ADDRESS_H_

#include <tl/net/InetAddress.h>

namespace tl {
namespace net {

class Inet6Address: public virtual InetAddress {
public:
	Inet6Address();
	virtual ~Inet6Address();
	Inet6Address(const Inet6Address &other) = delete;
	Inet6Address& operator=(const Inet6Address &other) = delete;
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_INET6ADDRESS_H_ */
