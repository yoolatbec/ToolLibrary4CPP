/*
 * TreeSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "TreeSet.h"
#include "LinkedList.h"

namespace tl {
namespace utils {

TreeSet::TreeSet(type_t type)
	:Set(type){
	// TODO Auto-generated constructor stub
	mMap = Reference(new TreeMap(type, Object::type()));

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeSet::~TreeSet() {
	// TODO Auto-generated destructor stub
	mMap = Reference()();
}

bool TreeSet::add(Reference ref){
	TreeMap* map = (TreeMap*)mMap.getEntity();
	if(map->containsKey(ref)){
		return false;
	}

	map->put(ref, Reference());
	return true;
}

} /* namespace utils */
} /* namespace tl */
