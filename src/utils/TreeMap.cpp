/*
 * TreeMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include "TreeMap.h"
#include "../lang/Math.h"
#include "TreeSet.h"

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
	mRootEntry = Reference();
}

TreeMap::TreeEntry::TreeEntry(Reference key, Reference value) :
		Entry(key, value) {
	mHeight = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
	mWeight = key.getEntity()->mHashCode;
}

bool TreeMap::TreeEntry::containsKey(Reference ref, Reference key) {
	if (ref.isNull()) {
		return false;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mKey.equals(key)) {
		return true;
	}

	return containsKey(entry->getLeft(), key)
			|| containsKey(entry->getRight(), key);
}

bool TreeMap::TreeEntry::containsValue(Reference ref, Reference value) {
	if (ref.isNull()) {
		return false;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->mValue.equals(value)) {
		return true;
	}

	return containsValue(entry->getLeft(), value)
			|| containsValue(entry->getRight(), value);
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
	Reference left = entry->getLeft();
	Reference right = entry->getRight();
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
	left = entry->getLeft();
	right = entry->getRight();

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
	Reference key = entry->value();
	if (key.equals(keyRef)) {
		entry->mValue = valueRef;
	} else if (keyRef.getEntity()->mHashCode > entry->mWeight) {
		TreeMap::TreeEntry::add(entry->getRight(), keyRef, valueRef);
	} else {
		TreeMap::TreeEntry::add(entry->getLeft(), keyRef, valueRef);
	}

	return TreeMap::TreeEntry::balance(ref);
}

Reference TreeMap::TreeEntry::remove(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->mKey.equals(keyRef)) {
		if (!entry->getLeft().isNull() && !entry->getRight().isNull()) {
			TreeEntry *minEntry =
					dynamic_cast<TreeEntry*>(TreeMap::TreeEntry::minEntry(
							entry->getRight()).getEntity());
			entry->mKey = minEntry->mKey;
			entry->mValue = minEntry->mValue;
			entry->mWeight = minEntry->mWeight;
			entry->getRight() = TreeMap::TreeEntry::remove(entry->getRight(),
					entry->mKey);
		} else {
			ref = entry->getLeft().isNull() ?
					entry->getRight() : entry->getLeft();
		}
	} else if (entry->mWeight < keyRef.getEntity()->mHashCode) {
		entry->getRight() = TreeMap::TreeEntry::remove(entry->getRight(),
				keyRef);
	} else {
		entry->getLeft() = TreeMap::TreeEntry::remove(entry->getLeft(), keyRef);
	}

	return TreeMap::TreeEntry::balance(ref);
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
		return TreeMap::TreeEntry::replace(entry->getLeft(), keyRef, valueRef);
	} else {
		return TreeMap::TreeEntry::replace(entry->getRight(), keyRef, valueRef);
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
		return TreeMap::TreeEntry::get(entry->getLeft(), keyRef);
	} else {
		return TreeMap::TreeEntry::get(entry->getRight(), keyRef);
	}
}

void TreeMap::TreeEntry::clear(Reference ref) {
	if (ref.isNull()) {
		return;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	TreeMap::TreeEntry::clear(entry->getLeft());
	TreeMap::TreeEntry::clear(entry->getRight());

	entry->getLeft() = Reference();
	entry->getRight() = Reference();
}

Reference TreeMap::TreeEntry::minEntry(Reference ref) {
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->getLeft().isNull()) {
		return ref;
	} else {
		return TreeMap::TreeEntry::minEntry(entry->getLeft());
	}
}

Reference TreeMap::TreeEntry::maxEntry(Reference ref) {
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	if (entry->getRight().isNull()) {
		return ref;
	} else {
		return TreeMap::TreeEntry::maxEntry(entry->getRight());
	}
}

Reference TreeMap::TreeEntry::floorEntry(Reference ref, Reference keyRef) {
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->mWeight == keyRef.getEntity()->mHashCode) {
		return ref;
	} else if (entry->mWeight > keyRef.getEntity()->mHashCode) {
		if (entry->getLeft().isNull()) {
			return Reference();
		} else {
			return floorEntry(entry->getLeft(), keyRef);
		}
	} else {
		if (entry->getRight().isNull()) {
			return ref;
		} else {
			return TreeMap::TreeEntry::floorEntry(entry->getRight(), keyRef);
		}
	}

}

Reference TreeMap::TreeEntry::ceilEntry(Reference ref, Reference keyRef) {
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->mWeight == keyRef.getEntity()->mHashCode) {
		return ref;
	} else if (entry->mWeight < keyRef.getEntity()->mHashCode) {
		if (entry->getRight().isNull()) {
			return Reference();
		} else {
			return TreeMap::TreeEntry::ceilEntry(entry->getRight(), keyRef);
		}
	} else {
		if (entry->getLeft().isNull()) {
			return ref;
		} else {
			return TreeMap::TreeEntry::ceilEntry(entry->getLeft(), keyRef);
		}
	}
}

void TreeMap::TreeEntry::keys(Reference entryRef, Reference setRef){
	if(entryRef.isNull()){
		return;
	}

	if(setRef.isNull()){
		//cast an exception
	}

	Set* set = dynamic_cast<Set*>(setRef.getEntity());
	TreeEntry* entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());

	TreeMap::TreeEntry::keys(entry->getLeft(), setRef);
	set->add(entry->key());
	TreeMap::TreeEntry::keys(entry->getRight(), setRef);
}

void TreeMap::TreeEntry::values(Reference entryRef, Reference setRef){
	if(entryRef.isNull()){
		return;
	}

	if(setRef.isNull()){
		//cast an exception
	}

	Set* set = dynamic_cast<Set*>(setRef.getEntity());
	TreeEntry* entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());

	TreeMap::TreeEntry::values(entry->getLeft(), setRef);
	set->add(entry->value());
	TreeMap::TreeEntry::values(entry->getRight(), setRef);
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

TreeMap::TreeMap(type_t keyType, type_t valueType) :
		Map(keyType, valueType) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::get(Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);

	return TreeMap::TreeEntry::get(mRootEntry, key);
}

Reference TreeMap::put(Reference key, Reference value) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);
	if (!value.isNull()) {
		typeCheck(value, mValueType);
	}

	return put0(key, value);
}

Reference TreeMap::put0(Reference key, Reference value) {
	Reference oldValue = TreeMap::TreeEntry::get(mRootEntry, key);
	mRootEntry = TreeMap::TreeEntry::add(mRootEntry, key, value);

	if (!oldValue.isNull()) {
		return oldValue;
	} else {
		mSize++;
		return value;
	}
}

Reference TreeMap::remove(Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);

	Reference oldValue = TreeMap::TreeEntry::get(mRootEntry, key);
	if (oldValue.isNull()) {
		return Reference();
	} else {
		mSize--;
		mRootEntry = TreeMap::TreeEntry::remove(mRootEntry, key);
		return oldValue;
	}
}

Reference TreeMap::firstKey() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference minEntryRef = TreeMap::TreeEntry::minEntry(mRootEntry);
	if (minEntryRef.isNull) {
		return Reference();
	}

	Entry *minEntry = dynamic_cast<Entry*>(minEntryRef.getEntity());
	return minEntry->key();
}

Reference TreeMap::firstEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	return TreeMap::TreeEntry::minEntry(mRootEntry);
}

Reference TreeMap::lastEntry() {
	if (mRootEntry.isNull) {
		return Reference();
	}

	return TreeMap::TreeEntry::maxEntry(mRootEntry);
}

Reference TreeMap::lastKey() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference maxEntryRef = TreeMap::TreeEntry::maxEntry(mRootEntry);
	Entry *entry = dynamic_cast<Entry*>(maxEntryRef.getEntity());
	return entry->key();
}

Reference TreeMap::floorKey(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference floorEntryRef = TreeMap::TreeEntry::floorEntry(mRootEntry,
			keyRef);
	if (floorEntryRef.isNull()) {
		return Reference();
	}

	Entry *floorEntry = dynamic_cast<Entry*>(floorEntryRef.getEntity());
	return floorEntry->key();
}

Reference TreeMap::floorEntry(Reference keyRef) {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	return TreeMap::TreeEntry::floorEntry(mRootEntry, keyRef);
}

Reference TreeMap::ceilEntry(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	return TreeMap::TreeEntry::ceilEntry(mRootEntry, keyRef);
}

Reference TreeMap::ceilKey(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference ceilEntryRef = TreeMap::TreeEntry::ceilEntry(mRootEntry, keyRef);
	if (ceilEntryRef.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ceilEntryRef.getEntity());
	return entry->key();
}

Reference TreeMap::putIfAbsent(Reference key, Reference value) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);
	if (!value.isNull()) {
		typeCheck(value, mValueType);
	}

	Reference oldValue = TreeMap::TreeEntry::get(mRootEntry, key);
	if (oldValue.isNull()) {
		mRootEntry = TreeMap::TreeEntry::add(oldValue, key, value);
		mSize++;
		return value;
	} else {
		return oldValue;
	}
}

void TreeMap::putAll(Reference ref) {
	if (ref.isNull()) {
		return;
	}

	typeCheck(ref, Map::type());

	Map *map = dynamic_cast<Map*>(ref.getEntity());
	typeCheck(map->mKeyType, mKeyType);
	typeCheck(map->mValueType, mValueType);

	Reference keyRef = map->keySet();
	Set *keySet = dynamic_cast<Set*>(keyRef.getEntity());
	Reference iteratorRef = keySet->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference key = iterator->next();
		Reference value = map->get(key);
		put0(key, value);
	}
}

Reference TreeMap::replace(Reference key, Reference value) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);

	if (!value.isNull()) {
		typeCheck(value, mValueType);
	}

	return TreeMap::TreeEntry::replace(mRootEntry, key, value);
}

bool TreeMap::containsKey(Reference key) {
	if (key.isNull()) {
		return false;
	}

	typeCheck(key, mKeyType);

	return TreeMap::TreeEntry::containsKey(mRootEntry, key);
}

bool TreeMap::containsValue(Reference value) {
	if (value.isNull()) {
		return false;
	}

	typeCheck(value, mValueType);

	return TreeMap::TreeEntry::containsValue(mRootEntry, value);
}

void TreeMap::clear() {
	TreeMap::TreeEntry::clear(mRootEntry);
	mRootEntry = Reference();
}

Reference TreeMap::keySet() {
	Reference result = Reference(new TreeSet(mKeyType));

	TreeMap::TreeEntry::keys(mRootEntry, result);

	return result;
}

Reference TreeMap::values() {
	Reference result = Reference(new TreeSet(mKeyType));

	TreeMap::TreeEntry::values(mRootEntry, result);

	return result;
}

type_t TreeMap::type() {
	return CLASS_SERIAL;
}

bool TreeMap::instanceof(type_t type) {
	return CLASS_SERIAL == type || Map::instanceof(type);
}

void TreeMap::typeCheck(Reference ref, type_t type) {
	if (!ref.getEntity()->instanceof(type)) {
		//cast an exception
	}
}

void TreeMap::typeCheck(type_t t1, type_t t2) {
	if (t1 != t2) {
		//cast an exception
	}
}

} /* namespace utils */
} /* namespace tl */
