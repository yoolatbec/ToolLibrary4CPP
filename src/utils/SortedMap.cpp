/*
 * SortedMap.cpp
 *
 *  Created on: 2021年2月4日
 *      Author: yoolatbec
 */

#include "SortedMap.h"

namespace tl {
namespace utils {

SortedMap::SortedMap(type_t keyType, type_t valueType)
	: Map(keyType, valueType) {
	// TODO Auto-generated constructor stub

	mHashCode = genHashCode(CLASS_SERIAL);
}

SortedMap::~SortedMap() {
	// TODO Auto-generated destructor stub
}

type_t SortedMap::type() {
	return CLASS_SERIAL;
}

bool SortedMap::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Map::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
