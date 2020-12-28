/*
 * TreeSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "TreeSet.h"
#include "../lang/Array.h"
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

TreeSet::TreeSetIterator::TreeSetIterator(Reference ref){
	if(!ref.instanceof(TreeSet::type())){
		//cast an exception here
	}

	mSet = ref;
	TreeSet* set = dynamic_cast<TreeSet*>(mSet.getEntity());
	mSetElements = new Array(set->elementType(), set->size());
}

} /* namespace utils */
} /* namespace tl */
