/*
 * DatagramPacket.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: yoolatbec
 */

#include "DatagramPacket.h"
#include <tl/lang/IllegalArgumentException.h>

namespace tl {
namespace net {

using lang::IllegalArgumentException;

DatagramPacket::DatagramPacket(tlint dataSize) {
	// TODO Auto-generated constructor stub
	if(dataSize <= 0){
		throw IllegalArgumentException("data size can't be negative");
	}

	mData = new byte[dataSize];

	mHashCode = genHashCode(CLASS_SERIAL);
}

DatagramPacket::~DatagramPacket() {
	// TODO Auto-generated destructor stub
	delete[] mData;
}

} /* namespace net */
} /* namespace tl */
