/*
 * Inet4Address.cpp
 *
 *  Created on: Feb 21, 2021
 *      Author: yoolatbec
 */

#include <tl/net/Inet4Address.h>
#include <tl/net/UnableToRecognizeAddressException.h>
#include <tl/lang/String.h>
#include <cstring>
#include <cstdio>
#include <arpa/inet.h>

namespace tl {
namespace net {

using lang::String;

Inet4Address::Inet4Address(const char *address, short port) {
	// TODO Auto-generated constructor stub
	memset(&mAddress, 0, sizeof(sockaddr_in));
	mAddress.sin_family = AF_INET;
	mAddress.sin_port = htons(port);
	inet_pton(AF_INET, address, &mAddress.sin_addr);
}

Inet4Address::~Inet4Address() {
	// TODO Auto-generated destructor stub
}

Reference Inet4Address::newInstance(Reference str, short port) {
	dismissNull(str);
	argumentTypeCheck(str, String::type());

	String *addr = dynamic_cast<String*>(str.getEntity());
	return newInstance(addr->toCharArray(), port);
}

Reference Inet4Address::newInstance(const char *addr, short port) {
	if (inet_addr(addr) == INADDR_NONE) {
		throw UnableToRecognizeAddressException();
	}

	return Reference(new Inet4Address(addr, port));
}

Reference Inet4Address::toString() {
	char addr[50];
	if (inet_ntop(AF_INET, &mAddress.sin_addr, addr, sizeof(addr)) == nullptr) {
		//cast an exception
	}
	sprintf(addr + strlen(addr), ":%d", ntohs(mAddress.sin_port));

	return Reference(new String(addr));
}

short Inet4Address::getPort() {
	return ntohs(mAddress.sin_port);
}

Reference Inet4Address::getAddress() {
	char addr[50];
	if (inet_ntop(AF_INET, &mAddress.sin_addr, addr, sizeof(addr)) == nullptr) {
		//cast an exception
	}

	return Reference(new String(addr));
}

sockaddr_in Inet4Address::getInetAddress() {
	return mAddress;
}

type_t Inet4Address::type() {
	return CLASS_SERIAL;
}

bool Inet4Address::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || InetAddress::instanceof(type);
}

} /* namespace net */
} /* namespace tl */
