/*
 * HashMap.h
 *
 *  Created on: Nov 16, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_HASHMAP_H_
#define SRC_UTILS_HASHMAP_H_

#include "Map.h"

namespace tl {
namespace utils {

class HashMap: virtual public Map {
private:
	const static type_t CLASS_SERIAL = 789;
	const static tlint INIT_CAPACITY[5] = {
			8, 13, 21, 34, 55
	};
	const static tlint TABLE_COUNT = 5;

	class HashEntry : public Entry{
	private:
		const static type_t CLASS_SERIAL = 780;
		bool mValid;

	public:
		HashEntry(Reference, Reference = Reference());
		bool valid();
		void validate();
		void invalidate();
		bool instanceof(type_t);
		static type_t type();
	};

	const type_t mKeyType;
	const type_t mValueType;
	Reference mTables;

public:
	HashMap(type_t, type_t);
	virtual ~HashMap();
	HashMap(const HashMap &other) = delete;
	HashMap& operator=(const HashMap &other) = delete;
	bool containsKey(Reference);
	bool containsValue(Reference);
	void clear();
	Reference keySet();
	Reference values();
	Reference put(Reference, Reference);
	Reference get(Reference);
	Reference putIfAbsent(Reference, Reference);
	void putAll(Reference);
	Reference replace(Reference, Reference);
	Reference remove(Reference);
	Reference remove(Reference, Reference);
	bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_HASHMAP_H_ */
