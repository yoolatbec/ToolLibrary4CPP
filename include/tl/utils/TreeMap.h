/*
 * TreeMap.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_TREEMAP_H_
#define TL_UTILS_TREEMAP_H_

#include <tl/utils/SortedMap.h>
#include <tl/utils/Iterator.h>
#include <tl/utils/SortedSet.h>

namespace tl {
namespace utils {

/**
 * RB-tree based balance tree
 */
class TreeMap: public virtual SortedMap {
private:
	const static type_t CLASS_SERIAL = 1039;

	class TreeEntry: public virtual Map::Entry {
	private:
		const static type_t CLASS_SERIAL = 1040;
		Reference mParent;
		Reference mLeft;
		Reference mRight;
		bool mColor;

	public:
		const static constexpr bool RED = true;
		const static constexpr bool BLACK = false;

		TreeEntry(type_t, Reference, type_t, Reference);
		TreeEntry(const TreeEntry&) = delete;
		TreeEntry& operator=(const TreeEntry&) = delete;
		~TreeEntry();
		Reference getParent();
		void setParent(Reference);
		Reference getLeft();
		void setLeft(Reference);
		Reference getRight();
		void setRight(Reference);
		bool getColor();
		void setColor(bool);
		static type_t type();
		bool instanceof(type_t);
	};

	class EntrySetView: virtual public SortedSet {
	private:
		const static type_t CLASS_SERIAL = 1043;

		Reference mMap;
	public:
		EntrySetView(type_t, Reference);
		EntrySetView(const EntrySetView&) = delete;
		EntrySetView& operator=(const EntrySetView&) = delete;
		~EntrySetView();
		bool add(Reference);
		bool addAll(Reference);
		Reference ceiling(Reference);
		void clear();
		bool contains(Reference);
		bool containsAll(Reference);
		Reference descendingIterator();
		Reference first();
		Reference floor(Reference);
		Reference higher(Reference);
		bool isEmpty();
		Reference iterator();
		Reference last();
		Reference lower(Reference);
		Reference pollFirst();
		Reference pollLast();
		bool remove(Reference);
		void removeAll(Reference);
		tlint size();
		Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class PrivateEntryIterator: virtual public Iterator {
	private:
		const static type_t CLASS_SERIAL = 1044;

		Reference mMap;
	protected:
		PrivateEntryIterator(Reference map, Reference entry);
		Reference nextEntry();
		Reference previousEntry();
		bool hasNext();
	public:
		PrivateEntryIterator(const PrivateEntryIterator&) = delete;
		PrivateEntryIterator& operator=(const PrivateEntryIterator&) = delete;
		~PrivateEntryIterator();
		/**
		 * Remove the lastly returned element.
		 */
		void remove();
		static type_t type();
		bool instanceof(type_t);
	};

	class KeySetView: public virtual SortedSet {
	private:
		const static type_t CLASS_SERIAL = 1045;

		Reference mMap;
	public:
		KeySetView(type_t, Reference);
		KeySetView(const KeySetView&) = delete;
		KeySetView& operator=(const KeySetView&) = delete;
		~KeySetView();
		Reference ceiling(Reference);
		void clear();
		bool contains(Reference);
		bool containsAll(Reference);
		Reference descendingIterator();
		Reference first();
		Reference floor(Reference);
		Reference higher(Reference);
		bool isEmpty();
		Reference iterator();
		Reference last();
		Reference lower(Reference);
		Reference pollFirst();
		Reference pollLast();
		bool remove(Reference);
		void removeAll(Reference);
		tlint size();
		Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class Values: public virtual Collection {
	private:
		const static type_t CLASS_SERIAL = 1046;

		Reference mMap;
	public:
		Values(type_t, Reference);
		bool contains(Reference);
		bool containsAll(Reference);
		bool isEmpty();
		Reference iterator();
		tlint size();
		Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class EntryIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 1047;

	public:
		EntryIterator(Reference map, Reference entry);
		EntryIterator(const EntryIterator&) = delete;
		EntryIterator& operator=(const EntryIterator&) = delete;
		~EntryIterator();
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class DescendingEntryIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 1048;

	public:
		DescendingEntryIterator(Reference map, Reference entry);
		DescendingEntryIterator(const DescendingEntryIterator&) = delete;
		DescendingEntryIterator& operator=(const DescendingEntryIterator&) = delete;
		~DescendingEntryIterator();
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class KeyIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 1049;

	public:
		KeyIterator(Reference map, Reference entry);
		KeyIterator(const KeyIterator&) = delete;
		KeyIterator& operator=(const KeyIterator&) = delete;
		~KeyIterator();
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class DescendingKeyIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 1050;

	public:
		DescendingKeyIterator(Reference map, Reference entry);
		DescendingKeyIterator(const DescendingKeyIterator&) = delete;
		DescendingKeyIterator& operator=(const DescendingKeyIterator&) = delete;
		~DescendingKeyIterator();
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class ValuesIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 1051;

	public:
		ValuesIterator(Reference map, Reference entry);
		ValuesIterator(const ValuesIterator&) = delete;
		ValuesIterator& operator=(const ValuesIterator&) = delete;
		~ValuesIterator();
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	friend class PrivateEntryIterator;
	friend class EntrySetView;
	friend class KeySetView;
	friend class Values;

	Reference mRoot;

	void clear(Reference entry);
	Reference addEntry(Reference key, Reference value);
	Reference addEntryUsingComparator(Reference key, Reference value);
	/**
	 * Remove the entry with the given key and value(if given) from the tree
	 */
	Reference removeEntry(Reference key, Reference value);
	Reference removeEntryUsingComparator(Reference key, Reference value);
	/**
	 * Remove the given entry from the tree
	 */
	void removeEntry0(Reference entry);
	/*
	 * Get the successor entry of the given entry.
	 */
	Reference successor(Reference entry);
	Reference predecessor(Reference entry);
	Reference getEntry0(Reference key);
	Reference getEntryUsingComparator(Reference key);
	void leftRotate(Reference entry);
	void rightRotate(Reference entry);
	void removeFixUp(Reference entry);
	void addFixUp(Reference entry);
	/**
	 * Get the lowest entry in the tree whose root
	 * is the given entry. null is allowed, under which
	 * circumstance null is returned.
	 */
	Reference getLowestEntry(Reference entry);
	/**
	 * Get the highest entry in the tree whose root
	 * is the given entry. null is allowed, under which
	 * circumstance null is returned.
	 */
	Reference getHighestEntry(Reference entry);
	Reference ceilingEntry0(Reference key);
	Reference ceilingEntryUsingComparator(Reference key);
	Reference floorEntry0(Reference key);
	Reference floorEntryUsingComparator(Reference key);
	Reference getEntryByValue(Reference value);
public:
	TreeMap(type_t, type_t, Reference);
	virtual ~TreeMap();
	TreeMap(const TreeMap &other) = delete;
	TreeMap& operator=(const TreeMap &other) = delete;
	Reference ceilingEntry(Reference key);
	Reference ceilingKey(Reference key);
	void clear();
	bool containsKey(Reference key);
	bool containsValue(Reference value);
	bool contains(Reference key, Reference value);
	Reference entrySet();
	Reference firstEntry();
	Reference firstKey();
	Reference floorEntry(Reference key);
	Reference floorKey(Reference key);
	Reference get(Reference key);
	Reference getEntry(Reference key);
	/**
	 * Return the entry with the least key strictly greater than the given
	 * key, or null if such key doesn't exist;
	 */
	Reference higherEntry(Reference key);
	Reference higherKey(Reference key);
	Reference keySet();
	Reference lastEntry();
	Reference lastKey();
	/**
	 * Return the entry with the least key strictly lest than the given
	 * key, or null if such key doesn't exist
	 */
	Reference lowerEntry(Reference key);
	Reference lowerKey(Reference key);
	Reference pollFirstEntry();
	Reference pollLastEntry();
	Reference put(Reference key, Reference value);
	Reference putIfAbsent(Reference key, Reference value);
	Reference remove(Reference key);
	Reference remove(Reference key, Reference value);
	Reference values();
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_TREEMAP_H_ */
