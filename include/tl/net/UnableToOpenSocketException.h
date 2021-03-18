/*
 * UnableToOpenSocketException.h
 *
 *  Created on: Mar 12, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_UNABLETOOPENSOCKETEXCEPTION_H_
#define TL_NET_UNABLETOOPENSOCKETEXCEPTION_H_

#include <tl/net/SocketException.h>

namespace tl {
namespace net {

using lang::Reference;

class UnableToOpenSocketException: public virtual SocketException {
private:
	const static type_t CLASS_SERIAL = 261;
	const static constexpr char *DEFAULT_MESSAGE =
		"UnableToOpenSocketException:";
	static Reference sDefaultMessage;
public:
	UnableToOpenSocketException();
	UnableToOpenSocketException(const char*);
	virtual ~UnableToOpenSocketException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_UNABLETOOPENSOCKETEXCEPTION_H_ */
