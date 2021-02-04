/*
 * TreeMap.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#include "TreeMap.h"
#include "../lang/Math.h"
#include "../lang/String.h"
#include "../lang/Array.h"

namespace tl {
namespace utils {

using lang::String;
using lang::Array;

TreeMap::TreeMap(type_t keyType, type_t valueType)
	: NavigableMap(keyType, valueType) {
	// TODO Auto-generated constructor stub
	mRootEntry = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
	TreeEntry::clear(mRootEntry);
	mRootEntry = Reference();
}

hash_t TreeMap::TreeEntry::genHashCode(type_t type) {
	hash_t keyHash = mKey.isNull() ? 0 : mKey.getEntity()->mHashCode;
	hash_t valueHash = mValue.isNull() ? 0 : mValue.getEntity()->mHashCode();
	return (((keyHash ^ valueHash) << 32) >> 32) | (type << 32);
}

TreeMap::TreeEntry::TreeEntry(Reference key, Reference value, Reference parent)
	: Entry(key, value), mParent(parent) {
	mHeight = 0;

	mHashCode = genHashCode(CLASS_SERIAL);
	mWeight = key.getEntity()->mHashCode;
}

bool TreeMap::TreeEntry::containsKey(Reference ref, Reference key) {
	return !TreeMap::TreeEntry::getEntry(ref, key).isNull();
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

Reference TreeMap::TreeEntry::getEntry(Reference ref, Reference key) {
	if (ref.isNull()) {
		return Reference();
	}

	if (key.isNull()) {
		return Reference();
	}

	while (!ref.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
		if (entry->mWeight == key.getEntity()->mHashCode) {
			break;
		}
		if (entry->mWeight < key.getEntity()->mHashCode) {
			ref = entry->getRight();
		} else {
			ref = entry->getLeft();
		}
	}

	if (ref.isNull()) {
		return Reference();
	} else {
		return ref;
	}
}

tlint TreeMap::TreeEntry::height(Reference ref) {
	if (ref.isNull()) {
		return -1;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	return entry->mHeight;
}

Reference TreeMap::TreeEntry::rightRotate(Reference ref) {
	TreeEntry *root = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference parent = root->getParent();
	Reference leftRef = root->getLeft();
	TreeEntry *left = dynamic_cast<TreeEntry*>(leftRef.getEntity());
	Reference rightRef = left->getRight();

	root->setLeft(rightRef);
	if (!rightRef.isNull()) {
		TreeEntry *right = dynamic_cast<TreeEntry*>(rightRef.getEntity());
		right->setParent(ref);
	}

	left->setRight(ref);
	root->setParent(leftRef);

	left->setParent(parent);

	root->setHeight(
		lang::Math::max(TreeMap::TreeEntry::height(root->getLeft()),
			TreeMap::TreeEntry::height(root->getRight())) + 1);
	left->setHeight(
		lang::Math::max(TreeMap::TreeEntry::height(left->getLeft()),
			TreeMap::TreeEntry::height(left->getRight())) + 1);

	return leftRef;
}

Reference TreeMap::TreeEntry::leftRotate(Reference ref) {
	TreeEntry *root = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference parent = root->getParent();
	Reference rightRef = root->getRight();
	TreeEntry *right = dynamic_cast<TreeEntry*>(rightRef.getEntity());
	Reference leftRef = right->getLeft();

	root->setRight(leftRef);
	if (!leftRef.isNull()) {
		TreeEntry *left = dynamic_cast<TreeEntry*>(leftRef.getEntity());
		left->setParent(ref);
	}

	right->setLeft(ref);
	root->setParent(rightRef);

	right->setParent(parent);

	root->setHeight(
		lang::Math::max(TreeMap::TreeEntry::height(root->getLeft()),
			TreeMap::TreeEntry::height(root->getRight())) + 1);
	right->setHeight(
		lang::Math::max(TreeMap::TreeEntry::height(right->getLeft()),
			TreeMap::TreeEntry::height(right->getRight())) + 1);

	return rightRef;
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
	Reference valueRef, Reference parent) {
	if (ref.isNull()) {
		return Reference(new TreeEntry(keyRef, valueRef, parent));
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference key = entry->value();
	if (key.equals(keyRef)) {
		entry->mValue = valueRef;
	} else if (keyRef.getEntity()->mHashCode > entry->mWeight) {
		TreeMap::TreeEntry::add(entry->getRight(), keyRef, valueRef, ref);
	} else {
		TreeMap::TreeEntry::add(entry->getLeft(), keyRef, valueRef, ref);
	}

	return TreeMap::TreeEntry::balance(ref);
}

Reference TreeMap::TreeEntry::remove(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->mKey.equals(keyRef)) {
		Reference parent = entry->getParent();
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
			ref =
				entry->getLeft().isNull() ?
					entry->getRight() : entry->getLeft();
			if (!ref.isNull()) {
				entry = dynamic_cast<TreeEntry*>(ref.getEntity());
				entry->setParent(parent);
			}
		}
	} else if (entry->mWeight < keyRef.getEntity()->mHashCode) {
		entry->getRight() = TreeMap::TreeEntry::remove(entry->getRight(),
			keyRef);
	} else {
		entry->getLeft() = TreeMap::TreeEntry::remove(entry->getLeft(), keyRef);
	}

	return TreeMap::TreeEntry::balance(ref);
}

Reference TreeMap::TreeEntry::replace(Reference root, Reference keyRef,
	Reference valueRef) {
	Reference entryRef = TreeEntry::getEntry(root, keyRef);
	if (!entryRef.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
		Reference oldValue = entry->value();
		entry->setValue(valueRef);
		return oldValue;
	} else {
		return Reference();
	}
}

Reference TreeMap::TreeEntry::getValue(Reference root, Reference keyRef) {
	if (root.isNull()) {
		return Reference();
	}

	Reference entryRef = TreeMap::TreeEntry::getEntry(root, keyRef);
	if (!entryRef.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
		return entry->value();
	} else {
		return Reference();
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
	if (ref.isNull()) {
		return Reference();
	}

	Reference current = ref;
	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	while (!entry->getLeft().isNull()) {
		current = entry->getLeft();
		entry = dynamic_cast<TreeEntry*>(current.getEntity());
	}

	return current;
}

Reference TreeMap::TreeEntry::maxEntry(Reference ref) {
	if (ref.isNull()) {
		return Reference();
	}

	Reference current = ref;
	TreeEntry *entry = dynamic_cast<TreeEntry*>(current.getEntity());
	while (!entry->getRight().isNull()) {
		current = entry->getRight();
		entry = dynamic_cast<TreeEntry*>(current.getEntity());
	}

	return current;
}

Reference TreeMap::TreeEntry::floorEntry(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

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

Reference TreeMap::TreeEntry::ceilingEntry(Reference ref, Reference keyRef) {
	if (ref.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());

	if (entry->mWeight == keyRef.getEntity()->mHashCode) {
		return ref;
	} else if (entry->mWeight < keyRef.getEntity()->mHashCode) {
		if (entry->getRight().isNull()) {
			return Reference();
		} else {
			return TreeMap::TreeEntry::ceilingEntry(entry->getRight(), keyRef);
		}
	} else {
		if (entry->getLeft().isNull()) {
			return ref;
		} else {
			return TreeMap::TreeEntry::ceilingEntry(entry->getLeft(), keyRef);
		}
	}
}

Reference TreeMap::TreeEntry::getLeft() {
	return mLeft;
}

Reference TreeMap::TreeEntry::getRight() {
	return mRight;
}

Reference TreeMap::TreeEntry::getParent() {
	return mParent;
}

void TreeMap::TreeEntry::setLeft(Reference ref) {
	mLeft = ref;
}

void TreeMap::TreeEntry::setRight(Reference ref) {
	mRight = ref;
}

void TreeMap::TreeEntry::setParent(Reference ref) {
	mParent = ref;
}

tlint TreeMap::TreeEntry::getHeight() {
	return mHeight;
}

void TreeMap::TreeEntry::setHeight(tlint height) {
	mHeight = height;
}

Reference TreeMap::TreeEntry::toString() {
	Reference keyStr =
		mKey.isNull() ?
			Reference(new String("null")) : mKey.getEntity()->toString();
	Reference valueStr =
		mValue.isNull() ?
			Reference(new String("null")) : mValue.getEntity()->toString();

	String *keyString = dynamic_cast<String*>(keyStr.getEntity());
	Reference tmp = keyString->append('=');
	String *tmpString = dynamic_cast<String*>(tmp.getEntity());
	return tmpString->append(valueStr);
}

Reference TreeMap::TreeEntry::successor(Reference root, Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	Reference entryRef = TreeMap::TreeEntry::getEntry(root, key);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	if (!entry->getRight().isNull()) {
		Reference s = entry->getRight();
		TreeEntry *e = dynamic_cast<TreeEntry*>(s.getEntity());
		while (!e->getLeft().isNull()) {
			s = e->getLeft();
			e = dynamic_cast<TreeEntry*>(s.getEntity());
		}

		return s;
	} else {
		Reference p = entry->getParent();
		Reference ch = entryRef;
		while (!p.isNull()) {
			TreeEntry *parent = dynamic_cast<TreeEntry*>(p.getEntity());
			if (!parent->getRight().equals(ch)) {
				break;
			}
			ch = p;
			p = parent->getParent();
		}

		return p;
	}
}

Reference TreeMap::TreeEntry::predecessor(Reference root, Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	Reference entryRef = TreeMap::TreeEntry::getEntry(root, key);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	if (!entry->getLeft().isNull()) {
		Reference p = entry->getLeft();
		TreeEntry *e = dynamic_cast<TreeEntry*>(p.getEntity());
		while (!e->getRight().isNull()) {
			p = e->getRight();
			e = dynamic_cast<TreeEntry*>(p.getEntity());
		}

		return p;
	} else {
		Reference p = entry->getParent();
		Reference ch = entryRef;
		while (!p.isNull()) {
			TreeEntry *parent = dynamic_cast<TreeEntry*>(p.getEntity());
			if (!parent->getLeft().equals(ch)) {
				break;
			}
			ch = p;
			p = parent->getParent();
		}

		return p;
	}
}

type_t TreeMap::TreeEntry::type() {
	return CLASS_SERIAL;
}

bool TreeMap::TreeEntry::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Map::Entry::instanceof(type);
}

Reference TreeMap::get(Reference key) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);

	return TreeMap::TreeEntry::getValue(mRootEntry, key);
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
	Reference oldValue = TreeMap::TreeEntry::getValue(mRootEntry, key);
	mRootEntry = TreeMap::TreeEntry::add(mRootEntry, key, value, Reference());

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

	Reference oldValue = TreeMap::TreeEntry::getValue(mRootEntry, key);
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

Reference TreeMap::ceilingEntry(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	return TreeMap::TreeEntry::ceilingEntry(mRootEntry, keyRef);
}

Reference TreeMap::ceilingKey(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference ceilingEntryRef = TreeMap::TreeEntry::ceilingEntry(mRootEntry,
		keyRef);
	if (ceilingEntryRef.isNull()) {
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ceilingEntryRef.getEntity());
	return entry->key();
}

Reference TreeMap::lowerEntry(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (TreeMap::TreeEntry::containsKey(mRootEntry, keyRef)) {
		return TreeMap::TreeEntry::predecessor(mRootEntry, keyRef);
	} else {
		return TreeMap::TreeEntry::floorEntry(mRootEntry, keyRef);
	}
}

Reference TreeMap::lowerKey(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (TreeMap::TreeEntry::containsKey(mRootEntry, keyRef)) {
		Reference entryRef = TreeMap::TreeEntry::predecessor(mRootEntry,
			keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	} else {
		Reference entryRef = floorEntry(keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	}
}

Reference TreeMap::higherEntry(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (TreeMap::TreeEntry::containsKey(mRootEntry, keyRef)) {
		return TreeMap::TreeEntry::successor(mRootEntry, keyRef);
	} else {
		return TreeMap::TreeEntry::ceilingEntry(mRootEntry, keyRef);
	}
}

Reference TreeMap::higherKey(Reference keyRef) {
	if (keyRef.isNull()) {
		return Reference();
	}

	typeCheck(keyRef, mKeyType);

	if (TreeMap::TreeEntry::containsKey(mRootEntry, keyRef)) {
		Reference entryRef = TreeMap::TreeEntry::successor(mRootEntry, keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	} else {
		Reference entryRef = TreeMap::TreeEntry::ceilingEntry(mRootEntry,
			keyRef);
		if (!entryRef.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
			return entry->key();
		} else {
			return Reference();
		}
	}

}

Reference TreeMap::pollFirstEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference firstEntryRef = TreeMap::TreeEntry::minEntry(mRootEntry);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(firstEntryRef.getEntity());
	TreeMap::TreeEntry::remove(mRootEntry, entry->key());
	mSize--;

	return firstEntryRef;
}

Reference TreeMap::pollLastEntry() {
	if (mRootEntry.isNull()) {
		return Reference();
	}

	Reference lastEntryRef = TreeMap::TreeEntry::maxEntry(mRootEntry);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(lastEntryRef.getEntity());
	TreeMap::TreeEntry::remove(mRootEntry, entry->key());
	mSize--;

	return lastEntryRef;
}

Reference TreeMap::putIfAbsent(Reference key, Reference value) {
	if (key.isNull()) {
		return Reference();
	}

	typeCheck(key, mKeyType);
	if (!value.isNull()) {
		typeCheck(value, mValueType);
	}

	Reference oldValue = TreeMap::TreeEntry::getValue(mRootEntry, key);
	if (oldValue.isNull()) {
		mRootEntry = TreeMap::TreeEntry::add(oldValue, key, value, Reference());
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
	Reference entrySet = map->entrySet();
	Set *entries = dynamic_cast<Set*>(entrySet.getEntity());
	Reference iteratorRef = entries->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	while (iterator->hasNext()) {
		Reference element = iterator->next();
		Map::Entry *entry = dynamic_cast<Map::Entry*>(element.getEntity());
		put(entry->key(), entry->value());
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
	mSize = 0;
}

Reference TreeMap::keySet() {
	return mKeySet;
//	return Reference(new KeySet(Reference(this, false)));
}

Reference TreeMap::values() {
//	return mValues;
	return Reference(new Values(Reference(this, false)));
}

Reference TreeMap::entrySet() {
	return Reference(new EntrySetView(Reference(this, false)));
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

TreeMap::Values::Values(Reference map) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void TreeMap::Values::typeCheck(Reference ref, type_t type) {
	if (!ref.getEntity()->instanceof(type)) {
		//cast an exception
	}
}

void TreeMap::Values::typeCheck(type_t t1, type_t t2) {
	if (t1 != t2) {
		//cast an exception
	}
}

void TreeMap::Values::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

bool TreeMap::Values::contains(Reference value) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsValue(value);

}

bool TreeMap::Values::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	typeCheck(collection->mElementType, map->mValueType);

	bool result = true;
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result && map->containsValue(element);
		if (!result) {
			break;
		}
	}

	return result;
}

bool TreeMap::Values::add(Reference ref) {
	//cast NotSupportedOperationException
	return false;
}

bool TreeMap::Values::addAll(Reference ref) {
	//cast NotSupportedOperationException
	return false;
}

Reference TreeMap::Values::toArray() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(map->mValueType, size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());
	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	tlint index = 0;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		arr->set(index, element);
		index++;
	}

	return rtval;
}

type_t TreeMap::Values::type() {
	return CLASS_SERIAL;
}

bool TreeMap::Values::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Collection::instanceof(type);
}

tlint TreeMap::Values::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

bool TreeMap::Values::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size() == 0;
}
bool TreeMap::Values::remove(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference entryRef = map->firstEntry();
	while (!entryRef.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeMap*>(entryRef.getEntity());
		if (entry->value().equals(ref)) {
			map->remove(entry->key());
			return true;
		}
		entryRef = TreeMap::TreeEntry::successor(mRootEntry, entry->key());
	}
	return false;
}

bool TreeMap::Values::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool modified = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		if (collection->contains(element)) {
			iterator->remove();
			modified = true;
		}
	}

	return modified;
}

Reference TreeMap::Values::iterator() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return Reference(new ValueIterator(map->firstEntry()));
}

TreeMap::EntrySetView::EntrySetView(Reference map)
	: NavigableSet(Map::Entry::type()) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

void TreeMap::EntrySetView::typeCheck(Reference ref, type_t type) {
	if (!ref.getEntity()->instanceof(type)) {
		//cast an exception
	}
}

bool TreeMap::EntrySetView::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference resultRef = TreeMap::TreeEntry::getEntry(map->mRootEntry, ref);
	if (resultRef.isNull()) {
		return false;
	}

	Map::Entry *result = dynamic_cast<Map::Entry*>(resultRef.getEntity());
	if (!result->key().equals(entry->key())
		|| !result->value().equals(entry->value())) {
		return false;
	}

	return true;
}

bool TreeMap::EntrySetView::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result && TreeMap::EntrySetView::contains(element);
		if (!result) {
			return result;
		}
	}

	return result;
}

void TreeMap::EntrySetView::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

bool TreeMap::EntrySetView::add(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->put(entry->key(), entry->value());
}

bool TreeMap::EntrySetView::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());

	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result || add(element);
	}

	return result;
}

bool TreeMap::EntrySetView::remove(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference entryRef = TreeMap::TreeEntry::getEntry(map->mRootEntry,
		entry->key());
	if (entryRef.isNull()) {
		return false;
	}

	TreeEntry *requiredEntry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	if (requiredEntry->value().equals(entry->value())) {
		map->remove(entry->key());
		return true;
	}

	return false;
}

bool TreeMap::EntrySetView::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	typeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		result = result || remove(element);
	}

	return result;
}

Reference TreeMap::EntrySetView::iterator() {
	return EntryIterator(mMap);
}

bool TreeMap::EntrySetView::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->isEmpty();
}

tlint TreeMap::EntrySetView::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

Reference TreeMap::EntrySetView::toArray() {
	Reference rtval = Reference(new Array(Map::Entry::type(), size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());
	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	tlint index = 0;
	while (iterator->hasNext()) {
		Reference element = iterator->next();
		arr->set(index, element);
		index++;
	}

	return rtval;
}

type_t TreeMap::EntrySetView::type() {
	return CLASS_SERIAL;
}

bool TreeMap::EntrySetView::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Set::instanceof(type);
}

//Reference TreeMap::EntrySetView::first() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return TreeMap::TreeEntry::minEntry(map->mRootEntry);
//}
//
//Reference TreeMap::EntrySetView::last() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return TreeMap::TreeEntry::maxEntry(map->mRootEntry);
//}
//
//Reference TreeMap::EntrySetView::pollFirst() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return map->pollFirstEntry();
//}
//
//Reference TreeMap::EntrySetView::pollLast() {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//
//	return map->pollLastEntry();
//}
//
//Reference TreeMap::EntrySetView::subSet(Reference fromElement,
//	Reference toElement) {
//	return subSet(fromElement, true, toElement, false);
//}
//
//Reference TreeMap::EntrySetView::subSet(Reference fromElement,
//	bool fromInclusive, Reference toElement, bool toInclusive) {
//
//}

TreeMap::PrivateEntryIterator::PrivateEntryIterator(Reference map) {
	mMap = map;

	TreeMap *treeMap = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = treeMap->firstEntry();
	mLastReturned = Reference();

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::PrivateEntryIterator::hasNext() {
	return !mNext.isNull();
}

Reference TreeMap::PrivateEntryIterator::nextEntry() {
	Reference e = mNext;
	if (e.isNull()) {
		//cast NoSuchElementException
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(e.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = TreeMap::TreeEntry::successor(map->mRootEntry, entry->key());
	mLastReturned = e;

	return e;
}

Reference TreeMap::PrivateEntryIterator::previousEntry() {
	Reference e = mNext;
	if (e.isNull()) {
		//cast NoSuchElementException
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(e.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = TreeMap::TreeEntry::predecessor(map->mRootEntry, entry->key());
	mLastReturned = e;

	return e;
}

void TreeMap::PrivateEntryIterator::remove() {
	if (mLastReturned.isNull()) {
		//cast an exception
	}

	TreeEntry *lastReturned =
		dynamic_cast<TreeEntry*>(mLastReturned.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->remove(lastReturned->key());

	mLastReturned = Reference();
}

type_t TreeMap::PrivateEntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::PrivateEntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterator::instanceof(type);
}

TreeMap::EntryIterator::EntryIterator(Reference map)
	: PrivateEntryIterator(map) {

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::EntryIterator::next() {
	return nextEntry();
}

type_t TreeMap::EntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::EntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::ValueIterator::ValueIterator(Reference map)
	: PrivateEntryIterator(map) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::ValueIterator::next() {
	Reference entryRef = PrivateEntryIterator::nextEntry();
	TreeEntry *entry = dynamic_cast<TreeEntry*>(entryRef.getEntity());
	return entry->value();
}

type_t TreeMap::ValueIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::ValueIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::KeyIterator::KeyIterator(Reference map)
	: PrivateEntryIterator(map) {

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::KeyIterator::next() {
	Reference entryRef = PrivateEntryIterator::nextEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

type_t TreeMap::KeyIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::KeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::DescendingKeyIterator::DescendingKeyIterator(Reference map)
	: PrivateEntryIterator(map) {
	TreeMap *treeMap = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = treeMap->lastEntry();

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::DescendingKeyIterator::next() {
	Reference entryRef = TreeMap::PrivateEntryIterator::previousEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

type_t TreeMap::DescendingKeyIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::DescendingKeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::KeySet::KeySet(type_t elementType, Reference map)
	: NavigableSet(elementType) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::KeySet::add(Reference ref) {
	return false;
}

bool TreeMap::KeySet::addAll(Reference ref) {
	return false;
}

bool TreeMap::KeySet::remove(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return !map->remove(ref).isNull();
}

bool TreeMap::KeySet::removeAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
		//cast an exception
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	bool result = false;
	while (iterator->hasNext()) {
		Reference key = iterator->next();
		result = result || !map->remove(key).isNull();
	}

	return result;
}

bool TreeMap::KeySet::contains(Reference ref) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsKey(ref);
}

bool TreeMap::KeySet::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.getEntity()->instanceof(Collection::type())) {
		//cast an exception
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	bool result = true;
	while (iterator->hasNext()) {
		Reference key = iterator->next();
		result = result && map->containsKey(key);
		if (!result) {
			return result;
		}
	}

	return result;
}

void TreeMap::KeySet::clear() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

Reference TreeMap::KeySet::ceiling(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->ceilingKey(keyRef);
}

Reference TreeMap::KeySet::floor(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->floorKey(keyRef);
}

Reference TreeMap::KeySet::lower(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lowerKey(keyRef);
}

Reference TreeMap::KeySet::higher(Reference keyRef) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->higherKey(keyRef);
}

Reference TreeMap::KeySet::first() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->firstKey();
}

Reference TreeMap::KeySet::last() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lastKey();
}

Reference TreeMap::KeySet::pollLast() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference entryRef = map->pollLastEntry();
	if (entryRef.isNull()) {
		return Reference();
	}

	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

Reference TreeMap::KeySet::pollFirst() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	Reference entryRef = map->pollFirstEntry();
	if (entryRef.isNull()) {
		return Reference();
	}

	Map::Entry *entry = dynamic_cast<Map::Entry*>(entryRef.getEntity());
	return entry->key();
}

Reference TreeMap::KeySet::toArray() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference rtval = Reference(new Array(mElementType, map->size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference iteratorRef = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());
	tlint index = 0;

	while (iterator->hasNext()) {
		arr->set(index, iterator->next());
		index++;
	}

	return rtval;
}

tlint TreeMap::KeySet::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

bool TreeMap::KeySet::isEmpty() {
	return size() == 0;
}

Reference TreeMap::KeySet::iterator() {
	return Reference(new KeyIterator(mMap));
}

type_t TreeMap::KeySet::type() {
	return CLASS_SERIAL;
}

bool TreeMap::KeySet::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || NavigableSet::instanceof(type);
}

//Reference TreeMap::KeySet::subSet(Reference fromElement, Reference toElement) {
//	return subSet(fromElement, true, toElement, false);
//}
//
//Reference TreeMap::KeySet::subSet(Reference fromElement, bool fromInclusive,
//	Reference toElement, bool toInclusive) {
//	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
//	Reference subMapRef = map->subMap(fromElement, fromInclusive, toElement,
//		toInclusive);
//	TreeMap *subMap = dynamic_cast<TreeMap*>(subMapRef.getEntity());
//	return subMap->keySet();
//}

} /* namespace utils */
} /* namespace tl */
