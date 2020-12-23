/*
 * Map.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "Map.h"

namespace tl {
namespace utils {

Map::Map(type_t keyType, type_t valueType)
		: mKeyType(keyType), mValueType(valueType) {
	// TODO Auto-generated constructor stub
	mSize = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

size_t Map::size(){
	return mSize;
}

bool Map::isEmpty(){
	return mSize == 0;
}

bool Map::instanceof(type_t type){
	return CLASS_SERIAL == type || Object::instanceof(type);
}

type_t Map::type(){
	return CLASS_SERIAL;
}

Map::Entry::Entry(Reference ref)
		: mKey(ref), mWeight(ref.getEntity()->mHashCode) {
	mValue = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

} /* namespace utils */
} /* namespace tl */
