/*
 * TreeMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_TREEMAP_H_
#define SRC_UTILS_TREEMAP_H_

#include "NavigableMap.h"
#include "NavigableSet.h"
#include "SortedSet.h"

namespace tl {
namespace utils {

using lang::Reference;
class TreeMap: public virtual NavigableMap {
private:
	const static type_t CLASS_SERIAL = 54;
	class TreeEntry: public Entry {
	private:
		hash_t genHashCode(type_t);

		const static type_t CLASS_SERIAL = 55;
		const static tlint ALLOWED_IMBALANCE = 1;
		Reference mParent;
		Reference mLeft, mRight;
		tlint mWeight;
		tlint mHeight;
	public:
		TreeEntry(Reference, Reference, Reference = Reference());
		static Reference add(Reference, Reference, Reference, Reference);
		static Reference remove(Reference ref, Reference keyRef);
		static Reference replace(Reference, Reference, Reference);
		static bool containsKey(Reference ref, Reference keyRef);
		static bool containsValue(Reference ref, Reference valueRef);
		static Reference balance(Reference);
		static tlint height(Reference);
		static void clear(Reference);
		static Reference minEntry(Reference);
		static Reference maxEntry(Reference);
		static Reference ceilingEntry(Reference ref, Reference keyRef);
		static Reference floorEntry(Reference ref, Reference keyRef);
		static Reference rightRotate(Reference);
		static Reference leftRotate(Reference);
		static Reference rightLeftRotate(Reference);
		static Reference leftRightRotate(Reference);
		static Reference getValue(Reference, Reference);
		static Reference getEntry(Reference, Reference);
		static Reference successor(Reference, Reference);
		static Reference predecessor(Reference, Reference);
		Reference getLeft();
		Reference getRight();
		Reference getParent();
		void setLeft(Reference);
		void setRight(Reference);
		void setParent(Reference);
		tlint getHeight();
		void setHeight(tlint);
		Reference toString();
		static type_t type();
		bool instanceof(type_t);
	};

	class EntrySetView: public virtual Set {
	private:
		const static type_t CLASS_SERIAL = 90;
		Reference mMap;

		void typeCheck(Reference, type_t);
	public:
		EntrySetView(Reference);
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

	class Values: public Collection {
	private:
		const static type_t CLASS_SERIAL = 91;
		Reference mMap;

		void typeCheck(Reference, type_t);
		void typeCheck(type_t, type_t);
	public:
		Values(Reference);
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
		Reference nextEntry();
		Reference previousEntry();
		virtual bool hasNext();
		virtual void remove();
	};

	class EntryIterator: public PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 98;
	public:
		EntryIterator(Reference);
		Reference next();
	};

	class ValueIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 99;
	public:
		ValueIterator(Reference);
		Reference next();
	};

	class KeySet: public NavigableSet {
	private:
		const static type_t CLASS_SERIAL = 92;
		Reference mMap;
	public:
		KeySet(type_t, Reference);
		virtual Reference add(Reference);
		virtual Reference addAll(Reference);
		virtual Reference remove(Reference);
		virtual Reference removeAll(Reference);
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
		virtual Reference subSet(Reference fromElement, bool fromInclusive,
			Reference toElement, bool toInclusive);
		virtual Reference subSet(Reference fromElement, Reference toElement);
		virtual Reference iterator();
		virtual tlint size();
		virtual bool isEmpty();
		static type_t type();
		virtual bool instanceof(type_t);
	};

	class KeyIterator: public PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 94;
	public:
		KeyIterator(Reference);
		Reference next();
	};

	class DescendingKeyIterator: public PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 95;
	public:
		DescendingKeyIterator(Reference);
		Reference next();
	};

	friend class EntrySetView;
	friend class PrivateEntryIterator;
	friend class Values;
	friend class KeySet;

	Reference mValues;
	Reference mKeySet;

	Reference mRootEntry;
	void typeCheck(Reference, type_t);
	void typeCheck(type_t, type_t);
	Reference put0(Reference, Reference);

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
	Reference replace(Reference, Reference);
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
	void clear();
	Reference subMap(Reference fromKey, bool fromInclusive, Reference toKey,
		bool toInclusive);
	Reference subMap(Reference fromKey, Reference toKey);
	Reference keySet();
	Reference values();
	Reference entrySet();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_TREEMAP_H_ */
