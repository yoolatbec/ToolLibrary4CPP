/*
 * InetAddress.cpp
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#include <tl/net/InetAddress.h>

namespace tl {
namespace net {

InetAddress::InetAddress() {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

InetAddress::~InetAddress() {
	// TODO Auto-generated destructor stub
}

type_t InetAddress::type() {
	return CLASS_SERIAL;
}

bool InetAddress::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
