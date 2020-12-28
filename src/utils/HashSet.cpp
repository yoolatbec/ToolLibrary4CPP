/*
 * HashSet.cpp
 *
 *  Created on: Nov, 11, 2020
 *      Author: Yoolatbec
 */

#include "HashSet.h"
#include "../lang/Array.h"


namespace tl {
namespace utils {

HashSet::HashSet(type_t type)
		: Set(type) {
	// TODO Auto-generated constructor stub
	mTableArray = Reference(new Array(Array::type(), 5));
	//initialize to 8, 13, 21, 34, 55
	Array *hashArray = (Array*)mTableArray.getEntity();
	for (int index = 0; index < TABLE_NUM; index++) {
		hashArray->set(
				Reference(
						new Array(HashEntry::type(), INITIAL_CAPACITY[index])),
				index);
		mHashFactor[index] = INITIAL_CAPACITY[index];
	}

	mHashCode = genHashCode(CLASS_SERIAL);
}

HashSet::~HashSet() {
	// TODO Auto-generated destructor stub
	Array* tableArray = (Array*)mTableArray.getEntity();
	for(int index = 0; index < TABLE_NUM; index++){
		tableArray->set(Reference(), index);
	}
	mTableArray = Reference();
}

HashSet::HashEntry::HashEntry() {
	mValid = false;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void HashSet::reHash() {
	Array *tableArray = (Array*)mTableArray.getEntity();
	size_t newCapacity = ((Array*)tableArray->get(3).getEntity())->size()
			+ ((Array*)tableArray->get(4).getEntity())->size();

	if(newCapacity > lang::Integer::MAX_VALUE){

	}

	Reference newTableRef = Reference(new Array(HashEntry::type(), newCapacity));
	Array* newTable = (Array*)newTableRef.getEntity();
	Reference oldTableRef = tableArray->get(0);
	Array* oldTable = (Array*)oldTableRef.getEntity();

	for(int index = 0; index < TABLE_NUM - 1; index++){
		tableArray->set(tableArray->get(index + 1), index);
	}
	tableArray->set(newTableRef, TABLE_NUM - 1);

	for(int index = 0; index < oldTable->size(); index++){
		Reference ref = oldTable->get(index);
		HashEntry* entry = dynamic_cast<HashEntry*>(ref.getEntity());
		if(entry->mValid){
			add(entry->mValue);
		}
	}
}

type_t HashSet::type() {
	return CLASS_SERIAL;
}

bool HashSet::instanceof(type_t type) {
	return CLASS_SERIAL == type || Set::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
