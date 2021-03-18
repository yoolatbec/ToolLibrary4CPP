/*
 * Socket.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_SOCKET_H_
#define TL_NET_SOCKET_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace net {

using lang::Reference;

class Socket: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 200;

protected:
	tlint mSocketID;

	Socket();
	Socket(tlint);
public:
	virtual ~Socket();
	Socket(const Socket &other) = delete;
	Socket& operator=(const Socket &other) = delete;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_SOCKET_H_ */
