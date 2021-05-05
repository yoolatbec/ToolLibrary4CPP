/*
 * SortedSet.cpp
 *
 *  Created on: May 2, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/Comparator.h>
#include <tl/utils/Iterator.h>
#include <tl/utils/SortedSet.h>

namespace tl {
namespace utils {

SortedSet::SortedSet(type_t elementType)
	: Collection(elementType), Set(elementType) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

SortedSet::SortedSet(type_t elementType, Reference comparator)
	: Collection(elementType), Set(elementType) {
	if (!comparator.isNull()) {
		argumentTypeCheck(comparator, Comparator::type());
	}

	mComparator = comparator;
	mHashCode = genHashCode(CLASS_SERIAL);
}

SortedSet::~SortedSet() {
	// TODO Auto-generated destructor stub
}

void SortedSet::invalidateIterators() {
	if (!mIterator.isNull()) {
		Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
		iterator->invalidate();
	}

	if (!mDescendingIterator.isNull()) {
		Iterator *iterator =
			dynamic_cast<Iterator*>(mDescendingIterator.getEntity());
		iterator->invalidate();
	}
}

type_t SortedSet::type() {
	return CLASS_SERIAL;
}

bool SortedSet::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Set::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
