/*
 * UnableToRecognizeAddressException.h
 *
 *  Created on: Mar 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_NET_UNABLETORECOGNIZEADDRESSEXCEPTION_H_
#define TL_NET_UNABLETORECOGNIZEADDRESSEXCEPTION_H_

#include <tl/net/NetworkException.h>

namespace tl {
namespace net {

class UnableToRecognizeAddressException: public virtual NetworkException {
private:
	const static type_t CLASS_SERIAL = 748;
	constexpr const static char* DEFAULT_MESSAGE = "UnableToRecognizeAddressException:";
	static Reference sDefaultMessage;
public:
	UnableToRecognizeAddressException();
	UnableToRecognizeAddressException(const char*);
	virtual ~UnableToRecognizeAddressException();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace net */
} /* namespace tl */

#endif /* TL_NET_UNABLETORECOGNIZEADDRESSEXCEPTION_H_ */
