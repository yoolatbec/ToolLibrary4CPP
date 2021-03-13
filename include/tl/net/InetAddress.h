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

using lang::Reference;

class InetAddress: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 263;
protected:
	InetAddress();
public:
	virtual ~InetAddress();
	InetAddress(const InetAddress &other) = delete;
	InetAddress& operator=(const InetAddress &other) = delete;
	virtual Reference toString() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_INETADDRESS_H_ */
