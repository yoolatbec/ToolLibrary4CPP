/*
 * HashMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include "HashMap.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {

using lang::Array;

HashMap::HashMap(type_t keyType, type_t valueType) :
		mKeyType(keyType), mValueType(valueType) {
	// TODO Auto-generated constructor stub

	mTables = Reference(new Array(Array::type(), TABLE_COUNT));
	Array *tables = dynamic_cast<Array*>(mTables.getEntity());
	for (tlint index = 0; index < TABLE_COUNT; index++) {
		tables->set(index,
				Reference(new Array(HashEntry::type(), INIT_CAPACITY[index])));
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

HashMap::~HashMap() {
	// TODO Auto-generated destructor stub
}

bool HashMap::instanceof(type_t type){
	return (CLASS_SERIAL == type) || Map::instanceof(type);
}

type_t HashMap::type(){
	return CLASS_SERIAL;
}

HashMap::HashEntry::HashEntry(Reference key, Reference value) :
		Entry(key, value) {
	mValid = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool HashMap::HashEntry::valid() {
	return mValid;
}

void HashMap::HashEntry::invalidate() {
	mValid = false;
}

void HashMap::HashEntry::validate() {
	mValid = true;
}

} /* namespace utils */
} /* namespace tl */
