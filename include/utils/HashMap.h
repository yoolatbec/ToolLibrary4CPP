/*
 * HashMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_HASHMAP_H_
#define INCLUDE_UTILS_HASHMAP_H_

#include <utils/Map.h>
#include <utils/Set.h>

namespace tl {
namespace utils {

using lang::Reference;

class HashMap: virtual public Map {
private:
	const static type_t CLASS_SERIAL = 789;
	constexpr const static tlint INIT_CAPACITY[5] =
		{ 8, 13, 21, 34, 55 };
	constexpr const static tlint DEFAULT_TOTAL_CAPACITY = 131;
	constexpr const static tlint TABLE_COUNT = 5;
	constexpr const static tlint MAX_CAPACITY = 1 << 30;
	constexpr const static tlint MAX_TRANSFER = 8;
	constexpr const static double DEFAULT_LOAD_FACTOR = 0.5;

	class HashEntry: public Map::Entry {
	private:
		const static type_t CLASS_SERIAL = 780;
		bool mValid;

	public:
		HashEntry(Reference, Reference = Reference());
		HashEntry& operator=(const HashEntry&) = delete;
		HashEntry(const HashEntry&) = delete;
		bool valid();
		void validate();
		void invalidate();
		bool instanceof(type_t);
		static type_t type();
	};

	class PrivateEntryIterator: public virtual Iterator {
	private:
		const static type_t CLASS_SERIAL = 500;

		Reference mLastReturned;
		Reference mCurrentEntry;

		tlint mTableNumber;
		tlint mEntryIndex;

		Reference nextEntry0();
	protected:
		Reference mMap;
	public:
		PrivateEntryIterator(Reference);
		PrivateEntryIterator(const PrivateEntryIterator&) = delete;
		PrivateEntryIterator& operator=(const PrivateEntryIterator&) = delete;
		virtual ~PrivateEntryIterator();
		virtual Reference nextEntry();
		virtual bool hasNext();
		virtual void remove();
		static type_t type();
		bool instanceof(type_t);
	};

	class EntrySetView: public virtual Set {
	private:
		const static type_t CLASS_SERIAL = 501;

		Reference mMap;
		Reference mIterator;

		void invalidateIterators();
	public:
		EntrySetView(Reference);
		EntrySetView(const EntrySetView&) = delete;
		EntrySetView& operator=(const EntrySetView&) = delete;
		virtual bool add(Reference);
		virtual bool addAll(Reference);
		virtual bool contains(Reference);
		virtual bool containsAll(Reference);
		virtual Reference iterator();
		virtual bool remove(Reference);
		virtual bool removeAll(Reference);
		virtual void clear();
		virtual Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class EntryIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 602;
	public:
		EntryIterator(Reference);
		EntryIterator(const EntryIterator&) = delete;
		EntryIterator& operator=(const EntryIterator&) = delete;
		virtual Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class KeySetView: public virtual Set {
	private:
		const static type_t CLASS_SERIAL = 502;

		Reference mMap;
		Reference mIterator;

		void invalidateIterators();
	public:
		KeySetView(type_t, Reference);
		KeySetView(const KeySetView&) = delete;
		KeySetView& operator=(const KeySetView&) = delete;
		virtual bool add(Reference);
		virtual bool addAll(Reference);
		virtual bool contains(Reference);
		virtual bool containsAll(Reference);
		virtual Reference iterator();
		virtual bool remove(Reference);
		virtual bool removeAll(Reference);
		virtual void clear();
		virtual Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class KeyIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 506;

	public:
		KeyIterator(Reference);
		KeyIterator(const KeyIterator&) = delete;
		KeyIterator& operator=(const KeyIterator&) = delete;
		virtual Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	class Values: public virtual Collection {
	private:
		const static type_t CLASS_SERIAL = 503;

		Reference mMap;
		Reference mIterator;

		void invalidateIterators();
	public:
		Values(type_t, Reference);
		Values(const Values&) = delete;
		Values& operator=(const Values&) = delete;
		virtual bool add(Reference);
		virtual bool addAll(Reference);
		virtual bool contains(Reference);
		virtual bool containsAll(Reference);
		virtual bool remove(Reference);
		virtual bool removeAll(Reference);
		virtual void clear();
		virtual Reference iterator();
		virtual Reference toArray();
		static type_t type();
		bool instanceof(type_t);
	};

	class ValueIterator: public virtual PrivateEntryIterator {
	private:
		const static type_t CLASS_SERIAL = 504;
	public:
		ValueIterator(Reference);
		ValueIterator(const ValueIterator&) = delete;
		ValueIterator& operator=(const ValueIterator&) = delete;
		Reference next();
		static type_t type();
		bool instanceof(type_t);
	};

	friend class PrivateEntryIterator;

	Reference mTables;
	tlint mNextExchange;

	tlint mCurrentCapacity[5];
	tlint mCurrentTotalCapacity;
	double mLoadFactor;

	void rehash();
	Reference computeIndices(Reference);
	Reference findEntry(Reference);
	void put0(Reference, Reference);
	bool searchTableForValue(tlint, Reference);
	void capacityCheck();

public:
	HashMap(type_t, type_t);
	virtual ~HashMap();
	HashMap(const HashMap &other) = delete;
	HashMap& operator=(const HashMap &other) = delete;
	virtual bool containsKey(Reference);
	virtual bool containsValue(Reference);
	virtual bool containsEntry(Reference);
	virtual void clear();
	virtual Reference keySet();
	virtual Reference entrySet();
	virtual Reference values();
	virtual Reference put(Reference, Reference);
	virtual Reference get(Reference);
	virtual Reference putIfAbsent(Reference, Reference);
	virtual void putAll(Reference);
	virtual Reference remove(Reference);
	virtual Reference remove(Reference, Reference);
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_HASHMAP_H_ */
