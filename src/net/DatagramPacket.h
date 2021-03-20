/*
 * DatagramPacket.h
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#ifndef NET_DATAGRAMPACKET_H_
#define NET_DATAGRAMPACKET_H_

#include <tl/lang/Reference.h>

namespace tl {
namespace net {

using lang::Reference;

class DatagramPacket: public virtual lang::Object {
private:
	const static type_t CLASS_SERIAL = 829;
	const static tlint DEFAULT_DATA_SIZE = 4096;

	byte* mData;

public:
	DatagramPacket(tlint = DEFAULT_DATA_SIZE);
	virtual ~DatagramPacket();
	DatagramPacket(const DatagramPacket &other) = delete;
	DatagramPacket& operator=(const DatagramPacket &other) = delete;
};

} /* namespace net */
} /* namespace tl */

#endif /* NET_DATAGRAMPACKET_H_ */
