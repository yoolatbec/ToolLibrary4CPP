/*
 * LinkedList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "LinkedList.h"

namespace tl {
namespace utils {

LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub

}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

bool LinkedList::instanceof(hash_t type) const{
	return (mHash & CLASS_HASH == type) || List::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
