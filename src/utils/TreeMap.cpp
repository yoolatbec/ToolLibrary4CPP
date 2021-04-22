/*
 * TreeMap.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/TreeMap.h>

namespace tl {
namespace utils {

TreeMap::TreeMap(type_t keyType, type_t valueType, Reference comparator)
	: Map(keyType, valueType), SortedMap(keyType, valueType, comparator) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
	clear();
}

} /* namespace utils */
} /* namespace tl */
