/*
 * HashSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include <lang/Array.h>
#include <utils/HashSet.h>

namespace tl {
namespace utils {

using lang::Array;
using lang::Reference;

HashSet::HashSet(type_t type)
	: Collection(type), Set(type) {
	// TODO Auto-generated constructor stub
	mMap = Reference(new HashMap(type, Object::type()));

	mHashCode = genHashCode(CLASS_SERIAL);
}

HashSet::~HashSet() {
	// TODO Auto-generated destructor stub

}

void HashSet::invalidateIterators() {
	if (mIterator.isNull()) {
		return;
	}

	Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
	iterator->invalidate();
}

bool HashSet::add(Reference ref) {
	invalidateIterators();

	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	return map->put(ref, Reference()).isNull();
}

bool HashSet::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	invalidateIterators();

	Collection* c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator* iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while(iterator->hasNext()){
		Reference e = iterator->next();
		result = result || add(e);
	}

	return result;
}

bool HashSet::remove(Reference ref){
	invalidateIterators();

	HashMap* map = dynamic_cast<HashMap*>(mMap.getEntity());
	return !map->remove(ref).isNull();
}

bool HashSet::removeAll(Reference ref){
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	invalidateIterators();

	Collection* c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator* iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while(iterator->hasNext()){
		Reference e = iterator->next();
		result = result || remove(e);
	}

	return result;
}

bool HashSet::contains(Reference ref){
	HashMap* map = dynamic_cast<HashMap*>(mMap.getEntity());
	return map->containsKey(ref);
}

bool HashSet::containsAll(Reference ref){
	if(ref.isNull()){
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection* c = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = c->iterator();
	Iterator* iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = true;
	while(iterator->hasNext()){
		Reference e = iterator->next();
		result = result && contains(e);
		if(!result){
			return result;
		}
	}

	return result;
}

void HashSet::clear(){
	invalidateIterators();

	HashMap* map = dynamic_cast<HashMap*>(mMap.getEntity());
	map->clear();
}

Reference HashSet::iterator() {
	HashMap *map = dynamic_cast<HashMap*>(mMap.getEntity());
	Reference keySetRef = map->keySet();
	Set *keySet = dynamic_cast<Set*>(keySetRef.getEntity());
	mIterator = keySet->iterator();
	return mIterator;
}

Reference HashSet::toArray(){
	HashMap* map = dynamic_cast<HashMap*>(mMap.getEntity());
	Reference keySetRef = map->keySet();
	Set* keySet = dynamic_cast<Set*>(keySetRef.getEntity());
	return keySet->toArray();
}

type_t HashSet::type() {
	return CLASS_SERIAL;
}

bool HashSet::instanceof(type_t type) {
	return CLASS_SERIAL == type || Set::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
