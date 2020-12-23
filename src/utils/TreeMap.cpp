/*
 * TreeMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include "TreeMap.h"

namespace tl {
namespace utils {

TreeMap::TreeMap(type_t keyType, type_t valueType)
		: Map(keyType, valueType) {
	// TODO Auto-generated constructor stub
	mRootEntry = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
}

} /* namespace utils */
} /* namespace tl */
