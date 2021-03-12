/*
 * InetAddress.h
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_INETADDRESS_H_
#define TL_NET_INETADDRESS_H_

#include <tl/lang/Reference.h>

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

#endif /* TL_NET_INETADDRESS_H_ */
