/*
 * Socket.h
 *
 *  Created on: Feb 19, 2021
 *      Author: yoolatbec
 */

#ifndef NET_SOCKET_H_
#define NET_SOCKET_H_

#include "../lang/Reference.h"

namespace tl {
namespace net {

using lang::Reference;

class Socket: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 200;

protected:
	tlint mSocketID;

public:
	Socket();
	virtual ~Socket();
	Socket(const Socket &other) = delete;
	Socket& operator=(const Socket &other) = delete;
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_SOCKET_H_ */
