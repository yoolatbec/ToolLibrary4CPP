/*
 * GenericList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "GenericList.h"

namespace tl {
namespace utils {

GenericList::GenericList() {
	// TODO Auto-generated constructor stub

}

GenericList::~GenericList() {
	// TODO Auto-generated destructor stub
}

hash_t GenericList::getType(){
	return CLASS_HASH;
}

bool GenericList::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || GenericCollection::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
