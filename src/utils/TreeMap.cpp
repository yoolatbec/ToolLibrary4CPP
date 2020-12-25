/*
 * TreeMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include "TreeMap.h"
#include "../lang/Math.h"

namespace tl {
namespace utils {

TreeMap::TreeMap(type_t keyType, type_t valueType) :
		Map(keyType, valueType) {
	// TODO Auto-generated constructor stub
	mRootEntry = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
	TreeEntry::clear(mRootEntry);
}

TreeMap::TreeEntry::TreeEntry(Reference key, Reference value) :
		Entry(key, value) {
	mHeight = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::TreeEntry::containsKey(Reference ref, Reference key) {
	if (ref.isNull()) {
		return false;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mKey.equals(key)) {
		return true;
	}

	return containsKey(entry->mLeft, key) || containsKey(entry->mRight, key);
}

bool TreeMap::TreeEntry::containsValue(Reference ref, Reference value) {
	if (ref.isNull()) {
		return false;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mValue.equals(value)) {
		return true;
	}

	return containsValue(entry->mLeft, value)
			|| containsValue(entry->mRight, value);
}

tlint TreeMap::TreeEntry::height(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	return entry->mHeight;
}

Reference TreeMap::TreeEntry::rightRotate(Reference ref) {
	TreeEntry *parentEntry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference left = parentEntry->mLeft;
	TreeEntry *leftEntry = dynamic_cast<TreeEntry*>(left.getEntity());

	parentEntry->mLeft = leftEntry->mRight;
	leftEntry->mRight = ref;
	parentEntry->mHeight = lang::Math::max(
			TreeMap::TreeEntry::height(parentEntry->mLeft),
			TreeMap::TreeEntry::height(parentEntry->mRight)) + 1;
	leftEntry->mHeight = lang::Math::max(
			TreeMap::TreeEntry::height(leftEntry->mLeft),
			TreeMap::TreeEntry::height(leftEntry->mRight)) + 1;

	return left;
}

Reference TreeMap::TreeEntry::leftRotate(Reference ref) {
	TreeEntry *parentEntry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference right = parentEntry->mRight;
	TreeEntry *rightEntry = dynamic_cast<TreeEntry*>(right.getEntity());

	parentEntry->mRight = rightEntry->mLeft;
	rightEntry->mLeft = ref;
	parentEntry->mHeight = lang::Math::max(
			TreeMap::TreeEntry::height(parentEntry->mLeft),
			TreeMap::TreeEntry::height(parentEntry->mRight)) + 1;
	rightEntry->mHeight = lang::Math::max(
			TreeMap::TreeEntry::height(rightEntry->mLeft),
			TreeMap::TreeEntry::height(rightEntry->mRight)) + 1;

	return right;
}

Reference TreeMap::TreeEntry::rightLeftRotate(Reference ref) {
	TreeEntry *parentEntry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference right = parentEntry->mRight;

	parentEntry->mRight = TreeMap::TreeEntry::rightRotate(right);
	return TreeMap::TreeEntry::leftRotate(ref);
}

Reference TreeMap::TreeEntry::leftRightRotate(Reference ref) {
	TreeEntry *parentEntry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference left = parentEntry->mLeft;

	parentEntry->mLeft = TreeMap::TreeEntry::leftRotate(left);
	return TreeMap::TreeEntry::rightRotate(ref);
}

Reference TreeMap::TreeEntry::balance(Reference ref) {
	if (ref.isNull()) {
		return ref;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference left = entry->mLeft;
	Reference right = entry->mRight;
	TreeEntry *leftEntry = dynamic_cast<TreeEntry*>(left.getEntity());
	TreeEntry *rightEntry = dynamic_cast<TreeEntry*>(right.getEntity());

	if (TreeMap::TreeEntry::height(left) - TreeMap::TreeEntry::height(right)
			> ALLOWED_IMBALANCE) {
		if (TreeMap::TreeEntry::height(leftEntry->mLeft)
				>= TreeMap::TreeEntry::height(leftEntry->mRight)) {
			ref = TreeMap::TreeEntry::rightRotate(ref);
		} else {
			ref = TreeMap::TreeEntry::leftRightRotate(ref);
		}
	} else if (TreeMap::TreeEntry::height(right)
			- TreeMap::TreeEntry::height(left) > ALLOWED_IMBALANCE) {
		if (TreeMap::TreeEntry::height(rightEntry->mRight)
				>= TreeMap::TreeEntry::height(rightEntry->mLeft)) {
			ref = TreeMap::TreeEntry::leftRotate(ref);
		} else {
			ref = TreeMap::TreeEntry::rightLeftRotate(ref);
		}
	}

	entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	left = entry->mLeft;
	right = entry->mRight;

	entry->mHeight = lang::Math::max(TreeMap::TreeEntry::height(left),
			TreeMap::TreeEntry::height(right)) + 1;
	return ref;
}

Reference TreeMap::TreeEntry::add(Reference ref, Reference keyRef,
		Reference valueRef) {
	if (ref.isNull()) {
		return Reference(new TreeEntry(keyRef, valueRef));
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (ref.equals(keyRef)) {
		entry->mValue = valueRef;
	} else if (keyRef.getEntity()->mHashCode > ref.getEntity()->mHashCode) {
		TreeMap::TreeEntry::add(entry->mRight, keyRef, valueRef);
	} else {
		TreeMap::TreeEntry::add(entry->mLeft, keyRef, valueRef);
	}

	return TreeMap::TreeEntry::balance(ref);
}

Reference TreeMap::TreeEntry::remove(Reference ref, Reference keyRef) {
	if(ref.isNull()){
		return ref;
	}


}

} /* namespace utils */
} /* namespace tl */
