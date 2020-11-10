/*
 * GenericCollection.cpp
 *
 *  Created on: 2020Äê11ÔÂ10ÈÕ
 *      Author: Yoolatbec
 */

#include "GenericCollection.h"

namespace tl {
namespace utils {

GenericCollection::GenericCollection() {
	// TODO Auto-generated constructor stub
	mSize = 0;
}

GenericCollection::~GenericCollection() {
	// TODO Auto-generated destructor stub
}

hash_t GenericCollection::getType(){
	return CLASS_HASH;
}

bool GenericCollection::instanceof(hash_t type) const{
	return (type == CLASS_HASH) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
