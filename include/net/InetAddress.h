/*
 * InetAddress.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef NET_INETADDRESS_H_
#define NET_INETADDRESS_H_

#include <lang/Reference.h>

namespace tl {
namespace net {

class InetAddress: public virtual lang::Object {
public:
	InetAddress();
	virtual ~InetAddress();
	InetAddress(const InetAddress &other) = delete;
	InetAddress& operator=(const InetAddress &other) = delete;
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_INETADDRESS_H_ */
