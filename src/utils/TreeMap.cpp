/*
 * TreeMap.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#include <tl/utils/TreeMap.h>
#include <tl/lang/UnsupportedOperationException.h>
#include <tl/lang/Comparable.h>
#include <tl/lang/Array.h>
#include <tl/utils/NoSuchElementException.h>
#include <tl/utils/Comparator.h>

namespace tl {
namespace utils {

using lang::UnsupportedOperationException;
using lang::Comparable;
using lang::Array;

TreeMap::TreeMap(type_t keyType, type_t valueType, Reference comparator)
	: Map(keyType, valueType), SortedMap(keyType, valueType, comparator) {
	// TODO Auto-generated constructor stub
	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::~TreeMap() {
	// TODO Auto-generated destructor stub
	clear();
}

void TreeMap::clear(Reference currentEntry) {
	if (currentEntry.isNull()) {
		return;
	}

	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
	clear(current->getLeft());
	clear(current->getRight());

	current->setLeft(Reference());
	current->setRight(Reference());
}

void TreeMap::leftRotate(Reference ref) {
	dismissNull(ref);

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference parentEntry = entry->getParent();
	Reference rightEntry = entry->getRight();
	TreeEntry *right = dynamic_cast<TreeEntry*>(rightEntry.getEntity());

	Reference newRightEntry = right->getLeft();
	entry->setRight(newRightEntry);

	if (!newRightEntry.isNull()) {
		TreeEntry *newRight =
			dynamic_cast<TreeEntry*>(newRightEntry.getEntity());
		newRight->setParent(ref);
	}

	right->setParent(parentEntry);
	entry->setParent(rightEntry);

	if (parentEntry.isNull()) {
		mRoot = rightEntry;
	} else {
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (parent->getLeft().equals(ref)) {
			parent->setLeft(rightEntry);
		} else {
			parent->setRight(rightEntry);
		}
	}
}

void TreeMap::rightRotate(Reference ref) {
	dismissNull(ref);

	TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
	Reference parentEntry = entry->getParent();
	Reference leftEntry = entry->getLeft();
	TreeEntry *left = dynamic_cast<TreeEntry*>(leftEntry.getEntity());

	Reference newLeftEntry = left->getRight();
	entry->setLeft(newLeftEntry);

	if (!newLeftEntry.isNull()) {
		TreeEntry *newLeft = dynamic_cast<TreeEntry*>(newLeftEntry.getEntity());
		newLeft->setParent(ref);
	}

	left->setParent(parentEntry);
	entry->setParent(leftEntry);

	if (parentEntry.isNull()) {
		mRoot = leftEntry;
	} else {
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (parent->getLeft().equals(ref)) {
			parent->setLeft(leftEntry);
		} else {
			parent->setRight(leftEntry);
		}
	}
}

Reference TreeMap::addEntry(Reference key, Reference value) {
	Reference currentEntry = mRoot;
	Reference lastEntry;
	Comparable *comparable = dynamic_cast<Comparable*>(key.getEntity());

	while (!currentEntry.isNull()) {
		lastEntry = currentEntry;
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		Reference currentKey = current->key();

		if (comparable->compareTo(currentKey) == 0) {
			Reference oldValue = current->value();
			current->setValue(value);
			return oldValue;
		} else {
			if (comparable->compareTo(currentKey) < 0) {
				currentEntry = current->getLeft();
			} else {
				currentEntry = current->getRight();
			}
		}
	}

	Reference newEntry = Reference(
		new TreeEntry(mKeyType, key, mValueType, value));
	TreeEntry *entry = dynamic_cast<TreeEntry*>(newEntry.getEntity());
	entry->setParent(lastEntry);
	if (lastEntry.isNull()) {
		mRoot = newEntry;
	} else {
		TreeEntry *last = dynamic_cast<TreeEntry*>(lastEntry.getEntity());
		if (comparable->compareTo(last->key()) < 0) {
			last->setLeft(newEntry);
		} else {
			last->setRight(newEntry);
		}
	}

	addFixUp(newEntry);

	mSize++;
	return Reference();
}

Reference TreeMap::addEntryUsingComparator(Reference key, Reference value) {
	Reference currentEntry = mRoot;
	Reference lastEntry;
	Comparator *comparator = dynamic_cast<Comparator*>(mComparator.getEntity());

	while (!currentEntry.isNull()) {
		lastEntry = currentEntry;
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (comparator->compare(key, current->key()) == 0) {
			Reference oldValue = current->value();
			current->setValue(value);
			return oldValue;
		}

		if (comparator->compare(key, current->key()) < 0) {
			currentEntry = current->getLeft();
		} else {
			currentEntry = current->getRight();
		}
	}

	Reference newEntry = Reference(
		new TreeEntry(mKeyType, key, mValueType, value));
	TreeEntry *entry = dynamic_cast<TreeEntry*>(newEntry.getEntity());
	entry->setParent(lastEntry);
	if (lastEntry.isNull()) {
		mRoot = newEntry;
	} else {
		TreeEntry *last = dynamic_cast<TreeEntry*>(lastEntry.getEntity());
		if (comparator->compare(key, last->key()) < 0) {
			last->setLeft(newEntry);
		} else {
			last->setRight(newEntry);
		}
	}

	addFixUp(newEntry);

	mSize++;
	return Reference();
}

void TreeMap::addFixUp(Reference currentEntry) {
	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());

	Reference parentEntry = current->getParent();
	Reference gparentEntry;

	while (!parentEntry.isNull()) {
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (parent->getColor() != TreeEntry::RED) {
			break;
		}

		gparentEntry = parent->getParent();
		TreeEntry *gparent = dynamic_cast<TreeEntry*>(gparentEntry.getEntity());

		if (gparent->getLeft().equals(parentEntry)) {
			Reference uncleEntry = gparent->getRight();
			if (!uncleEntry.isNull()) {
				TreeEntry *uncle =
					dynamic_cast<TreeEntry*>(uncleEntry.getEntity());
				if (uncle->getColor() == TreeEntry::RED) {
					uncle->setColor(TreeEntry::BLACK);
					parent->setColor(TreeEntry::BLACK);
					gparent->setColor(TreeEntry::RED);
					currentEntry = gparentEntry;
					parentEntry = gparent->getParent();
					continue;
				}
			}

			if (parent->getRight().equals(currentEntry)) {
				Reference tmp;
				leftRotate(parentEntry);
				tmp = parentEntry;
				parentEntry = currentEntry;
				currentEntry = tmp;
				current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
				parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
			}

			parent->setColor(TreeEntry::BLACK);
			gparent->setColor(TreeEntry::RED);
			rightRotate(gparentEntry);

			parentEntry = current->getParent();
		} else {
			Reference uncleEntry = gparent->getLeft();
			if (!uncleEntry.isNull()) {
				TreeEntry *uncle =
					dynamic_cast<TreeEntry*>(uncleEntry.getEntity());
				if (uncle->getColor() == TreeEntry::RED) {
					uncle->setColor(TreeEntry::BLACK);
					parent->setColor(TreeEntry::BLACK);
					gparent->setColor(TreeEntry::RED);
					currentEntry = gparentEntry;
					current = gparent;

					parentEntry = current->getParent();
					continue;
				}
			}

			if (parent->getLeft().equals(currentEntry)) {
				Reference tmp;
				rightRotate(parentEntry);
				tmp = parentEntry;
				parentEntry = currentEntry;
				currentEntry = tmp;

				current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
				parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
			}

			parent->setColor(TreeEntry::BLACK);
			gparent->setColor(TreeEntry::RED);
			leftRotate(gparentEntry);

			parentEntry = current->getParent();
		}
	}

	TreeEntry *root = dynamic_cast<TreeEntry*>(mRoot.getEntity());
	root->setColor(TreeEntry::BLACK);
}

void TreeMap::removeFixUp(Reference currentEntry) {
	Reference parentEntry;
	Reference brotherEntry;
	while (!currentEntry.isNull() && !currentEntry.equals(mRoot)) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (current->getColor() == TreeEntry::BLACK) {
			break;
		}

		parentEntry = current->getParent();
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (currentEntry.equals(parent->getLeft())) {
			brotherEntry = parent->getRight();
			TreeEntry *brother =
				dynamic_cast<TreeEntry*>(brotherEntry.getEntity());
			if (brother->getColor() == TreeEntry::RED) {
				brother->setColor(TreeEntry::BLACK);
				parent->setColor(TreeEntry::RED);
				leftRotate(parentEntry);
				brother = parent->getRight();
			}

			Reference leftEntry = brother->getLeft();
			Reference rightEntry = brother->getRight();
			if ((leftEntry.isNull()
				|| (dynamic_cast<TreeEntry*>(leftEntry.getEntity())->getColor()
					== TreeEntry::BLACK))
				&& (rightEntry.isNull()
					|| (dynamic_cast<TreeEntry*>(rightEntry.getEntity())->getColor()
						== TreeEntry::BLACK))) {
				brother->setColor(TreeEntry::RED);
				currentEntry = current->getParent();
				current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
			} else {
				if (rightEntry.isNull()
					|| (dynamic_cast<TreeEntry*>(rightEntry.getEntity())->getColor()
						== TreeEntry::BLACK)) {
					if (!leftEntry.isNull()) {
						TreeEntry *left =
							dynamic_cast<TreeEntry*>(leftEntry.getEntity());
						left->setColor(TreeEntry::BLACK);
					}
					brother->setColor(TreeEntry::RED);
					rightRotate(brotherEntry);
					brotherEntry = parent->getRight();
					brother =
						dynamic_cast<TreeEntry*>(brotherEntry.getEntity());
				}

				brother->setColor(parent->getColor());
				parent->setColor(TreeEntry::BLACK);
				rightEntry = brother->getRight();
				TreeEntry *right =
					dynamic_cast<TreeEntry*>(rightEntry.getEntity());
				right->setColor(TreeEntry::BLACK);
				leftRotate(parentEntry);

				currentEntry = mRoot;

				break;
			}
		} else {
			brotherEntry = parent->getLeft();
			TreeEntry *brother =
				dynamic_cast<TreeEntry*>(brotherEntry.getEntity());

			if (brother->getColor() == TreeEntry::RED) {
				brother->setColor(TreeEntry::BLACK);
				parent->setColor(TreeEntry::RED);
				rightRotate(parentEntry);
				brotherEntry = parent->getLeft();
				brother = dynamic_cast<TreeEntry*>(brotherEntry.getEntity());
			}

			Reference leftEntry = brother->getLeft();
			Reference rightEntry = brother->getRight();
			if ((leftEntry.isNull()
				|| (dynamic_cast<TreeEntry*>(leftEntry.getEntity())->getColor()
					== TreeEntry::BLACK))
				&& (rightEntry.isNull()
					|| (dynamic_cast<TreeEntry*>(rightEntry.getEntity())->getColor()
						== TreeEntry::BLACK))) {
				brother->setColor(TreeEntry::RED);
				currentEntry = current->getParent();
				current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
			} else {
				if (leftEntry.isNull()
					|| (dynamic_cast<TreeEntry*>(leftEntry.getEntity())->getColor()
						== TreeEntry::RED)) {
					if (!rightEntry.isNull()) {
						TreeEntry *right =
							dynamic_cast<TreeEntry*>(rightEntry.getEntity());
						right->setColor(TreeEntry::BLACK);
					}
					brother->setColor(TreeEntry::RED);
					leftRotate(brotherEntry);
					brotherEntry = parent->getLeft();
					brother =
						dynamic_cast<TreeEntry*>(brotherEntry.getEntity());
				}

				brother->setColor(TreeEntry::RED);
				parent->setColor(TreeEntry::BLACK);
				leftEntry = brother->getLeft();
				TreeEntry *left =
					dynamic_cast<TreeEntry*>(leftEntry.getEntity());
				left->setColor(TreeEntry::BLACK);
				rightRotate(parentEntry);

				currentEntry = mRoot;

				break;
			}
		}
	}

	if (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		current->setColor(TreeEntry::BLACK);
	}
}

Reference TreeMap::removeEntry(Reference key, Reference value) {
	Reference currentEntry = getEntry(key);

	if (currentEntry.isNull()) {
		return currentEntry;
	}

	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
	if (!value.isNull()) {
		if (!value.equals(current->value())) {
			return Reference();
		}
	}

	Reference oldValue = current->value();
	removeEntry0(currentEntry);
	mSize--;

	return oldValue;
}

Reference TreeMap::removeEntryUsingComparator(Reference key, Reference value) {
	Reference currentEntry = getEntryUsingComparator(key);

	if (currentEntry.isNull()) {
		return Reference();
	}

	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
	if (!value.isNull()) {
		if (!value.equals(current->value())) {
			return Reference();
		}
	}

	Reference oldValue = current->value();
	removeEntry0(currentEntry);
	mSize--;

	return oldValue;
}

void TreeMap::removeEntry0(Reference currentEntry) {
	Reference childEntry, parentEntry;
	bool color;

	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
	if (!current->getLeft().isNull() && !current->getRight().isNull()) {
		Reference replaceEntry = current->getRight();
		replaceEntry = getLowestEntry(replaceEntry);

		if (!current->getParent().isNull()) {
			TreeEntry *p = current->getParent();
			if (p->getLeft().equals(currentEntry)) {
				p->setLeft(replaceEntry);
			} else {
				p->setRight(replaceEntry);
			}
		} else {
			mRoot = replaceEntry;
		}

		TreeEntry *replace = dynamic_cast<TreeEntry*>(replaceEntry.getEntity());
		childEntry = replace->getRight();
		parentEntry = replace->getParent();

		color = replace->getColor();

		if (parentEntry.equals(currentEntry)) {
			parentEntry = replaceEntry;
		} else {
			if (!childEntry.isNull()) {
				TreeEntry *child =
					dynamic_cast<TreeEntry*>(childEntry.getEntity());
				child->setParent(parentEntry);
			}

			TreeEntry *parent =
				dynamic_cast<TreeEntry*>(parentEntry.getEntity());
			parent->setLeft(childEntry);
			replace->setRight(current->getRight());
			TreeEntry *right =
				dynamic_cast<TreeEntry*>(current->getRight().getEntity());
			right->setParent(replaceEntry);
		}

		replace->setParent(current->getParent());
		replace->setColor(current->getColor());
		replace->setLeft(current->getLeft());
		TreeEntry *left =
			dynamic_cast<TreeEntry*>(current->getLeft().getEntity());
		left->setParent(replaceEntry);

		if (color == TreeEntry::BLACK) {
			removeFixUp(childEntry);
		}

		currentEntry = Reference();
		return;
	}

	if (!current->getLeft().isNull()) {
		childEntry = current->getLeft();
	} else {
		childEntry = current->getRight();
	}

	parentEntry = current->getParent();
	color = current->getColor();

	if (!childEntry.isNull()) {
		TreeEntry *child = dynamic_cast<TreeEntry*>(childEntry.getEntity());
		child->setParent(parentEntry);
	}

	if (!parentEntry.isNull()) {
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (parent->getLeft().equals(currentEntry)) {
			parent->setLeft(childEntry);
		} else {
			parent->setRight(childEntry);
		}
	} else {
		mRoot = childEntry;
	}

	if (color == TreeEntry::BLACK) {
		removeFixUp(childEntry);
	}

	currentEntry = Reference();
}

Reference TreeMap::successor(Reference currentEntry) {
	dismissNull(currentEntry);

	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
	Reference next;
	if (!current->getRight().isNull()) {
		next = getLowestEntry(current->getRight());
		return next;
	}

	Reference parentEntry = current->getParent();
	Reference childEntry = currentEntry;
	while (!parentEntry.isNull()) {
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (!parent->getRight().equals(childEntry)) {
			break;
		}

		childEntry = parentEntry;
		parentEntry = parent->getParent();
	}

	return parentEntry;
}

Reference TreeMap::predecessor(Reference currentEntry) {
	dismissNull(currentEntry);

	TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
	Reference last;
	if (!current->getLeft().isNull()) {
		last = current->getLeft();
		last = getHighestEntry(last);
		return last;
	}

	Reference parentEntry = current->getParent();
	Reference childEntry = currentEntry;
	while (!parentEntry.isNull()) {
		TreeEntry *parent = dynamic_cast<TreeEntry*>(parentEntry.getEntity());
		if (!parent->getLeft().equals(childEntry)) {
			break;
		}

		childEntry = parentEntry;
		parentEntry = parent->getParent();
	}

	return parentEntry;
}

Reference TreeMap::getEntry0(Reference key) {
	Reference currentEntry = mRoot;
	Comparable *comparable = dynamic_cast<Comparable*>(key.getEntity());
	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (comparable->compareTo(current->key()) == 0) {
			break;
		}

		if (comparable->compareTo(current->key()) < 0) {
			currentEntry = current->getLeft();
		} else {
			currentEntry = current->getRight();
		}
	}

	return currentEntry;
}

Reference TreeMap::getLowestEntry(Reference currentEntry) {
	Reference lastEntry;
	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		lastEntry = currentEntry;
		currentEntry = current->getLeft();
	}

	return lastEntry;
}

Reference TreeMap::getHighestEntry(Reference currentEntry) {
	Reference lastEntry;
	while (!currentEntry.isNull()) {
		lastEntry = currentEntry;
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		currentEntry = current->getRight();
	}

	return lastEntry;
}

Reference TreeMap::getEntryUsingComparator(Reference key) {
	Reference currentEntry = mRoot;
	Comparator *comparator = dynamic_cast<Comparator*>(mComparator.getEntity());

	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (comparator->compare(key, current->key())) {
			break;
		}

		if (comparator->compare(key, current->key()) < 0) {
			currentEntry = current->getLeft();
		} else {
			currentEntry = current->getRight();
		}
	}

	return currentEntry;
}

Reference TreeMap::ceilingEntry(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	if (!mComparator.isNull()) {
		return ceilingEntryUsingComparator(key);
	}

	argumentTypeCheck(key, Comparable::type());
	return ceilingEntry0(key);
}

Reference TreeMap::ceilingEntry0(Reference key) {
	Reference lastEntry;
	Reference currentEntry = mRoot;
	Comparable *comparable = dynamic_cast<Comparable*>(key.getEntity());

	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (comparable->compareTo(current->key()) == 0) {
			lastEntry = currentEntry;
			break;
		}

		if (comparable->compareTo(current->key()) < 0) {
			lastEntry = currentEntry;
			currentEntry = predecessor(currentEntry);
			continue;
		}

		currentEntry = successor(currentEntry);
	}

	return lastEntry;
}

Reference TreeMap::ceilingEntryUsingComparator(Reference key) {
	Comparator *comparator = dynamic_cast<Comparator*>(mComparator.getEntity());

	Reference lastEntry;
	Reference currentEntry = mRoot;

	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (comparator->compare(key, current->key()) == 0) {
			lastEntry = currentEntry;
			break;
		}

		if (comparator->compare(key, current->key()) < 0) {
			lastEntry = currentEntry;
			currentEntry = predecessor(currentEntry);
			continue;
		}

		currentEntry = successor(currentEntry);
	}

	return lastEntry;
}

Reference TreeMap::floorEntry0(Reference key) {
	Comparable *comparable = dynamic_cast<Comparable*>(key.getEntity());
	Reference lastEntry;
	Reference currentEntry = mRoot;

	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());

		if (comparable->compareTo(current->key()) == 0) {
			lastEntry = currentEntry;
			break;
		}

		if (comparable->compareTo(current->key()) > 0) {
			lastEntry = currentEntry;
			currentEntry = successor(currentEntry);
			continue;
		}

		currentEntry = predecessor(currentEntry);
	}

	return lastEntry;
}

Reference TreeMap::floorEntryUsingComparator(Reference key) {
	Comparator *comparator = dynamic_cast<Comparator*>(mComparator.getEntity());
	Reference lastEntry;
	Reference currentEntry = mRoot;

	while (!currentEntry.isNull()) {
		TreeEntry *current = dynamic_cast<TreeEntry*>(currentEntry.getEntity());
		if (comparator->compare(key, current->key()) == 0) {
			lastEntry = currentEntry;
			break;
		}

		if (comparator->compare(key, current->key()) > 0) {
			lastEntry = currentEntry;
			currentEntry = successor(currentEntry);
			continue;
		}

		currentEntry = predecessor(currentEntry);
	}

	return lastEntry;
}

Reference TreeMap::getEntryByValue(Reference value) {
	Reference currentEntry = getLowestEntry(mRoot);

	while (!currentEntry.isNull()) {
		Map::Entry *entry = dynamic_cast<Map::Entry*>(currentEntry.getEntity());
		if (value.equals(entry->value())) {
			return currentEntry;
		}

		currentEntry = successor(currentEntry);
	}

	return Reference();
}

Reference TreeMap::ceilingKey(Reference key) {
	Reference targetEntry = ceilingEntry(key);
	if (!targetEntry.isNull()) {
		TreeEntry *target = dynamic_cast<TreeEntry*>(targetEntry.getEntity());
		return target->key();
	}

	return Reference();
}

void TreeMap::clear() {
	clear(mRoot);
	mRoot = Reference();

	mSize = 0;
}

bool TreeMap::containsKey(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	Reference target = getEntry(key);

	return !target.isNull();
}

bool TreeMap::containsValue(Reference value) {
	if (!value.isNull()) {
		argumentTypeCheck(value, mValueType);
	}

	Reference entry = getEntryByValue(value);
	return !entry.isNull();
}

bool TreeMap::contains(Reference key, Reference value) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	Reference target;
	if (!mComparator.isNull()) {
		target = getEntryUsingComparator(key);
	} else {
		target = getEntry(key);
	}

	if (target.isNull()) {
		return false;
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(target.getEntity());
	return entry->value().equals(value);
}

Reference TreeMap::entrySet() {
	return Reference(
		new EntrySetView(Map::Entry::type(), Reference(this, false)));
}

Reference TreeMap::firstEntry() {
	return getLowestEntry(mRoot);
}

Reference TreeMap::firstKey() {
	Reference lowestEntry = firstEntry();
	if (!lowestEntry.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(lowestEntry.getEntity());
		return entry->key();
	}

	return Reference();
}

Reference TreeMap::floorEntry(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	if (!mComparator.isNull()) {
		return floorEntryUsingComparator(key);
	}

	return floorEntry0(key);
}

Reference TreeMap::floorKey(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	Reference target;
	if (!mComparator.isNull()) {
		target = floorEntryUsingComparator(key);
	} else {
		target = floorEntry0(key);
	}

	if (!target.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(target.getEntity());
		return entry->key();
	}

	return Reference();
}

Reference TreeMap::get(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	Reference target;
	if (!mComparator.isNull()) {
		target = getEntryUsingComparator(key);
	} else {
		target = getEntry0(key);
	}

	if (!target.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(target.getEntity());
		return entry->value();
	}

	return Reference();
}

Reference TreeMap::getEntry(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	if (!mComparator.isNull()) {
		return getEntryUsingComparator(key);
	} else {
		return getEntry0(key);
	}
}

Reference TreeMap::higherEntry(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	Reference candidate;
	if (!mComparator.isNull()) {
		Comparator *comparator =
			dynamic_cast<Comparator*>(mComparator.getEntity());
		candidate = ceilingEntryUsingComparator(key);
		if (!candidate.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(candidate.getEntity());
			if (comparator->compare(entry->key(), key) == 0) {
				candidate = successor(candidate);
			}
		}

		return candidate;
	}

	argumentTypeCheck(key, Comparable::type());
	Comparable *comparable = dynamic_cast<Comparable*>(key.getEntity());
	candidate = ceilingEntry0(key);
	if (!candidate.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(candidate.getEntity());
		if (comparable->compareTo(entry->key()) == 0) {
			candidate = successor(candidate);
		}
	}

	return candidate;
}

Reference TreeMap::higherKey(Reference key) {
	Reference target = higherEntry(key);
	if (!target.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(target.getEntity());
		return entry->key();
	}

	return Reference();
}

Reference TreeMap::keySet() {
	return Reference(new KeySetView(mKeyType, Reference(this, false)));
}

Reference TreeMap::lastEntry() {
	return getHighestEntry(mRoot);
}

Reference TreeMap::lastKey() {
	Reference target = lastEntry();
	if (!target.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(target.getEntity());
		return entry->key();
	}

	return Reference();
}

Reference TreeMap::lowerEntry(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	Reference candidate;
	if (!mComparator.isNull()) {
		Comparator *comparator =
			dynamic_cast<Comparator*>(mComparator.getEntity());
		candidate = floorEntryUsingComparator(key);
		if (!candidate.isNull()) {
			TreeEntry *entry = dynamic_cast<TreeEntry*>(candidate.getEntity());
			if (comparator->compare(entry->key(), key) == 0) {
				candidate = predecessor(candidate);
			}
		}

		return candidate;
	}

	argumentTypeCheck(key, Comparable::type());
	Comparable *comparable = dynamic_cast<Comparable*>(key.getEntity());
	candidate = floorEntry0(key);
	if (!candidate.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(candidate.getEntity());
		if (comparable->compareTo(entry->key())) {
			candidate = predecessor(candidate);
		}
	}

	return candidate;
}

Reference TreeMap::lowerKey(Reference key) {
	Reference ref = lowerEntry(key);
	if (!ref.isNull()) {
		TreeEntry *entry = dynamic_cast<TreeEntry*>(ref.getEntity());
		return entry->key();
	}

	return Reference();
}

Reference TreeMap::pollFirstEntry() {
	if (mRoot.isNull()) {
		return Reference();
	}

	Reference firstEntry = getLowestEntry(mRoot);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(firstEntry.getEntity());
	remove(entry->key());

	return firstEntry;
}

Reference TreeMap::pollLastEntry() {
	if (mRoot.isNull()) {
		return Reference();
	}

	Reference lastEntry = getHighestEntry(mRoot);
	TreeEntry *entry = dynamic_cast<TreeEntry*>(lastEntry.getEntity());
	remove(entry->key());

	return lastEntry;
}

Reference TreeMap::put(Reference key, Reference value) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);
	if (!value.isNull()) {
		argumentTypeCheck(value, mValueType);
	}

	if (!mComparator.isNull()) {
		return addEntryUsingComparator(key, value);
	}

	argumentTypeCheck(key, Comparable::type());
	return addEntry(key, value);
}

Reference TreeMap::putIfAbsent(Reference key, Reference value) {
	Reference target = getEntry(key);
	if (target.isNull()) {
		put(key, value);
		return Reference();
	}

	TreeEntry *entry = dynamic_cast<TreeEntry*>(target.getEntity());
	return entry->value();
}

Reference TreeMap::remove(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	if (!mComparator.isNull()) {
		return removeEntryUsingComparator(key, Reference());
	}

	argumentTypeCheck(key, Comparable::type());
	return removeEntry(key, Reference());
}

Reference TreeMap::remove(Reference key, Reference value) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);
	if (!value.isNull()) {
		argumentTypeCheck(value, mValueType);
	}

	if (!mComparator.isNull()) {
		return removeEntryUsingComparator(key, value);
	}

	argumentTypeCheck(key, Comparable::type());
	return removeEntry(key, value);
}

Reference TreeMap::values() {
	return Reference(new Values(mValueType, Reference(this, false)));
}

type_t TreeMap::type() {
	return CLASS_SERIAL;
}

bool TreeMap::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SortedMap::instanceof(type);
}

TreeMap::EntrySetView::EntrySetView(type_t elementType, Reference map)
	: Collection(elementType), Set(elementType), SortedSet(elementType) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::EntrySetView::add(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());
	invalidateIterators();

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	tlint oldSize = map->size();
	map->put(entry->key(), entry->value());

	return map->size() != oldSize;
}

bool TreeMap::EntrySetView::addAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	tlint oldSize = map->size();

	while (iterator->hasNext()) {
		Reference e = iterator->next();
		if (e.isNull()) {
			continue;
		}

		add(e);
	}

	return map->size() != oldSize;
}

Reference TreeMap::EntrySetView::ceiling(Reference ref) {
	dismissNull(ref);

	argumentTypeCheck(ref, Map::Entry::type());
	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->ceilingEntry(entry->key());
}

void TreeMap::EntrySetView::clear() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

bool TreeMap::EntrySetView::contains(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Map::Entry::type());
	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	return map->contains(entry->key(), entry->value());
}

bool TreeMap::EntrySetView::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());
	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool flag = true;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		flag = flag && contains(e);

		if (!flag) {
			return flag;
		}
	}

	return flag;
}

Reference TreeMap::EntrySetView::descendingIterator() {
	if (!mDescendingIterator.isNull()) {
		Iterator *iterator =
			dynamic_cast<Iterator*>(mDescendingIterator.getEntity());
		iterator->invalidate();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mDescendingIterator = Reference(
		new DescendingEntryIterator(mMap, map->getHighestEntry(map->mRoot)));
	return mDescendingIterator;
}

Reference TreeMap::EntrySetView::first() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->firstEntry();
}

Reference TreeMap::EntrySetView::floor(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	return map->floorEntry(entry->key());
}

Reference TreeMap::EntrySetView::higher(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	return map->higherEntry(entry->key());
}

bool TreeMap::EntrySetView::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->isEmpty();
}

Reference TreeMap::EntrySetView::iterator() {
	if (!mIterator.isNull()) {
		Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
		iterator->invalidate();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mIterator = Reference(
		new EntryIterator(mMap, map->getLowestEntry(map->mRoot)));
	return mIterator;
}

Reference TreeMap::EntrySetView::last() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lastEntry();
}

Reference TreeMap::EntrySetView::lower(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Map::Entry::type());

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	return map->lowerEntry(entry->key());
}

Reference TreeMap::EntrySetView::pollFirst() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->pollFirstEntry();
}

Reference TreeMap::EntrySetView::pollLast() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->pollLastEntry();
}

bool TreeMap::EntrySetView::remove(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Map::Entry::type());
	invalidateIterators();

	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	tlint oldSize = map->size();
	map->remove(entry->key(), entry->value());

	return map->size() != oldSize;
}

void TreeMap::EntrySetView::removeAll(Reference ref) {
	dismissNull(ref);
	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	while (iterator->hasNext()) {
		Reference e = iterator->next();
		if (e.isNull()) {
			continue;
		}

		remove(e);
	}
}

tlint TreeMap::EntrySetView::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

type_t TreeMap::EntrySetView::type() {
	return CLASS_SERIAL;
}

bool TreeMap::EntrySetView::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SortedSet::instanceof(type);
}

TreeMap::PrivateEntryIterator::PrivateEntryIterator(Reference mapRef,
	Reference currentEntry) {
	mMap = mapRef;
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mNext = currentEntry;

	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::PrivateEntryIterator::nextEntry() {
	if (mNext.isNull()) {
		throw NoSuchElementException();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mLast = mNext;
	mNext = map->successor(mNext);

	return mLast;
}

Reference TreeMap::PrivateEntryIterator::previousEntry() {
	if (mNext.isNull()) {
		throw NoSuchElementException();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mLast = mNext;
	mNext = map->predecessor(mNext);

	return mLast;
}

bool TreeMap::PrivateEntryIterator::hasNext() {
	return !mNext.isNull();
}

void TreeMap::PrivateEntryIterator::remove() {
	checkValidation();

	if (mLast.isNull()) {
		throw NoSuchElementException();
	}

	Map::Entry *entry = dynamic_cast<Map::Entry*>(mLast.getEntity());
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());

	map->remove(entry->key());
}

Reference TreeMap::EntrySetView::toArray() {
	Reference rtval = Reference(new Array(Map::Entry::type(), size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference ref = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		arr->set(index, e);
		index++;
	}

	return rtval;
}

type_t TreeMap::PrivateEntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::PrivateEntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || Iterator::instanceof(type);
}

TreeMap::KeySetView::KeySetView(type_t elementType, Reference map)
	: Collection(elementType), Set(elementType), SortedSet(elementType) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::KeySetView::~KeySetView() {

}

Reference TreeMap::KeySetView::ceiling(Reference key) {
	dismissNull(key);
	argumentTypeCheck(key, mKeyType);

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->ceilingKey(key);
}

void TreeMap::KeySetView::clear() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	map->clear();
}

bool TreeMap::KeySetView::contains(Reference key) {
	if (key.isNull()) {
		return false;
	}

	argumentTypeCheck(key, mKeyType);

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsKey(key);
}

bool TreeMap::KeySetView::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool flag = true;
	while (iterator->hasNext()) {
		Reference e = iterator->next();
		if (e.isNull()) {
			continue;
		}

		flag = flag && contains(e);
		if (!flag) {
			return flag;
		}
	}

	return flag;
}

Reference TreeMap::KeySetView::descendingIterator() {
	if (!mDescendingIterator.isNull()) {
		Iterator *iterator =
			dynamic_cast<Iterator*>(mDescendingIterator.getEntity());
		iterator->invalidate();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mDescendingIterator = Reference(
		new DescendingKeyIterator(mMap, map->getHighestEntry(map->mRoot)));
	return mDescendingIterator;
}

Reference TreeMap::KeySetView::first() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->firstKey();
}

Reference TreeMap::KeySetView::floor(Reference key) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->floorKey(key);
}

Reference TreeMap::KeySetView::higher(Reference key) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->higherKey(key);
}

bool TreeMap::KeySetView::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->isEmpty();
}

Reference TreeMap::KeySetView::iterator() {
	if (!mIterator.isNull()) {
		Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
		iterator->invalidate();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mIterator = Reference(
		new KeyIterator(mMap, map->getLowestEntry(map->mRoot)));
	return mIterator;
}

Reference TreeMap::KeySetView::last() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lastKey();
}

Reference TreeMap::KeySetView::lower(Reference key) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->lowerKey(key);
}

Reference TreeMap::KeySetView::pollFirst() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference entry = map->pollFirstEntry();

	if (!entry.isNull()) {
		Map::Entry *e = dynamic_cast<Map::Entry*>(entry.getEntity());
		return e->key();
	}

	return Reference();
}

Reference TreeMap::KeySetView::pollLast() {
	invalidateIterators();

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	Reference entry = map->pollLastEntry();

	if (!entry.isNull()) {
		Map::Entry *e = dynamic_cast<Map::Entry*>(entry.getEntity());
		return e->key();
	}

	return Reference();
}

tlint TreeMap::KeySetView::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

Reference TreeMap::KeySetView::toArray() {
	Reference rtval = Reference(new Array(mElementType, size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference ref = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		Reference k = iterator->next();
		arr->set(index, k);
		index++;
	}

	return rtval;
}

type_t TreeMap::KeySetView::type() {
	return CLASS_SERIAL;
}

bool TreeMap::KeySetView::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || SortedSet::instanceof(type);
}

TreeMap::Values::Values(type_t elementType, Reference map)
	: Collection(elementType) {
	mMap = map;

	mHashCode = genHashCode(CLASS_SERIAL);
}

bool TreeMap::Values::contains(Reference value) {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->containsValue(value);
}

bool TreeMap::Values::containsAll(Reference ref) {
	if (ref.isNull()) {
		return false;
	}

	argumentTypeCheck(ref, Collection::type());

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	Reference iteratorRef = collection->iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(iteratorRef.getEntity());

	bool nullExist = contains(Reference());
	bool flag = true;
	while (iterator->hasNext()) {
		Reference v = iterator->next();
		if (v.isNull()) {
			flag = flag && nullExist;
		} else {
			flag = flag && contains(v);
		}

		if (!flag) {
			return flag;
		}
	}

	return flag;
}

bool TreeMap::Values::isEmpty() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->isEmpty();
}

Reference TreeMap::Values::iterator() {
	if (!mIterator.isNull()) {
		Iterator *iterator = dynamic_cast<Iterator*>(mIterator.getEntity());
		iterator->invalidate();
	}

	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	mIterator = Reference(
		new ValuesIterator(mMap, map->getLowestEntry(map->mRoot)));
	return mIterator;
}

tlint TreeMap::Values::size() {
	TreeMap *map = dynamic_cast<TreeMap*>(mMap.getEntity());
	return map->size();
}

Reference TreeMap::Values::toArray() {
	Reference rtval = Reference(new Array(mElementType, size()));
	Array *arr = dynamic_cast<Array*>(rtval.getEntity());

	Reference ref = iterator();
	Iterator *iterator = dynamic_cast<Iterator*>(ref.getEntity());
	tlint index = 0;
	while (iterator->hasNext()) {
		arr->set(index, iterator->next());
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

TreeMap::EntryIterator::EntryIterator(Reference map, Reference currentEntry)
	: PrivateEntryIterator(map, currentEntry) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

Reference TreeMap::EntryIterator::next() {
	checkValidation();

	return nextEntry();
}

type_t TreeMap::EntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::EntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::DescendingEntryIterator::DescendingEntryIterator(Reference map,
	Reference entry)
	: PrivateEntryIterator(map, entry) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::DescendingEntryIterator::~DescendingEntryIterator() {

}

Reference TreeMap::DescendingEntryIterator::next() {
	checkValidation();

	return previousEntry();
}

type_t TreeMap::DescendingEntryIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::DescendingEntryIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::KeyIterator::KeyIterator(Reference map, Reference entry)
	: PrivateEntryIterator(map, entry) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::KeyIterator::~KeyIterator() {

}

Reference TreeMap::KeyIterator::next() {
	checkValidation();

	Reference ref = nextEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	return entry->key();
}

type_t TreeMap::KeyIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::KeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::DescendingKeyIterator::DescendingKeyIterator(Reference map,
	Reference entry)
	: PrivateEntryIterator(map, entry) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::DescendingKeyIterator::~DescendingKeyIterator() {

}

Reference TreeMap::DescendingKeyIterator::next() {
	checkValidation();

	Reference ref = previousEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	return entry->key();
}

type_t TreeMap::DescendingKeyIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::DescendingKeyIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

TreeMap::ValuesIterator::ValuesIterator(Reference map, Reference entry)
	: PrivateEntryIterator(map, entry) {
	mHashCode = genHashCode(CLASS_SERIAL);
}

TreeMap::ValuesIterator::~ValuesIterator() {

}

Reference TreeMap::ValuesIterator::next() {
	checkValidation();

	Reference ref = nextEntry();
	Map::Entry *entry = dynamic_cast<Map::Entry*>(ref.getEntity());
	return entry->value();
}

type_t TreeMap::ValuesIterator::type() {
	return CLASS_SERIAL;
}

bool TreeMap::ValuesIterator::instanceof(type_t type) {
	return (CLASS_SERIAL == type) || PrivateEntryIterator::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
