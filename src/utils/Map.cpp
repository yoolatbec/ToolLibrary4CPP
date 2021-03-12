/*
 * Map.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include <tl/utils/Map.h>

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

tlint Map::size() {
	return mSize;
}

bool Map::isEmpty() {
	return mSize == 0;
}

type_t Map::keyType() {
	return mKeyType;
}

type_t Map::valueType() {
	return mValueType;
}

Reference Map::entry(Reference key, Reference value) {
	return Reference(new Entry(key, value));
}

bool Map::instanceof(type_t type) {
	return CLASS_SERIAL == type || Object::instanceof(type);
}

type_t Map::type() {
	return CLASS_SERIAL;
}

Map::Entry::Entry(Reference key, Reference value)
	: mKey(key), mValue(value) {
	mValue = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference Map::Entry::key() {
	return mKey;
}

Reference Map::Entry::value() {
	return mValue;
}

void Map::Entry::setValue(Reference value) {
	mValue = value;
}

} /* namespace utils */
} /* namespace tl */
