/*
 * SocketException.h
 *
 *  Created on: Mar 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_SOCKETEXCEPTION_H_
#define TL_NET_SOCKETEXCEPTION_H_

#include <tl/net/NetworkException.h>

namespace tl {
namespace net {

using lang::Reference;

class SocketException: public NetworkException {
private:
	const static type_t CLASS_SERIAL = 902;
	constexpr const static char* DEFAULT_MESSAGE = "SocketException:";
	static Reference sDefaultMessage;
public:
	SocketException();
	SocketException(const char*);
	virtual ~SocketException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_SOCKETEXCEPTION_H_ */
