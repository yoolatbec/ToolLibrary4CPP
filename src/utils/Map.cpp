/*
 * Map.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#include <tl/lang/IllegalArgumentException.h>
#include <tl/utils/Map.h>

namespace tl {
namespace utils {

using lang::IllegalArgumentException;

Map::Map(type_t keyType, type_t valueType) {
	// TODO Auto-generated constructor stub
	mKeyType = keyType;
	mValueType = valueType;
	mSize = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

bool Map::isEmpty() {
	return mSize == 0;
}

type_t Map::keyType() {
	return mKeyType;
}

tlint Map::size() {
	return mSize;
}

type_t Map::valueType() {
	return mValueType;
}

type_t Map::type() {
	return CLASS_SERIAL;
}

bool Map::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

Map::Entry::Entry(type_t keyType, Reference key, type_t valueType,
	Reference value) {
	dismissNull(key);
	argumentTypeCheck(key, keyType);

	mKeyType = keyType;

	if (!value.isNull()) {
		argumentTypeCheck(value, valueType);
	}
	mValueType = valueType;

	mKey = key;
	mValue = value;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference Map::Entry::value() {
	return mValue;
}

Reference Map::Entry::key() {
	return mKey;
}

type_t Map::Entry::keyType() {
	return mKeyType;
}

type_t Map::Entry::valueType() {
	return mValueType;
}

Reference Map::Entry::setValue(Reference value) {
	if (!value.isNull()) {
		argumentTypeCheck(value, mValueType);
	}

	Reference oldValue = mValue;
	mValue = value;
	return oldValue;
}

Map::Entry::~Entry() {

}

static type_t Map::Entry::type() {
	return CLASS_SERIAL;
}

bool Map::Entry::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
