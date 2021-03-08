/*
 * NavigableMap.cpp
 *
 *  Created on: 4 Feb 2021
 *      Author: yoolatbec
 */

#include <utils/NavigableMap.h>

namespace tl {
namespace utils {

NavigableMap::NavigableMap(type_t keyType, type_t valueType)
	: SortedMap(keyType, valueType) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

NavigableMap::~NavigableMap() {
	// TODO Auto-generated destructor stub
}

type_t NavigableMap::type(){
	return CLASS_SERIAL;
}

bool NavigableMap::instanceof(type_t type){
	return (CLASS_SERIAL == type) || SortedMap::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
