/*
 * TreeMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_TREEMAP_H_
#define INCLUDE_UTILS_TREEMAP_H_

#include <tl/utils/NavigableMap.h>
#include <tl/utils/NavigableSet.h>
#include <tl/utils/SortedSet.h>

namespace tl {
namespace utils {

using lang::Reference;
class TreeMap: public virtual NavigableMap {
private:
	const static type_t CLASS_SERIAL = 54;
	class TreeEntry: public virtual Map::Entry {
	private:
		hash_t genHashCode(type_t);

		const static type_t CLASS_SERIAL = 55;
		Reference mParent;
		Reference mLeft, mRight;
		hash_t mWeight;
		tlint mHeight;
	public:
		const static tlint ALLOWED_IMBALANCE = 1;

		TreeEntry(Reference, Reference, Reference = Reference());
		TreeEntry(const TreeEntry&) = delete;
		TreeEntry& operator=(const TreeEntry&) = delete;
		Reference getLeft();
		Reference getRight();
		Reference getParent();
		void setLeft(Reference);
		void setRight(Reference);
		void setParent(Reference);
		tlint getHeight();
		void setHeight(tlint);
		hash_t getWeight();
		Reference toString();
		static type_t type();
		bool instanceof(type_t);
	};

	Reference add0(Reference, Reference, Reference, Reference);
	Reference remove0(Reference ref, Reference keyRef);
//	Reference replace0(Reference, Reference, Reference);
	bool containsKey0(Reference ref, Reference keyRef);
	bool containsValue0(Reference ref, Reference valueRef);
	Reference balance0(Reference);
	tlint height0(Reference);
	void clear0(Reference);
	Reference minEntry0(Reference);
	Reference maxEntry0(Reference);
	Reference ceilingEntry0(Reference ref, Reference keyRef);
	Reference floorEntry0(Reference ref, Reference keyRef);
	Reference rightRotate0(Reference);
	Reference leftRotate0(Reference);
	Reference rightLeftRotate0(Reference);
	Reference leftRightRotate0(Reference);
	Reference getValue0(Reference, Reference);
	Reference getEntry0(Reference, Reference);
	Reference successor0(Reference, Reference);
	Reference predecessor0(Reference, Reference);

	class EntrySetView: public virtual Set {
	private:
		const static type_t CLASS_SERIAL = 90;
		Reference mMap;

		Reference mIterator;

		void invalidateIterators();
	public:
		EntrySetView(Reference);
		EntrySetView(const EntrySetView&) = delete;
		EntrySetView& operator=(const EntrySetView&) = delete;
		bool contains(Reference);
		bool containsAll(Reference);
		void clear();
		bool add(Reference);
		bool addAll(Reference);
		bool remove(Reference);
		bool removeAll(Reference);
//		Reference first();
//		Reference last();
//		Reference pollLast();
//		Reference pollFirst();
//		Reference subSet(Reference fromElement, Reference toElement);
//		Reference subSet(Reference fromElement, bool fromInclusive,
//			Reference toElement, bool toInclusive);
//		Reference lower(Reference);
//		Reference higher(Reference);
//		Reference ceiling(Reference);
//		Reference floor(Reference);
		Reference iterator();
		bool isEmpty();
		tlint size();
		Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class Values: public virtual Collection {
	private:
		const static type_t CLASS_SERIAL = 91;
		Reference mMap;

		Reference mIterator;
		void invalidateIterators();
	public:
		Values(type_t, Reference);
		Values(const Values&) = delete;
		Values& operator=(const Values&) = delete;
		virtual bool contains(Reference);
		virtual bool containsAll(Reference);
		virtual void clear();
		virtual bool add(Reference);
		virtual bool addAll(Reference);
		virtual Reference iterator();
		virtual bool remove(Reference);
		virtual bool removeAll(Reference);
		virtual tlint size();
		virtual bool isEmpty();
		virtual Reference toArray();
		bool instanceof(type_t);
		static type_t type();
	};

	class PrivateEntryIterator: public virtual Iterator {
	private:
		const static type_t CLASS_SERIAL = 99;
	protected:
		Reference mMap;
		Reference mNext;
		Reference mLastReturned;
	public:
		PrivateEntryIterator(Reference map);
		PrivateEntryIterator(const PrivateEntryIterator&) = delete;
		PrivateEntryIterator& operator=(const PrivateEntryIterator&) = delete;
		Reference nextEntry();
		Reference previousEntry();
		virtual bool hasNext();
		virtual void remove();
		static type_t type();
		bool instanceof(type_t);
	};

	class EntryIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 98;
	public:
		EntryIterator(Reference);
		EntryIterator(const EntryIterator&) = delete;
		EntryIterator& operator=(const EntryIterator&) = delete;
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class ValueIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 99;
	public:
		ValueIterator(Reference);
		ValueIterator(const ValueIterator&) = delete;
		ValueIterator& operator=(const ValueIterator&) = delete;
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class KeySet: public virtual NavigableSet {
	private:
		const static type_t CLASS_SERIAL = 92;
		Reference mMap;

		Reference mIterator;
		Reference mDescendingIterator;
		void invalidateIterators();
	public:
		KeySet(type_t, Reference);
		KeySet(const KeySet&) = delete;
		KeySet& operator=(const KeySet&) = delete;
		virtual bool add(Reference);
		virtual bool addAll(Reference);
		virtual bool remove(Reference);
		virtual bool removeAll(Reference);
		virtual bool contains(Reference);
		virtual bool containsAll(Reference);
		virtual void clear();
		virtual Reference toArray();
		virtual Reference ceiling(Reference);
		virtual Reference floor(Reference);
		virtual Reference lower(Reference);
		virtual Reference higher(Reference);
		virtual Reference last();
		virtual Reference first();
		virtual Reference pollLast();
		virtual Reference pollFirst();
//		virtual Reference subSet(Reference fromElement, bool fromInclusive,
//			Reference toElement, bool toInclusive);
//		virtual Reference subSet(Reference fromElement, Reference toElement);
		virtual Reference iterator();
		virtual Reference descendingIterator();
		virtual tlint size();
		virtual bool isEmpty();
		static type_t type();
		virtual bool instanceof(type_t);
	};

	class KeyIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 94;
	public:
		KeyIterator(Reference);
		KeyIterator(const KeyIterator&) = delete;
		KeyIterator& operator=(const KeyIterator&) = delete;
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class DescendingKeyIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 95;
	public:
		DescendingKeyIterator(Reference);
		DescendingKeyIterator(const DescendingKeyIterator&) = delete;
		DescendingKeyIterator& operator=(const DescendingKeyIterator&) = delete;
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	friend class EntrySetView;
	friend class PrivateEntryIterator;
	friend class Values;
	friend class KeySet;

	Reference mRootEntry;
	Reference put0(Reference, Reference);
//	bool inRange(Reference);
//	bool toLow(Reference);
//	bool toHigh(Reference);

public:
	TreeMap(type_t, type_t);
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
	Reference get(Reference);
	Reference put(Reference, Reference);
	void putAll(Reference);
	Reference remove(Reference);
	Reference putIfAbsent(Reference, Reference);
	Reference firstEntry();
	Reference firstKey();
	Reference floorEntry(Reference key);
	Reference floorKey(Reference key);
	Reference lastEntry();
	Reference lastKey();
	Reference lowerEntry(Reference key);
	Reference lowerKey(Reference key);
	Reference ceilingEntry(Reference key);
	Reference ceilingKey(Reference key);
	Reference higherEntry(Reference key);
	Reference higherKey(Reference key);
	Reference pollFirstEntry();
	Reference pollLastEntry();
	bool containsKey(Reference);
	bool containsValue(Reference);
	bool containsEntry(Reference);
	void clear();
//	Reference subMap(Reference fromKey, bool fromInclusive, Reference toKey,
//		bool toInclusive);
//	Reference subMap(Reference fromKey, Reference toKey);
	Reference keySet();
	Reference values();
	Reference entrySet();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_TREEMAP_H_ */
