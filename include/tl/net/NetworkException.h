/*
 * NetworkException.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_NETWORKEXCEPTION_H_
#define TL_NET_NETWORKEXCEPTION_H_

#include <tl/lang/Exception.h>

namespace tl {
namespace net {

using lang::Reference;

class NetworkException: public virtual lang::Exception {
private:
	const static type_t CLASS_SERIAL = 506;
	const static constexpr char *DEFAULT_MESSAGE = "NetworkException:";
	static Reference sDefaultMessage;
public:
	NetworkException();
	NetworkException(const char*);
	virtual ~NetworkException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_NETWORKEXCEPTION_H_ */
