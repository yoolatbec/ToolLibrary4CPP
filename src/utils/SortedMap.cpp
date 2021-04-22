/*
 * SortedMap.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Comparator.h>
#include <tl/utils/SortedMap.h>

namespace tl {
namespace utils {

SortedMap::SortedMap(type_t keyType, type_t valueType, Reference comparator)
	: Map(keyType, valueType) {
	// TODO Auto-generated constructor stub
	if (!comparator.isNull()) {
		argumentTypeCheck(comparator, Comparator::type());
	}

	mComparator = comparator;
	mHashCode = genHashCode(CLASS_SERIAL);
}

SortedMap::~SortedMap() {
	// TODO Auto-generated destructor stub
}

Reference SortedMap::getComparator() {
	return mComparator;
}

type_t SortedMap::type() {
	return CLASS_SERIAL;
}

bool SortedMap::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Map::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
