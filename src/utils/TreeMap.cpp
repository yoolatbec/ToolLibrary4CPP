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

TreeMap::TreeMap(type_t keyType, type_t valueType)
		: Map(keyType, valueType) {
	// TODO Auto-generated constructor stub
	mRootEntry = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
	TreeEntry::clear(mRootEntry);
	mRootEntry = Reference();
}

TreeMap::TreeEntry::TreeEntry(Reference key, Reference value)
		: Entry(key, value) {
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
	if (ref.isNull()) {
		return ref;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->mKey.equals(keyRef)) {
		if (!entry->mLeft.isNull() && !entry->mRight.isNull()) {
			TreeEntry *minEntry =
					dynamic_cast<TreeEntry*>(TreeMap::TreeEntry::findMin(
							entry->mRight).getEntity());
			entry->mKey = minEntry->mKey;
			entry->mValue = minEntry->mValue;
			entry->mWeight = minEntry->mWeight;
			entry->mRight = TreeMap::TreeEntry::remove(entry->mRight,
					entry->mKey);
		} else {
			ref = entry->mLeft.isNull() ? entry->mRight : entry->mLeft;
		}
	} else if (entry->mWeight < keyRef.getEntity()->mHashCode) {
		entry->mRight = TreeMap::TreeEntry::remove(entry->mRight, keyRef);
	} else {
		entry->mLeft = TreeMap::TreeEntry::remove(entry->mLeft, keyRef);
	}

	return TreeMap::TreeEntry::balance(ref);
}

Reference TreeMap::TreeEntry::findMin(Reference ref) {
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mLeft.isNull()) {
		return ref;
	} else {
		return TreeMap::TreeEntry::findMin(entry->mLeft);
	}
}

Reference TreeMap::TreeEntry::replace(Reference ref, Reference keyRef,
		Reference valueRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mKey.equals(keyRef)) {
		entry->mValue = valueRef;
		return valueRef;
	} else if (keyRef.getEntity()->mHashCode < entry->mWeight) {
		return TreeMap::TreeEntry::replace(entry->mLeft, keyRef, valueRef);
	} else {
		return TreeMap::TreeEntry::replace(entry->mRight, keyRef, valueRef);
	}
}

Reference TreeMap::TreeEntry::get(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mKey.equals(keyRef)) {
		return entry->mValue;
	} else if (keyRef.getEntity()->mHashCode < entry->mWeight) {
		return TreeMap::TreeEntry::get(entry->mLeft, keyRef);
	} else {
		return TreeMap::TreeEntry::get(entry->mRight, keyRef);
	}
}

void TreeMap::TreeEntry::clear(Reference ref) {
	if (ref.isNull()) {
		return;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	TreeMap::TreeEntry::clear(entry->mLeft);
	TreeMap::TreeEntry::clear(entry->mRight);

	entry->mLeft = Reference();
	entry->mRight = Reference();
}

Reference TreeMap::TreeEntry::getLeft() {
	return mLeft;
}

Reference TreeMap::TreeEntry::getRight() {
	return mRight;
}

tlint TreeMap::TreeEntry::getHeight() {
	return mHeight;
}

TreeMap::TreeMap(type_t keyType, type_t valueType)
		: Map(keyType, valueType) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::get(Reference key) {
	if (!key.getEntity()->instanceof(mKeyType)) {
		//cast an excetion here
	}

	return TreeMap::TreeEntry::get(mRootEntry, key);
}

Reference TreeMap::put(Reference key, Reference value) {
	if (!key.getEntity()->instanceof(mKeyType)
			|| !value.getEntity()->instanceof(mValueType)) {
		//cast an exception here
	}

	Reference oldValue = TreeMap::TreeEntry::get(mRootEntry, key);
	mRootEntry = TreeMap::TreeEntry::add(oldValue, key, value);
	if (!oldValue.isNull()) {
		return oldValue;
	} else {
		return value;
	}
}

Reference TreeMap::remove(Reference key) {
	if (!key.getEntity()->instanceof(mKeyType)) {
		//cast an exception here
	}

	Reference oldValue = TreeMap::TreeEntry::get(mRootEntry, key);
	mRootEntry = TreeMap::TreeEntry::remove(mRootEntry, key);
	return oldValue;
}

Reference TreeMap::putIfAbsent(Reference key, Reference value) {
	if (!key.getEntity()->instanceof(mKeyType)
			|| !value.getEntity()->instanceof(mValueType)) {
		//cast an exception here
	}

	Reference oldValue = TreeMap::TreeEntry::get(mRootEntry, key);
	if (oldValue.isNull()) {
		mRootEntry = TreeMap::TreeEntry::add(oldValue, key, value);
		return value;
	} else {
		return oldValue;
	}
}

Reference TreeMap::replace(Reference key, Reference value) {
	if (!key.getEntity()->instanceof(mKeyType)
			|| !value.getEntity()->instanceof(mValueType)) {
		//cast an exception here
	}

	return TreeMap::TreeEntry::replace(mRootEntry, key, value);
}

bool TreeMap::containsKey(Reference key) {
	return TreeMap::TreeEntry::containsKey(mRootEntry, key);
}

bool TreeMap::containsValue(Reference value) {
	return TreeMap::TreeEntry::containsValue(mRootEntry, value);
}

void TreeMap::clear() {
	TreeMap::TreeEntry::clear(mRootEntry);
	mRootEntry = Reference();
}

Set TreeMap::keySet() {

}

Set TreeMap::values() {

}

type_t TreeMap::type() {
	return CLASS_SERIAL;
}

bool TreeMap::instanceof(type_t type) {
	return CLASS_SERIAL == type || Map::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
