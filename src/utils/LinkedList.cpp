/*
 * LinkedList.cpp
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#include "LinkedList.h"

namespace tl {
namespace utils {

LinkedList::LinkedList(hash_t type)
		: Collection(type), List(type) {
	// TODO Auto-generated constructor stub
	mHash &= CLASS_HASH;
	mHead = Reference(new LinkedListNode(Reference()));
	mTail = Reference(new LinkedListNode(Reference()));
	((LinkedListNode*)mHead.getEntity())->mNext = mTail;
	((LinkedListNode*)mTail.getEntity())->mPrevious = mHead;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

bool LinkedList::add(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->mPrevious =
			((LinkedListNode*)mTail.getEntity())->mPrevious;
	((LinkedListNode*)node.getEntity())->mNext = mTail;
	((LinkedListNode*)mTail.getEntity())->mPrevious = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->mPrevious.getEntity()))->mNext =
			node;

	mModified = true;
	mSize++;
	return true;
}

bool LinkedList::addFirst(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->mPrevious = mHead;
	((LinkedListNode*)node.getEntity())->mNext =
			((LinkedListNode*)mHead.getEntity())->mNext;
	((LinkedListNode*)mHead.getEntity())->mNext = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->mNext.getEntity()))->mPrevious =
			node;

	mSize++;
	mModified = true;
	return true;
}

bool LinkedList::addLast(const Reference &ref) {
	return add(ref);
}

bool LinkedList::addAll(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference ref = iterator->next();
		add(ref);
	}

	return true;
}

bool LinkedList::addAllLast(const Reference &ref) {
	return addAll(ref);
}

bool LinkedList::addAllFirst(const Reference &ref) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Reference current = mHead;
	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference newNode = Reference(new LinkedListNode(iterator->next()));
		((LinkedListNode*)newNode.getEntity())->mPrevious = current;
		((LinkedListNode*)newNode.getEntity())->mNext =
				((LinkedListNode*)current.getEntity())->mNext;
		((LinkedListNode*)current.getEntity())->mNext = newNode;
		((LinkedListNode*)(((LinkedListNode*)newNode.getEntity())->mNext.getEntity()))->mPrevious =
				newNode;
		current = ((LinkedListNode*)current.getEntity())->mNext;
	}

	mModified = true;
	mSize += collection->size();
	return true;
}

bool LinkedList::contains(const Reference &ref) const {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	while (!current.equals(mTail)) {
		if (((LinkedListNode*)current.getEntity())->mValue.equals(ref)) {
			return true;
		}
	}
	return false;
}

bool LinkedList::insert(const Reference &ref, size_t position) {
	if (position < 0 || position > mSize) {
		return false;
	}

	if (position == mSize) {
		return addLast(ref);
	}

	if (position == 0) {
		return addFirst(ref);
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference current = mHead;
	size_t index = 0;
	while (index < position) {
		current = ((LinkedListNode*)current.getEntity())->mNext;
		index++;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->mNext =
			((LinkedListNode*)current.getEntity())->mNext;
	((LinkedListNode*)node.getEntity())->mPrevious = current;
	((LinkedListNode*)current.getEntity())->mNext = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->mNext.getEntity()))->mPrevious =
			node;

	mSize++;
	mModified = true;
	return true;
}

bool LinkedList::insertAll(const Reference &ref, size_t position) {
	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	if (position < 0 || position > mSize) {
		return false;
	}

	if (position == mSize) {
		return addAll(ref);
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	if (collection->size() == 0) {
		return true;
	}

	Reference current = mHead;
	size_t index = 0;
	while (index < position) {
		current = ((LinkedListNode*)current.getEntity())->mNext;
	}

	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		Reference node = Reference(new LinkedListNode(value));
		((LinkedListNode*)node.getEntity())->mNext =
				((LinkedListNode*)current.getEntity())->mNext;
		((LinkedListNode*)node.getEntity())->mPrevious = current;
		((LinkedListNode*)current.getEntity())->mNext = node;
		((LinkedListNode*)(((LinkedListNode*)node.getEntity())->mNext.getEntity()))->mPrevious =
				node;
		current = ((LinkedListNode*)current.getEntity())->mNext;
	}

	mModified = true;
	mSize += collection->size();
	return true;
}

bool LinkedList::remove(const Reference &ref) {
	if (empty()) {
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	bool found = false;
	while (!current.equals(mTail)) {
		if (ref.equals(((LinkedListNode*)current.getEntity())->mValue)) {
			Reference target = current;
			current = ((LinkedListNode*)current.getEntity())->mNext;
			((LinkedListNode*)((LinkedListNode*)target.getEntity())->mPrevious.getEntity())->mNext =
					current;
			((LinkedListNode*)(LinkedListNode*)current.getEntity())->mPrevious =
					((LinkedListNode*)target.getEntity())->mPrevious;
			mSize--;
			mModified = true;
		}
	}

	return found;
}

bool LinkedList::remove(size_t position) {
	if (empty()) {
		return false;
	}

	if (position < 0 || position >= mSize) {
		return false;
	}

	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	for (size_t index = 0; index < position; index++) {
		current = ((LinkedListNode*)current.getEntity())->mNext;
	}

	Reference target = current;
	current = ((LinkedListNode*)current.getEntity())->mNext;
	((LinkedListNode*)((LinkedListNode*)target.getEntity())->mPrevious.getEntity())->mNext =
			current;
	((LinkedListNode*)(LinkedListNode*)current.getEntity())->mPrevious =
			((LinkedListNode*)target.getEntity())->mPrevious;

	mModified = true;
	mSize--;
	return true;
}

bool LinkedList::removeFirst() {
	return remove(0);
}

bool LinkedList::removeLast() {
	if (empty()) {
		return false;
	}

	Reference target = ((LinkedListNode*)mTail.getEntity())->mPrevious;
	((LinkedListNode*)((LinkedListNode*)target.getEntity())->mPrevious.getEntity())->mNext =
			mTail;
	((LinkedListNode*)(LinkedListNode*)mTail.getEntity())->mPrevious =
			((LinkedListNode*)target.getEntity())->mPrevious;

	mModified = true;
	mSize--;
	return true;
}

bool LinkedList::removeAll(const Reference &ref) {
	if (empty()) {
		return false;
	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(Collection::getType())) {
		return false;
	}

	Collection *collection = dynamic_cast<Collection*>(ref.getEntity());
	if (collection->getElementType() != mElementType) {
		return false;
	}

	Iterator *iterator = collection->iterator();
	while (iterator->hasNext()) {
		Reference value = iterator->next();
		remove(value);
	}

	return true;
}

void LinkedList::clear() {
	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	while (!current.equals(mTail)) {
		((LinkedListNode*)mHead.getEntity())->mNext =
				((LinkedListNode*)current.getEntity())->mNext;
		((LinkedListNode*)((LinkedListNode*)current.getEntity())->mNext.getEntity())->mPrevious =
				mHead;
	}

	mSize = 0;
	mModified = true;
}

Reference LinkedList::get(size_t position) {
	if (position < 0 || position >= mSize) {
		return Reference();
	}

	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	for (size_t index = 0; index < position; index++) {
		current = ((LinkedListNode*)current.getEntity())->mNext;
	}

	return ((LinkedListNode*)current.getEntity())->mValue;
}

bool LinkedList::replace(const Reference &ref, size_t position) {
	if (ref.isNull()) {
		return remove(position);
	}

	if (!ref.instanceof(mElementType)) {
		return false;
	}

	if (position < 0 || position >= mSize) {
		return false;
	}

	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	for (size_t index = 0; index < position; index++) {
		current = ((LinkedListNode*)current.getEntity())->mNext;
	}

	((LinkedListNode*)current.getEntity())->mValue = ref;
	return true;
}

Array* LinkedList::toArray() const {
	Array *arr = new Array(mSize, mElementType);
	Reference current = ((LinkedListNode*)mHead.getEntity())->mNext;
	for (size_t index = 0; index < mSize; index++) {
		arr->set(((LinkedListNode*)current.getEntity())->mValue, index);
	}

	return arr;
}

Iterator* LinkedList::iterator() {
	return new LinkedListIterator(this);
}

Iterator* LinkedList::reversedIterator() {
	return new LinkedListReversedIterator(this);
}

bool LinkedList::instanceof(hash_t type) const {
	return (CLASS_HASH == type) || List::instanceof(type);
}

hash_t LinkedList::getType() {
	return CLASS_HASH;
}

LinkedList::LinkedListNode::LinkedListNode(const Reference &ref) {
	mValue = ref;
	mNext = Reference();
	mPrevious = Reference();
}

hash_t LinkedList::LinkedListNode::getType() {
	return CLASS_HASH;
}

bool LinkedList::LinkedListNode::instanceof(hash_t type) const {
	return (CLASS_HASH == type) || Object::instanceof(type);
}

LinkedList::LinkedListIterator::LinkedListIterator(LinkedList *list)
		: mList(list) {
	mCurrent = mList->mHead;
}

bool LinkedList::LinkedListIterator::hasNext() const {
	if (mList->mModified) {

	}

	return !(((LinkedListNode*)mCurrent.getEntity())->mNext.equals(mList->mTail));
}

Reference LinkedList::LinkedListIterator::next() {
	if (mList->mModified) {

	}

	mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mNext;
	return ((LinkedListNode*)mCurrent.getEntity())->mValue;
}

bool LinkedList::LinkedListIterator::hasPrevious() const{
	if(mList->mModified){

	}

	return !(((LinkedListNode*)mCurrent.getEntity())->mPrevious.equals(mList->mHead));
}

Reference LinkedList::LinkedListIterator::previous(){
	if(mList->mModified){

	}

	mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mPrevious;
	return ((LinkedListNode*)mCurrent.getEntity())->mValue;
}

bool LinkedList::LinkedListIterator::insert(const Reference &ref) {
	if (mList->mModified) {

	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mList->mElementType)) {
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->mPrevious = mCurrent;
	((LinkedListNode*)node.getEntity())->mNext =
			((LinkedListNode*)mCurrent.getEntity())->mNext;
	((LinkedListNode*)mCurrent.getEntity())->mNext = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->mNext.getEntity()))->mPrevious =
			node;

	(mList->mSize)++;
	return true;
}

bool LinkedList::LinkedListIterator::remove() {
	if (mList->mModified) {

	}

	if (mCurrent.equals(mList->mHead)) {
		return false;
	}

	if (((LinkedListNode*)mCurrent.getEntity())->mNext.equals(mList->mTail)) {
		mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mPrevious;
		((LinkedListNode*)(mList->mTail.getEntity()))->mPrevious = mCurrent;
		((LinkedListNode*)mCurrent.getEntity())->mNext = mList->mTail;
	} else {
		Reference target = mCurrent;
		mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mNext;
		((LinkedListNode*)(((LinkedListNode*)target.getEntity())->mPrevious.getEntity()))->mNext =
				mCurrent;
		((LinkedListNode*)mCurrent.getEntity())->mPrevious =
				((LinkedListNode*)target.getEntity())->mPrevious;
	}

	(mList->mSize)--;

	return true;
}

hash_t LinkedList::LinkedListIterator::getType() {
	return CLASS_HASH;
}

bool LinkedList::LinkedListIterator::instanceof(hash_t type) const {
	return (CLASS_HASH || Iterator::instanceof(type);
}

LinkedList::LinkedListReversedIterator::LinkedListReversedIterator(
		LinkedList *list)
		: mList(list) {
	mCurrent = mList->mTail;
}

bool LinkedList::LinkedListReversedIterator::hasNext() const {
	if (mList->mModified) {

	}

	return !(((LinkedListNode*)mCurrent.getEntity())->mPrevious.equals(
			mList->mHead));
}

Reference LinkedList::LinkedListReversedIterator::next() {
	if (mList->mModified) {

	}

	mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mPrevious;
	return ((LinkedListNode*)mCurrent.getEntity())->mValue;
}

bool LinkedList::LinkedListReversedIterator::hasPrevious() const{
	if(mList->mModified){

	}

	return !(((LinkedListNode*)mCurrent.getEntity())->mNext.equals(mList->mTail));
}

Reference LinkedList::LinkedListReversedIterator::previous(){
	if(mList->mModified){

	}

	mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mNext;
	return ((LinkedListNode*)mCurrent.getEntity())->mValue;
}

bool LinkedList::LinkedListReversedIterator::insert(const Reference &ref) {
	if (mList->mModified) {

	}

	if (ref.isNull()) {
		return false;
	}

	if (!ref.instanceof(mList->mElementType)) {
		return false;
	}

	Reference node = Reference(new LinkedListNode(ref));
	((LinkedListNode*)node.getEntity())->mNext = mCurrent;
	((LinkedListNode*)node.getEntity())->mPrevious =
			((LinkedListNode*)mCurrent.getEntity())->mPrevious;
	((LinkedListNode*)mCurrent.getEntity())->mPrevious = node;
	((LinkedListNode*)(((LinkedListNode*)node.getEntity())->mPrevious.getEntity()))->mNext =
			node;

	return true;
}

bool LinkedList::LinkedListReversedIterator::remove() {
	if (mList->mSize == 0) {
		return false;
	}

	if (((LinkedListNode*)mCurrent.getEntity())->mPrevious.equals(
			mList->mHead)) {
		mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mNext;
		((LinkedListNode*)mList->mHead.getEntity())->mNext = mCurrent;
		((LinkedListNode*)mCurrent.getEntity())->mPrevious = mList->mHead;
	} else {
		Reference target = mCurrent;
		mCurrent = ((LinkedListNode*)mCurrent.getEntity())->mPrevious;
		((LinkedListNode*)mCurrent.getEntity())->mNext = ((LinkedListNode*)target.getEntity())->mNext;
		((LinkedListNode*)(((LinkedListNode*)target.getEntity())->mNext.getEntity()))->mPrevious = mCurrent;
	}

	return true;
}

hash_t LinkedList::LinkedListReversedIterator::getType(){
	return CLASS_HASH;
}

bool LinkedList::LinkedListReversedIterator::instanceof(hash_t type) const{
	return (CLASS_HASH == type) || Object::instanceof(type);
}

} /* namespace utils */
} /* namespace tl */
